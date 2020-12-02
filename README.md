# QTTree
[![Latest Release](https://img.shields.io/github/release/Epictigu/QtTree?label=Download)](https://github.com/Epictigu/QTTree/releases/)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

<dd>Das QTTree-Programm ist eine Möglichkeit binäre Bäume in einem Fenster mit C++ anzuzeigen.</dd>
<dd>Benutzt wird dafür ein Baum-Objekt welches bereits erarbeitet wurde.</dd>
<dd>Dieses ist ein Struct-Objekt, kann aber ohne Weiteres auf eine vollständige Objektorientierung umgeändert werden.</dd>

## Verwendung

<dd>Das Programm ist dafür geschrieben bei Bedarf in ein weiteres Programm eingebunden zu werden.</dd>
<dd>Um dies zu ermöglichen ist allerdings eine Integration von Qt in die verwendete IDE/Compiler nötig.</dd>
<dd>Benutzt werden kann sowohl der <a href="https://github.com/Epictigu/QTTree/releases">Source-Code</a> als auch die Repository selber.</dd>
<dd>Für eine Benutzung der Repository sollte natürlich ein entsprechendes Wissen über Git vorhanden sein.</dd>

### Integration

<dd>Für eine reibungslose Integration muss entweder die hauseigene IDE von Qt (<a href="www.qt.io/download-qt-installer">QtCreator</a>) oder eine gewünschte IDE mit vorhandenem Plugin genutzt werden. Beispiele dafür wären:</dd>

+ CodeBlocks (Benötigt Qt-Installation)
+ Eclipse ([CDT-Qt](https://wiki.eclipse.org/CDT/Archive/cdt-qt))
+ VisualStudio ([Qt Visual Studio Tools](https://marketplace.visualstudio.com/items?itemName=TheQtCompany.QtVisualStudioTools-19123))

<dd>Generell können auch andere Umgebungen für Qt benutzt werden, allerdings erfordern diese mehr Eigenarbeit um das ganze zum Laufen zu bringen.</dd>
<dd>Um einen Baum in einem Fenster zu öffnen kann direkt die Methode "display" in ShowKnot.h verwendet werden.</dd>

### Testlauf

<dd>Wer das Programm einfach nur ausführen möchte um den Ablauf zu testen kann auch direkt den <a href="https://github.com/Epictigu/QTTree/releases">Release-Download</a> nehmen.</dd>
<dd>Generell kann das Programm einfach ausgeführt werden, wobei ein zufälliger Baum mit bis zu 10 Knoten erstellt und angezeigt wird.</dd>
<dd>Wenn allerdings ein bestimmter Zufallsbaum erstellt werden soll, können dafür auch bestimmte Programamparameter übergeben werden (Über Verknüpfung oder Konsole).</dd>
<dd>Die Parameter können wie folgt aussehen: <i>"QTTree.exe &lt;Maximale Anzahl an Elementen&gt; &lt;Min. Knotenwert&gt; &lt;Max. Knotenwert&gt;"</i>.</dd>
<dd>Bei dem Aufruf können beliebig 0-3 Parameter benutzt werden. Es kann also beispielsweise nur die Anzahl an Elementen umgeändert werden indem nur der erste Parameter benutzt wird.</dd>

## Features

<dd>Generell ist das Ziel einen gegebenen Baum anzuzeigen.</dd>
<dd>Allerdings wurden zum Komfort weitere kleine Features eingebaut, damit der Baum aum eine vernünftige Weise dargestellt werden kann.</dd>
<dd>Das Fenster passt sich beim Starten direkt an den gegebenen Baum an, wobei das Limit natürlich die Größe des Bildschirms ist.</dd>
<dd>Sollte der Baum größer sein als das Fenster kann über ein Ziehen der Maus der Inhalt verschoben werden.</dd>
<dd>Die Größe anzupassen ist ebenfalls möglich über ein Drücken der Strg.-Taste zusammen mit dem Drehen des Mausrades.</dd>
<dd>Wenn gewünscht könnten einige Zeichendetails innerhalb des Pens und des Brushs in den dazugehörigen Klassen ebenfalls geändert werden.</dd>
