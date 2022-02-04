#ifndef GROUPE_H
#define GROUPE_H

#include "Planifiable.h"

class Groupe : public Planifiable
{
    friend ostream& operator<<(ostream& s, Groupe& p);

    private:
        int numero;

    public:

        //CONSTRUCTEURS
        Groupe();                   //PAR DEFAUT
        Groupe(int i, int num);     //INITIALISATION
        Groupe(const Groupe& g);    //COPIE
        int compG(const Groupe& g);

        //DESTRUCTEUR
        ~Groupe();

        //SETTERS/GETTERS
        void    setNumero(int i);

        int     getNumero() const;

        //SURCHARGE OPERATEURS
        const Groupe&  operator=(const Groupe& p);
        int operator<(const Groupe& g);
        int operator>(const Groupe& g);
        int operator==(const Groupe& g);

        //METHODES
        const char* Txt();
        const char* Tuple();

        
};

#endif