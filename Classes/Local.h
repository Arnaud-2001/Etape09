#ifndef LOCAL_H
#define LOCAL_H

#include "Planifiable.h"
#include <string.h>

class Local : public Planifiable
{
    friend ostream& operator<<(ostream& s, Local& p);

    private:
        char* nom;
        int compL(const Local& l);

    public:
        
        //CONSTRUCTEURS
        Local();                        //PAR DEFAUT
        Local(int i, const char* n);    //INITIALISATION
        Local(const Local& l);          //COPIE

        //DESTRUCTEUR
        ~Local();

        //SETTERS/GETTERS
        void setNom(const char* n);

        const char* getNom() const;

        //SURCHARGE OPERATEURS
        const Local&  operator=(const Local& l);
        int operator<(const Local& l);
        int operator>(const Local& l);
        int operator==(const Local& l);

        //METHODES
        const char* Txt();
        const char* Tuple();
};

#endif