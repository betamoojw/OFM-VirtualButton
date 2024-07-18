### Dokumentation

Eine vollständige Applikationsbeschreibung ist unter folgendem Link verfügbar: https://github.com/openknx/OFM-VirtualButton/blob/v1/doc/Applikationsbeschreibung-Taster.md

Dies ist ein OpenKNX-Modul, um virtuelle Taster bereitzustellen. Diese können mit integrierten Binäreingängen (falls vorhanden) kombiniert oder mit externen Tastern verwendet werden, deren Funktionen nicht ausreichend sind. Voraussetzung für die Verwendung ist, dass der verwendete Taster oder Binäreingang bei einem Tastendruck ein EIN und beim Loslassen ein AUS senden kann.

Das Repository findet man unter: https://github.com/openknx/OFM-VirtualButton

#### Modus
- 1fach-Taster
- 2fach-Taster
- Mehrfach-Klick

#### DPTs
- DPT 1.001 Schalten
- DPT 2.001 Zwangsführung
- DPT 3.007 Dimmen
- DPT 3.008 Jalousie
- DPT 5.005 (0..255)
- DPT 5.001 (0..100%)
- DPT 7.001 (0..65535)
- DPT 18.001 Szene

#### Funktionen
- Sperrmöglichkeit
- Individuelle Reaktionszeiten
- Unterscheidung zwischen "Drücken" und "Loslassen"
- Zusätzlicher DPT1-Ausgang bei 1/2-fach-Tastern
- Zusätzliches "Extra-Lang" neben einfachem und langem Tastendruck
- Umschalter für DPT1, DPT2
- Dynamische Richtung für DPT3 (Dimmen/Rollladen)
- Spezielle Kommunikationsobjekte für Mehrfach-Klick und DPT1 (Alle 3 Mehrfach-Klicks haben ein eigenes KO)
- Klickzähler bei Mehrfach-Klick, um externe Logiken über den 3-fach Klick hinaus zu ermöglichen

