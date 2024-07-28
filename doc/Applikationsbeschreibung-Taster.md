<!-- DOC -->
## **Dokumentation**

<!-- DOCCONTENT
Eine vollständige Applikationsbeschreibung ist unter folgendem Link verfügbar: https://github.com/openknx/OFM-VirtualButton/blob/v1/doc/Applikationsbeschreibung-Taster.md
DOCCONTENT -->

Dies ist ein OpenKNX-Modul, um virtuelle Taster bereitzustellen. Diese können mit integrierten Binäreingängen (falls vorhanden) oder mit externen Tastern verwendet werden. Dies kann beispielsweise sinnvoll sein, wenn die Funktionen des vorhandenen Tasters nicht ausreichend sind. Voraussetzung für die Verwendung ist, dass der verwendete Taster oder Binäreingang bei einem Tastendruck ein EIN und beim Loslassen ein AUS senden kann.

Das Repository findet man unter: https://github.com/openknx/OFM-VirtualButton

#### **Modus**
- 1fach-Taster
- 2fach-Taster
- Mehrfach-Klick

#### **DPTs**
- DPT 1.001 Schalten
- DPT 2.001 Zwangsführung
- DPT 3.007 Dimmen
- DPT 3.008 Jalousie
- DPT 5.005 (0..255)
- DPT 5.001 (0..100%)
- DPT 7.001 (0..65535)
- DPT 18.001 Szene

#### **Funktionen**
- Sperrmöglichkeit
- Individuelle Reaktionszeiten
- Unterscheidung zwischen "Drücken" und "Loslassen"
- Zusätzlicher DPT1-Ausgang bei 1/2-fach-Tastern
- Zusätzliches "Extra-Lang" neben einfachem und langem Tastendruck
- Umschalter für DPT1, DPT2
- Dynamische Richtung für DPT3 (Dimmen/Rollladen)
- Spezielle Kommunikationsobjekte für Mehrfach-Klick und DPT1 (Alle 3 Mehrfach-Klicks haben ein eigenes KO)
- Klickzähler bei Mehrfach-Klick, um externe Logiken über den 3-fach Klick hinaus zu ermöglichen

## **Allgemein**

Auf dieser Seite findet man die Einstellungen, die übergreifend für alle Taster-Kanäle gelten.

### **Tastermodul**

Hier wird die Version des Tastermoduls ausgegeben, die in dieser Firmware verwendet wurde.

### **Verfügbare Kanäle**

Um die Applikation übersichtlicher zu gestalten, kann hier ausgewählt werden, wie viele Kanäle in der Applikation verfügbar und editierbar sind. Die Maximalanzahl der Kanäle hängt von der Firmware des Gerätes ab, dass dieses Modul verwendet.

Die ETS ist auch schneller in der Anzeige, wenn sie weniger (leere) Kanäle darstellen muss. Insofern macht es Sinn, nur so viele Kanäle anzuzeigen, wie man wirklich braucht.

### **Reaktionszeiten**

Für alle Funktionen, die aus mehreren Tastendrücken bestehen, können hier die Zeiten angegeben werden, die gewartete werden soll.

<!-- DOC -->
#### **Mehrfach-Klick**

Gibt die Wartezeit an, wie lange auf einen weiteren Tastendruck gewartet wird. Sobald die Zeit abgelaufen ist, wird der bis dahin gezählte Mehrfach-Klick ausgeführt.

<!-- DOC -->
#### **Langer Tastendruck**

Gibt an, ab wann der gehaltene Tastendruck als "Langer Tastendruck" gewertet wird. Sobald die Zeit erreicht wurde, wird ein passendes "Press"-Event ausgelöst. Sollte nun vor dem Ablauf der Reaktionszeit für "Extra langer Tastendruck" (falls aktiviert) losgelassen werden, so wird das dazugehörige "Release"-Event ausgelöst.

<!-- DOC -->
#### **Extra langer Tastendruck**

Gibt an, ab wann der gehaltene Tastendruck als "Extra langer Tastendruck" gewertet wird. Sobald die Zeit erreicht wurde, wird ein passendes "Press"-Event ausgelöst. Sobald nun losgelassen wird, wird das dazugehörige "Release"-Event ausgelöst.

## **Taster *n***

Da alle Taster gleichartig konfiguriert werden, wird hier nur die Konfiguration für einen Taster behandelt.

<!-- DOC -->
### **Beschreibung**

Der hier angegebene Name wird an verschiedenen Stellen verwendet, um diesen Kanal wiederzufinden.

* Seitenbeschreibung des Kanals
* Name vom Kommunikationsobjekt

Eine aussagekräftige Benennung erlaubt eine einfachere Orientierung innerhalb der Applikation, vor allem wenn man viele Kanäle nutzt.

<!-- DOC -->
### **Modus**

Der virtuelle Taster kann in verschiedenen Tastermodi betrieben werden.

#### **1fach-Taste** 

Dieser Modus wird in der Regel mit Toggle-Funktionen genutzt. Somit kann man mit nur einer Taste das Licht „Ein“ und „Aus“ schalten oder das Rollo „Hoch“ und „Runter“ fahren. Es kann aber auch genutzt werden, um mit einem weiteren Kanal einen „2fach-Taster“ abzubilden. Das kann z.B. in Kombination mit dem Mehrfach-Taster sinnvoll sein. Dabei könnte man den Mehrfach-Taster nutzen verschiedene Helligkeiten abzubilden und mit dem 1-fach-Taster nur das „Aus“.

#### **2fach-Taster** 

Der 2fach-Taster ist der Klassiker für normale "Ein/Aus" bzw "Hoch/Runter"-Taster.

#### **Mehrfach-Klick** 

In diesem Modus werden die Auslösungen des Taster innerhalb einer Zeitspanne gezählt. Dabei kann der Einfach-, Doppel- sowie der Dreifach-Klick direkt mit einem Event versehen werden. Weitere Events (wie der Vierfach- oder Fünffach-Klick) sind in Kombination mit einer Logikengine machbar.

<!-- DOC -->
### **Sperre**

Durch die Verwendung der Sperre kann der virtuelle Taster gesperrt werden.

<!-- DOC -->
### **Tastereingänge**

Um die Channels über die Tastereingänge zu triggern, müssen beim Drücken eine 1 und beim Loslassen eine 0 gesendet werden. Taster, die keine Unterscheidung zwischen diesen beiden Zuständen ermöglichen, sind nicht verwendbar.

Standardmäßig kommen die Events über ein externes KO. Manche verwendete Hardware hat bereits Binäreingänge bzw. Taster verbaut. In diesem Fall kann der Eingang auch ohne Umwege über den Bus zugewiesen werden. Beachte, dass diese internen Tastereingängen in der Regel konfigurationsabhängig sind. Es ist daher meistens nötig, im jeweiligen Modul (je nach Hardware) den Tastereingang erst zu aktivieren bzw. zu konfigurieren.

<!-- DOC -->
### **Datentyp**

Es muss ein Datentyp ausgewählt werden, mit dem der Taster seine Schaltaktionen sendet. Der Datentyp kann für den "Einfachen Tastendruck", den "Langen Tastendruck" und den "Extralangen Tastendruck" unterschiedlich sein.

<!-- DOC -->
### **Wert beim Drücken**

Der ausgewählte Wert wird beim Drücken sofort bzw. beim gedrückt halten (beim langem oder extra langen Tastendruck) nach Ablauf der eingestellten Reaktionszeit auf den Bus gesendet.

Dadurch werden prinzipbedingt auch alle aktiven Events (kurz, lang, extralang) unabhängig vom Loslassen ausgeführt. In der Regel wird daher beim "Einfacher Tastendruck" gar nicht mit diesem Event gearbeitet. Beim gedrücktem Taster sollte man auf dieses Event nur reagieren, wenn es das letzte Event ist.

Beispiel:
Möchte ich ein Gerät mit kurzem Tastendruck einschalten und mit langem Tastendruck ausschalten, so sollte folgende Konfiguration gewählt werden:

Beim "Einfacher Tastendruck" sollte mittels "Wert beim Loslassen" ein EIN geschickt werden.
Beim "Langer Tastendruck" sollte mittels "Wert beim Drücken" ein AUS geschickt werden.

In dieser Kombination ist sichergestellt, dass das EIN nur beim Loslassen und innerhalb der Reaktionszeit gesendet wird.
Das AUS hingegen wird sofort bei erreichen der eingestellten Reaktionszeit ausgelöst, so dass der Benutzer sieht das er loslassen kann.

<!-- DOC -->
### **Wert beim Loslassen**

Der ausgewählte Wert wird bei Loslassen gesendet. Vorherige Events werden dabei nicht ausgelöst. Habe ich also für "Einfacher Tastendruck" und "Langer Tastendruck" ein Wert eingestellt und halte die Taste entsprechend lange gedrückt und lasse dann los, so wird nur der Wert von "Langer Tastendruck" gesendet. Möchte man das beide Events ausgelöst werden, so muss man die beiden Funktionen auf zwei virtuelle Taster aufteilen.

<!-- DOC -->
### **Zusatzausgang**

Mit dem Zusatzausgang besteht die Möglichkeit, ein zusätzliches Telegramm zu senden. Dieses Telegramm ist auf das DPT1 beschränkt und wird beim Loslassen gesendet.

<!-- DOC -->
### **Dynamische Richtung**

Durch die Erweiterung "Dynamische Richtung" wird es möglich, basierend auf dem %-Status, dynamisch die nächste Dimm-/Fahrtrichtung festzulegen. Verzögerung und Schwellwerte können dabei individuell festgelegt werden. Diese Funktion steht nur bei DPT3.00x zur Verfügung.

Hier ein Beispiel: Ich dimme von 100 % auf 90 % herunter. Die nächste Richtung wäre jetzt wieder hochdimmen. Ein späterer Benutzer möchte jedoch aufgrund der 90 % herunterdimmen, würde aber stattdessen hochdimmen. Mit dieser Erweiterung wird der Status nach Ablauf der Verzögerung und anhand der Schwellwerte neu gesetzt.

<!-- DOC HelpContext="DimVerzoegerung" -->
#### **Verzögerung**

Legt fest, wie lange die Statusauswertung nach einem Dimm-/Fahrvorgang verzögert wird. Erst nach Ablauf dieser Verzögerung wird die Dimm-/Fahrtrichtung anhand des aktuellen %-Status neu bestimmt. Der Mindestwert und auch die Empfehlung beträgt 5 Sekunden, sodass die Bedienung sicher abgeschlossen ist und der finale Aktorstatus eingetroffen ist. Sobald die Verzögerung abgelaufen ist, werden eintreffende Status-Updates direkt ausgewertet.


<!-- DOC HelpContext="DimSchwellwerte" -->
#### **Schwellwerte**

Der obere Schwellwert legt die Dimm-/Fahrtrichtung nach unten fest, während der untere Schwellwert die Richtung nach oben bestimmt. Greift keiner der Schwellwerte, findet keine Anpassung statt. Überlappen sich die Schwellwerte, hat der obere Schwellwert Vorrang.

Es ist in den meisten Fällen sinnvoll, beide Schwellwerte gleich zu halten. Dies gibt in der Regel das gewünschte Verhalten wieder. Sind die Werte weiter auseinander, bedeutet das, dass der Wertebereich zwischen beiden Schwellwerten keine Anpassung auslöst. Dadurch verhält es sich so, als wäre die Funktion "Dynamische Richtung" ausgeschaltet.

Ein Verhindern, dass die Werte sich nicht überschneiden, ist in der ETS nicht möglich. Daher ist es so geregelt, dass der obere Schwellwert Vorrang vor dem unteren Schwellwert hat.

