#include "Professeur.h"

//CONSTRUCTEURS
Professeur::Professeur() : Planifiable()                                        //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---Professeur : constructeur par defaut---" << endl;
    #endif

    nom     = NULL;
    prenom  = NULL;
}

Professeur::Professeur(int i, const char* n, const char* p) : Planifiable(i)    //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Professeur : constructeur d'initialisation---" << endl;
    #endif

    nom     = NULL;
    prenom  = NULL;

    setNom(n);
    setPrenom(p);
}

Professeur::Professeur(const Professeur& p) : Planifiable(p)            //COPIE
{
    #ifdef DEBUG
    cout << "---Professeur : constructeur de copie---" << endl;
    #endif

    nom     = NULL;
    prenom  = NULL;

    setNom(p.getNom());
    setPrenom(p.getPrenom());
}

//DESTRUCTEUR
Professeur::~Professeur()
{
    #ifdef DEBUG
    cout << "---Professeur : destructeur---" << endl;
    #endif

    if(nom) delete nom;
    if(prenom) delete prenom;
}

//SETTERS/GETTERS
void Professeur::setNom(const char* n)
{
    if(n == NULL) return;

    if(nom) delete nom;
    nom = new char[strlen(n)+1];
    strcpy(nom,n);
}

void Professeur::setPrenom(const char* p)
{
    if(p == NULL) return;

    if(prenom) delete prenom;
    prenom = new char[strlen(p)+1];
    strcpy(prenom,p);
}

const char* Professeur::getNom() const
{
    return nom;
}

const char* Professeur::getPrenom() const
{
    return prenom;
}

//SURCHARGE OPERATEURS
const Professeur& Professeur::operator=(const Professeur& p)
{
    setId(p.id);
    setNom(p.nom);
    setPrenom(p.prenom);

    return (*this);
}

int Professeur::operator<(const Professeur& p) 
{
    return compP(p)==-1;
}

int Professeur::operator>(const Professeur& p) 
{
    return compP(p)==1;
}

int Professeur::operator==(const Professeur& p) 
{
    return compP(p)==0;
}

int Professeur::compP(const Professeur& p)
{
    //Comparaison des noms de famille
    const char *nom1 = this->getNom(), *nom2 = p.getNom();

    if((strcmp(nom1, nom2)) < 0)
        return -1;
    else
    {
        if((strcmp(nom1, nom2)) > 0)
            return 1;
    }

    //Noms identiques, on passe donc aux prénoms
    const char *prenom1 = this->getPrenom(), *prenom2 = p.getPrenom();

    if((strcmp(prenom1, prenom2)) < 0)
        return -1;
    else
    {
        if((strcmp(prenom1, prenom2)) > 0)
            return 1;
    }

    return 0;   //Noms et prénoms identiques
}

ostream& operator<<(ostream& s, const Professeur& p)
{
    Professeur tmp(p);

    s << tmp.getId();
    s << " ";

    if(tmp.getNom() == NULL)
        s << "/";
    else
        s << tmp.getNom();
    
    s << " ";
    
    if(tmp.getPrenom() == NULL)
        s << "/";
    else
        s << tmp.getPrenom();

    return s;
}

//METHODES
const char* Professeur::Txt()
{
    if (txt)
        delete txt;
    if(getNom()&& getPrenom())
    {
        txt = NULL;
        txt = new char[sizeof(getNom())+sizeof(getPrenom())+2];
        sprintf(txt,"%s %s", getNom(), getPrenom());
    }

    return txt;
}

const char* Professeur::Tuple()
{
    if (tuple)
        delete tuple;
    if(getNom() && getPrenom())
    {
        tuple = NULL;
        tuple = new char[sizeof(getId())+sizeof(getNom())+sizeof(getPrenom())+3];
        sprintf(tuple, "%d;%s;%s", getId(), getNom(), getPrenom());
    }
    return tuple;
}
