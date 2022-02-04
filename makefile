# Fichier : 		makefile
# Utilisateur : 	DE MARCO Quentin
# Groupe : 			2227
# Date modif. :		04-12-2021

.SILENT:
COMP=g++ -Wall #-DDEBUG
CLASSES=Classes/
QT=InterfaceQt/
OBJETS=$(CLASSES)Event.o $(CLASSES)Temps.o $(CLASSES)Timing.o $(CLASSES)Planifiable.o $(CLASSES)Professeur.o $(CLASSES)Groupe.o $(CLASSES)Local.o $(CLASSES)Exception.o $(CLASSES)TempsException.o $(CLASSES)TimingException.o $(CLASSES)Liste.o $(CLASSES)ListeTriee.o $(CLASSES)Iterateur.o $(CLASSES)Horaire.o $(CLASSES)$(QT)main.o $(CLASSES)$(QT)applichorairewindow.o $(CLASSES)$(QT)moc_applichorairewindow.o

all: ApplicHoraire

ApplicHoraire:	$(OBJETS)
	echo Creation de ApplicHoraire
	$(COMP) -Wl,-O1 -o ApplicHoraire $(OBJETS) /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread 					

$(CLASSES)$(QT)main.o:	$(CLASSES)$(QT)main.cpp
	echo Creation de main.o
	g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(CLASSES)$(QT)main.o $(CLASSES)$(QT)main.cpp

$(CLASSES)$(QT)applichorairewindow.o:	$(CLASSES)$(QT)applichorairewindow.cpp $(CLASSES)$(QT)applichorairewindow.h $(CLASSES)$(QT)ui_applichorairewindow.h
	echo Creation de applichorairewindow.o
	g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(CLASSES)$(QT)applichorairewindow.o $(CLASSES)$(QT)applichorairewindow.cpp

$(CLASSES)$(QT)moc_applichorairewindow.o:	$(CLASSES)$(QT)moc_applichorairewindow.cpp $(CLASSES)$(QT)applichorairewindow.h
	echo Creation de moc_applichorairewindow.o
	g++ -c -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o $(CLASSES)$(QT)moc_applichorairewindow.o $(CLASSES)$(QT)moc_applichorairewindow.cpp

$(CLASSES)Event.o: $(CLASSES)Event.cpp
	echo Creation de Event.o
	$(COMP) $(CLASSES)Event.cpp -c -o $(CLASSES)Event.o

$(CLASSES)Temps.o: $(CLASSES)Temps.cpp
	echo Creation de Temps.o
	$(COMP) $(CLASSES)Temps.cpp -c -o $(CLASSES)Temps.o

$(CLASSES)Timing.o: $(CLASSES)Timing.cpp
	echo Creation de Timing.o
	$(COMP) $(CLASSES)Timing.cpp -c -o $(CLASSES)Timing.o

$(CLASSES)Planifiable.o: $(CLASSES)Planifiable.cpp
	echo Creation de Planifiable.o
	$(COMP) $(CLASSES)Planifiable.cpp -c -o $(CLASSES)Planifiable.o

$(CLASSES)Professeur.o: $(CLASSES)Professeur.cpp
	echo Creation de Professeur.o
	$(COMP) $(CLASSES)Professeur.cpp -c -o $(CLASSES)Professeur.o

$(CLASSES)Groupe.o: $(CLASSES)Groupe.cpp
	echo Creation de Groupe.o
	$(COMP) $(CLASSES)Groupe.cpp -c -o $(CLASSES)Groupe.o

$(CLASSES)Local.o: $(CLASSES)Local.cpp
	echo Creation de Local.o
	$(COMP) $(CLASSES)Local.cpp -c -o $(CLASSES)Local.o

$(CLASSES)Exception.o: $(CLASSES)Exception.cpp
	echo Creation de Exception.o
	$(COMP) $(CLASSES)Exception.cpp -c -o $(CLASSES)Exception.o

$(CLASSES)TempsException.o: $(CLASSES)TempsException.cpp
	echo Creation de TempsException.o
	$(COMP) $(CLASSES)TempsException.cpp -c -o $(CLASSES)TempsException.o

$(CLASSES)TimingException.o: $(CLASSES)TimingException.cpp
	echo Creation de TimingException.o
	$(COMP) $(CLASSES)TimingException.cpp -c -o $(CLASSES)TimingException.o

$(CLASSES)Liste.o:	$(CLASSES)Liste.cpp
	echo Creation de Liste.o
	$(COMP) $(CLASSES)Liste.cpp -c -o $(CLASSES)Liste.o

$(CLASSES)ListeTriee.o:	$(CLASSES)ListeTriee.cpp
	echo Creation de ListeTriee.o
	$(COMP) $(CLASSES)ListeTriee.cpp -c -o $(CLASSES)ListeTriee.o

$(CLASSES)Iterateur.o:	$(CLASSES)Iterateur.cpp
	echo Creation de Iterateur.o
	$(COMP) $(CLASSES)Iterateur.cpp -c -o $(CLASSES)Iterateur.o

$(CLASSES)Horaire.o:	$(CLASSES)Horaire.cpp
	echo Creation de Horaire.o
	$(COMP) $(CLASSES)Horaire.cpp -c -o $(CLASSES)Horaire.o

clean:
	rm $(CLASSES)*.o
	rm $(CLASSES)$(QT)*.o
	rm ApplicHoraire