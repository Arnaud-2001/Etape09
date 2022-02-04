#include "Groupe.h"

//CONSTRUCTEURS
Groupe::Groupe() : Planifiable()                            //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---Groupe : constructeur par defaut---" << endl;
    #endif

    setNumero(0);
}

Groupe::Groupe(int i, int num) : Planifiable(i)             //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Groupe : constructeur d'initialisation---" << endl;
    #endif

    setNumero(num);
}

Groupe::Groupe(const Groupe& g) : Planifiable(g)            //COPIE
{
    #ifdef DEBUG
    cout << "---Groupe : constructeur de copie---" << endl;
    #endif

    setNumero(g.getNumero());
}

//DESTRUCTEUR
Groupe::~Groupe()
{
    #ifdef DEBUG
    cout << "---Groupe : destructeur---" << endl;
    #endif
}

//SETTERS/GETTERS
void Groupe::setNumero(int i)
{
    if(i > 0)
    {
        numero = i;
    }
    else
    {
        numero = 0;
    }
}

int Groupe::getNumero() const
{
    return numero;
}

//SURCHARGE OPERATEURS
const Groupe& Groupe::operator=(const Groupe& g)
{
    setId(g.id);
    setNumero(g.numero);

    return (*this);
}

ostream& operator<<(ostream& s, Groupe& g)
{
    s << g.getId();
    s << " ";
    s << g.getNumero();

    return s;
}

int Groupe::compG(const Groupe& g) 
{
    //Comparer numeros
    if(getNumero() < g.getNumero()) return -1;
    if(getNumero() > g.getNumero()) return 1;
    
    //Numeros egaux
    return 0;
}

int Groupe::operator<(const Groupe& g) 
{
    return compG(g)==-1;
}

int Groupe::operator>(const Groupe& g) 
{
    return compG(g)==1;
}

int Groupe::operator==(const Groupe& g) 
{
    return compG(g)==0;
}

//METHODES
const char* Groupe::Txt()
{
    if (txt)
        delete txt;
    if(getNumero())
    {
        txt = NULL;
        txt = new char[sizeof(getNumero())+2];
        sprintf(txt, "G%d", getNumero());
    }
    return txt;
}

const char* Groupe::Tuple()
{
    if (tuple)
        delete tuple;
    if(getNumero())
    {
        tuple = NULL;
        tuple = new char[sizeof(getId())+sizeof(getNumero())+3];
        sprintf(tuple, "%d;G%d", getId(), getNumero());
    }
    return tuple;
}