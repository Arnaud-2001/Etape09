#include "Local.h"

//CONSTRUCTEURS
Local::Local() : Planifiable()                                        //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---Local : constructeur par defaut---" << endl;
    #endif

    nom = NULL;
}

Local::Local(int i, const char* n) : Planifiable(i)    //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Local : constructeur d'initialisation---" << endl;
    #endif

    nom = NULL;

    setNom(n);
}

Local::Local(const Local& l) : Planifiable(l)  //COPIE
{
    #ifdef DEBUG
    cout << "---Local : constructeur de copie---" << endl;
    #endif

    nom = NULL;

    setNom(l.getNom());
}

//DESTRUCTEUR
Local::~Local()
{
    #ifdef DEBUG
    cout << "---Local : destructeur---" << endl;
    #endif

    if(nom) delete nom;
}

//SETTERS/GETTERS
void Local::setNom(const char* n)
{
    if(n == NULL) return;

    if(nom) delete nom;
    nom = new char[strlen(n)+1];
    strcpy(nom,n);
}

const char* Local::getNom() const
{
    return nom;
}

//SURCHARGE OPERATEURS
const Local& Local::operator=(const Local& l)
{
    setId(l.id);
    setNom(l.nom);

    return (*this);
}

int Local::compL(const Local& l) 
{
    //Comparaison des noms de locaux
    const char *nom1 = this->getNom(), *nom2 = l.getNom();

    if((strcmp(nom1, nom2)) < 0)
        return -1;
    else
    {
        if((strcmp(nom1, nom2)) > 0)
            return 1;
    }

    return 0;   //Noms identiques
}

int Local::operator<(const Local& l) 
{
    return compL(l)==-1;
}

int Local::operator>(const Local& l) 
{
    return compL(l)==1;
}

int Local::operator==(const Local& l) 
{
    return compL(l)==0;
}

ostream& operator<<(ostream& s, Local& l)
{
    s << l.getId();
    s << " ";
    
    if(l.getNom() == NULL)
        s << "/";
    else
        s << l.getNom();

    return s;
}

//METHODES
const char* Local::Txt()
{
    if (txt)
        delete txt;
    if(getNom())
    {
        txt = NULL;
        txt = new char[sizeof(getNom())+1];
        sprintf(txt,"%s",getNom());
    }
    return txt;
}

const char* Local::Tuple()
{
    if (tuple)
        delete tuple;
    if(getNom())
    {
        tuple = NULL;
        tuple = new char[sizeof(getId())+sizeof(getNom())+2];
        sprintf(tuple,"%d;%s",getId(),getNom());
    }
    return tuple;
}