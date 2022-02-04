#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "Liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template<class T>
class Iterateur
{
    private:
        Liste<T>&   liste;
        Cellule<T>  *pCurrent;

    public:

        //CONSTRUCTEUR
        Iterateur (Liste<T>& l);    //INITIALISATION
        ~Iterateur();

        //SET/GET
        void setListe(const Liste<T>& l);
        void setCurrent(Cellule<T> *pC);

        Liste<T>&   getListe() const;
        Cellule<T>  *getCurrent() const;

        //METHODES
        bool        end();
        void        reset();
        operator    T() const;

        //SURCHARGE DES OPERATEURS
        Iterateur<T> operator++();
        Iterateur<T> operator++(int); 

};
#endif