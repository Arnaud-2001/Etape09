#ifndef TEMPS_H
#define TEMPS_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "TempsException.h"

using namespace std;

class Temps
{
    
    friend const Temps   operator+(const Temps& t1, int i);
    friend const Temps   operator+(int i, const Temps& t1);
    friend const Temps   operator-(const Temps& t1, int i);
    friend const Temps   operator-(int i, const Temps& t1);
    
    friend ostream& operator<<(ostream& s, const Temps& t);
    friend istream& operator>>(istream& s, Temps& t);

    private:
        int heure;
        int minute;
        int compT(const Temps& t);

    public:

        //CONSTRUCTEURS
        Temps();                //PAR DÉFAUT
        Temps(int h, int m);    //INITIALISATION
        Temps(int m);           //INITIALISATION
        Temps(const Temps& t);  //COPIE

        //DESTRUCTEUR
        ~Temps();

        //SETTERS/GETTERS
        void setHeure(int h);
        void setMinute(int m);

        int getHeure() const;
        int getMinute() const;

        //SURCHARGE OPERATEURS
        const Temps&  operator=(const Temps& t);
        const Temps   operator+(int i);
        const Temps   operator+(const Temps& t);
        const Temps   operator-(int i);
        const Temps   operator-(const Temps& t);

        int operator<(const Temps& t);
        int operator>(const Temps& t);
        int operator==(const Temps& t);

        Temps operator++();
        Temps operator++(int);
        Temps operator--();
        Temps operator--(int);

        //METHODES
        void Affiche() const;
        void Save(ofstream& fichier) const;
        void Load(ifstream& fichier);

};

#endif