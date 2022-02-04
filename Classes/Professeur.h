#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Planifiable.h"

using namespace std;

class Professeur : public Planifiable
{
    friend ostream& operator<<(ostream& s, const Professeur& p);

    private:
        char* nom;
        char* prenom;
        int compP(const Professeur& p);

    public:

        //CONSTRUCTEURS
        Professeur();                                       //PAR DEFAUT
        Professeur(int i, const char* n, const char* p);    //INITIALISATION
        Professeur(const Professeur& p);                    //COPIE

        //DESTRUCTEUR
        ~Professeur();

        //SETTERS/GETTERS
        void setNom(const char* n);
        void setPrenom(const char* p);

        const char* getNom() const;
        const char* getPrenom() const;

        //SURCHARGE OPERATEURS
        const Professeur&  operator=(const Professeur& p);
        int operator<(const Professeur& p);
        int operator>(const Professeur& p);
        int operator==(const Professeur& p);

        //METHODES
        const char* Txt();
        const char* Tuple();
};

#endif