#ifndef LISTETRIEE_H
#define LISTETRIEE_H

#include "Liste.h"

using namespace std;

template <class T>
class ListeTriee : public Liste<T>
{
    protected:

    public:

        //CONSTRUCTEURS
        ListeTriee();                           //PAR DEFAUT
        ListeTriee(const ListeTriee<T>& l);     //DE COPIE

        //DESTRUCTEUR
        ~ListeTriee();

        //SETTERS/GETTERS


        //SURCHARGE OPERATEURS


        //METHODES
        void    insere(const T& val);
};

#endif