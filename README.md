# Modern Cmake

Dieses Repository beinhaltet verschiedene (erfolgreiche) Versuche eine statische Library, welche wiederum von weiteren lokal erzeugten Libraries abhängig ist, zu exportieren und dementsprechend weiteren externen Projekten zugänglich zu machen.

Die Hauptaufgabe bei diesem Versuch liegt in der Verwendung von CMake und im speziellen einem modern CMake Ansatz der im Allgemeinen eine Kapselung von Properties an Targets direkt liefert.

* Jedes Target ist für sich selbst verantwortlich
* Jedes Target liefert alle für sich relevanten Sachen mit

Beim Programmieren dieses Versuchs ist mir aufgefallen, dass diese beiden (von mir geschriebenen) Anforderungen manchmal nicht wirklich eingehalten werden.

## Ordnerstruktur

Die zu exportierende Library _basicLib_ ist im Ordner _lib_ beinhaltet. Diese Library ist wiederum abhängig von den Library _privateLib_ und _publicLib_.

Zur einfachen Überprüfung der Library ist eine zusätzliches main-Projekt erstellt worden.

## Git-Aufbau

Jeder einzelner Git-Branch stellt eine eigene Idee und Umsetzung dar. Aus diesem Grund ist ein allgemeine _master_-Zweig vorhanden.

### status_quo

Das Projekt baut und die relevante Library und ihre zusätzlichen Header werden installiert.


### importlibrary

* Baut auf status_quo auf
* Zusätzlich im src-Ordner noch der Ordner importedTarget enthalten, der die installierte Library als eigenständiges und externes Projekt versucht anzuziehen
* abhängige Libraries müssen auch installiert werden
* installierte Library wird mittels _add_libray(basicLib STATIC IMPORTED)_ dem Projekt bekannt gemacht
* Sehr hoher Eigenaufwand nötig (vgl. der zugehörigen CMakeLists.txt)


### installinclude

* Verwendung von _install(... EXPORT ...)_
* Erstellt somit eigenständig eine Datei, die die notwendigen Informationen für die Library, um diese zu importieren
* installierte Library wird mittels _include(...)_ dem Projekt hinzugefügt
* Library hat auch die zugehörigen includes in sich vereinigt
* alle zugehörigen Libraries müssen mitinstalliert werden


### findpackage (ist momentan auch als master definiert)

* kleiner Hack, da die exportierte Datei der Namenskonvention für ein _find_package()_ entspricht
* Nicht unbedingt der richtige Weg, aber in diesem simplen Fall zielführend
* installierte Library wird mittels _find_package(...)_ dem Projekt hinzugefügt
* Library hat auch die zugehörigen includes in sich vereinigt
* alle zugehörigen Libraries müssen mitinstalliert werden

### objectLibrary

* die zugehörigen Libraries ( _privateLib_ und _publicLib_) werden als _OBJECT_ Libraries beschrieben
* Diese so erstellten Libs können dann aber nicht einfach über _target_link_libraries(...)_ der _basicLib_ hinzugefügt werden. (Siehe lib/CMakeLists.txt)
* Vorteil: Die zugehörigen Libraries müssen nicht mit installiert werden
* Hier wird die exportierte Library über _include_ dem neuen Projekt zugänglich gemacht. Kann aber auch schnell und einfach mit der Variante in findPackage angepasst werden


## Nice to know:

 * [Creating Packages on CMake](https://cmake.org/cmake/help/v3.8/manual/cmake-packages.7.html#creating-packages) - Nützliche Information und Dokumentation
 * [Youtube Talk](https://www.youtube.com/watch?v=bsXLMQ6WgIk) - Cpp Now Talk von Daniel Pfeiffer über _Modern CMake_. Krasser Scheiß an manchen Stellen

