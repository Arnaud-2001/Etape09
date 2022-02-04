#ifndef TIMING_H
#define TIMING_H

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Temps.h"
#include "TimingException.h"

using namespace std;

class Timing
{
    private:
        char* jour;
        Temps heure;
        Temps duree;
        int compT(const Timing& t);

    public:

        //CONSTRUCTEURS
        Timing();                                   //PAR DÉFAUT
        Timing(const char* j, Temps h, Temps d);    //INITIALISATION
        Timing(const Timing& t);                    //COPIE

        //DESTRUCTEUR
        ~Timing();

        //SETTERS/GETTERS
        void setJour(const char* j);
        void setHeure(Temps h);
        void setDuree(Temps d);

        const char* getJour() const;
        Temps       getDuree() const;
        Temps       getHeure() const;

        //SURCHARGE OPERATEURS
        int operator<(const Timing& t);
        int operator>(const Timing& t);
        int operator==(const Timing& t);

        //METHODES
        void    Affiche() const;
        int     NumDuJour(const Timing& t);
        void    Save(ofstream& fichier) const;
        void    Load(ifstream& fichier);

        //VARIABLES STATIQUES
        const static char *LUNDI, *MARDI, *MERCREDI, *JEUDI, *VENDREDI, *SAMEDI, *DIMANCHE;
};

#endif