#pragma once
#include "knx.h"
#include "Helper.h"
#include "KnxHelper.h"
#include "knxprod.h"
#include "hardware.h"
#include "OpenKNX.h"

#define BTN_MaxMuliClicks 3
#define BTN_DPT1 1
#define BTN_DPT2 2
#define BTN_DPT5 4
#define BTN_DPT5001 5
#define BTN_DPT18 6
#define BTN_DPT3007 7
#define BTN_DPT3008 8
#define BTN_DPT7 3

struct sMultiClickParams
{
  bool active = false;
  uint16_t output;
};

struct sVirtualButtonParams
{
  bool outputShortPressActive = false;
  bool outputShortReleaseActive = false;
  uint16_t outputShortPress = 0;
  uint16_t outputShortRelease = 0;

  bool outputLongPressActive = false;
  bool outputLongReleaseActive = false;
  uint16_t outputLongPress = 0;
  uint16_t outputLongRelease = 0;

  bool outputExtraLongPressActive = false;
  bool outputExtraLongReleaseActive = false;
  uint16_t outputExtraLongPress = 0;
  uint16_t outputExtraLongRelease = 0;

  uint16_t inputKo = 0;
  uint16_t output2Short = 0;
  uint16_t output2Long = 0;
  uint16_t output2ExtraLong = 0;
};

struct sVirtualButtonGlobalParams
{
  uint8_t mode = 0;
  uint8_t lock = 0;
  bool multiClickCount = false;

  uint8_t outputShortDpt = 0;
  uint8_t outputLongDpt = 0;
  uint8_t outputExtraLongDpt = 0;
  uint8_t outputMultiClickDpt = 0;

  uint16_t reactionTimeMultiClick = 0;
  uint16_t reactionTimeLong = 0;
  uint16_t reactionTimeExtraLong = 0;
  uint8_t dynamicStatusThreshold = 0;
  uint32_t dynamicStatusFallback = 0;
};

struct sVirtualButtonState
{
  bool press = false;
  bool pressLong = false;
  bool pressExtraLong = false;
  uint32_t pressStart = 0;
  uint32_t multiClickTimer = 0;
  int8_t multiClicks = 0;
};

class VirtualButton : public OpenKNX::Channel
{

private:
  void processInputKoInput(GroupObject &iKo, bool iButton);
  void processInputKoLock(GroupObject &iKo);
  void processPress(bool iButton);
  void processRelease(bool iButton);
  void processPressAndHold(bool iButton);
  void processMultiClick();
  void eventMultiClick(uint8_t iClicks);
  void eventShortPress(bool iButton);
  void eventLongPress(bool iButton);
  void eventExtraLongPress(bool iButton);
  void eventShortRelease(bool iButton);
  void eventLongRelease(bool iButton);
  void eventExtraLongRelease(bool iButton);
  void writeOutput(uint8_t iOutputDPT, uint16_t iOutputKo, uint16_t iOutputValue, bool &oStatus);
  void processInputKoStatus(GroupObject &iKo, uint8_t iStatusNumber, uint8_t iDpt, bool &oStatus);
  void processDynamicStatusTimer();
  void evaluateDynamicStatus();

  uint8_t mLock = 0;
  bool mStatusShort = false;
  bool mStatusLong = false;
  bool mStatusExtraLong = false;
  u_int32_t mDynamicStatusTimer = 0;

  sVirtualButtonState mButtonState[2] = {
      sVirtualButtonState(),
      sVirtualButtonState()};
  sVirtualButtonParams mButtonParams[2] = {
      sVirtualButtonParams(),
      sVirtualButtonParams()};
  sVirtualButtonGlobalParams mParams;
  sMultiClickParams mMultiClickParams[3];

public:
  VirtualButton(uint8_t iIndex);
  ~VirtualButton();

  void setup();
  void loop();
  void processInputKo(GroupObject &iKo);
  const char* name() override;
};