#ifndef EVENT_H
#define EVENT_H

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Timing.h"
#include "TimingException.h"

using namespace std;

class Event
{
    private:
        int     code;
        char*   intitule;
        Timing* timing;
        
    public:

        //CONSTRUCTEURS
        Event();                                  //PAR DEFAUT
        Event(int c, const char* i, Timing& t);   //INITIALISATION AVEC TIMING
        Event(int c, const char* i);              //INITIALISATION SANS TIMING
        Event(const Event& e);                    //COPIE

        //DESTRUCTEUR
        ~Event();

        //SETTERS/GETTERS
        void setCode(int c);
        void setIntitule(const char* i); //const afin que la méthode ne puisse pas modifier la valeur de cette variable
        void setTiming(const Timing& t);

        int             getCode() const;     //const afin de ne pas pouvoir modifier la valeur des variables membres
        const char*     getIntitule() const; //const afin que la valeur retournée ne puisse pas être directement modifiée et de ne pas pouvoir modifier la valeur des variables membres
        Timing          getTiming() const;

        //METHODES
        void    Affiche() const;
        void    Save(ofstream& fichier) const;
        void    Load(ifstream& fichier);

        //VARIABLES STATIQUES
        static int codeCourant;

};

#endif