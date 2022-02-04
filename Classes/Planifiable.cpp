#include "Planifiable.h"

//VARIABLE STATIQUE
int Planifiable::idCourant = 0;

//CONSTRUCTEURS
Planifiable::Planifiable()                       //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---Planifiable : constructeur par defaut---" << endl;
    #endif

    txt     = NULL;
    tuple   = NULL;

    idCourant++;
    setId(idCourant);
    
}

Planifiable::Planifiable(int i)                  //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Planifiable : constructeur d'initialisation---" << endl;
    #endif

    txt     = NULL;
    tuple   = NULL;

    idCourant++;
    setId(idCourant);
    
}

Planifiable::Planifiable(const Planifiable& p)   //COPIE
{
    #ifdef DEBUG
    cout << "---Planifiable : constructeur de copie---" << endl;
    #endif

    txt     = NULL;
    tuple   = NULL;

    setId(p.getId());
}

//DESTRUCTEUR
Planifiable::~Planifiable()
{
    #ifdef DEBUG
    cout << "---Planifiable : destructeur---" << endl;
    #endif

    if(txt)
        delete txt;

    if(tuple)
        delete tuple;

}

//SETTERS/GETTERS
void Planifiable::setId(int i)
{
    if (i > 0)
        id = i;
    else
        id = 0;
}

int  Planifiable::getId() const
{
    return id;
}
/*
//SURCHARGE DES OPERATEURS
const Planifiable& Planifiable::operator=(const Planifiable& p)
{
    setId(p.getId());

    return (*this);
}

ostream& operator<<(ostream& s, const Planifiable& p)
{
    s << p.getId();

    return s;
}
*/
//METHODES