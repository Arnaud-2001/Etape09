#ifndef PLANIFIABLE_H
#define PLANIFIABLE_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Planifiable
{

    protected:
        int     id;
        char*   txt;
        char*   tuple;

    public:

        //CONSTRUCTEURS
        Planifiable();                      //PAR DEFAUT
        Planifiable(int i);                 //INITIALISATION
        Planifiable(const Planifiable& p);  //COPIE

        //DESTRUCTEUR
        virtual ~Planifiable();

        //SETTERS/GETTERS
        void setId(int i);

        int  getId() const;

        //METHODES
        virtual const char* Txt() = 0;
        virtual const char* Tuple() = 0;

        //VARIABLE STATIQUE
        static int idCourant;
};

#endif