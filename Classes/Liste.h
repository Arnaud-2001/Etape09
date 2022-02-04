#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

template <class T> 
struct Cellule
{
    T valeur;                                                   //Valeur de la cellule
    Cellule<T> *suivant;                                        //Pointeur vers la cellule suivante
    Cellule<T>(T n, Cellule<T> *s) : valeur(n), suivant(s) {};  //Constructeur d'initialisation de la Cellule
};

template <class T> class Iterateur; //IMPORTANT : Déclaration de la classe amie Iterateur

template <class T> 
class Liste
{
    protected:
        Cellule<T> *pTete;

    public:

        //CONSTRUCTEURS
        Liste();                    //PAR DEFAUT
        Liste(const Liste<T>& l);   //COPIE

        //DESTRUCTEUR
        ~Liste();

        //SET/GET
        void setTete(Cellule<T> *t);

        Cellule<T> *getTete() const;

        //SURCHARGE OPERATEURS
        Liste<T>& operator=(const Liste& l);

        //METHODES
        bool    estVide() const;
        int     getNombreElements() const;
        void    Affiche() const;
        void    insere(const T& val);
        T       retire(int ind); 

        //RELATIONS AMICALES
        friend class Iterateur<T>;     
};

#endif