#include "Timing.h"
#include "string.h"

//VARIABLES STATIQUES
const char* Timing::LUNDI     = "Lundi";
const char* Timing::MARDI     = "Mardi";
const char* Timing::MERCREDI  = "Mercredi";
const char* Timing::JEUDI     = "Jeudi";
const char* Timing::VENDREDI  = "Vendredi";
const char* Timing::SAMEDI    = "Samedi";
const char* Timing::DIMANCHE  = "Dimanche";

//CONSTRUCTEURS
Timing::Timing()                //PAR DÉFAUT
{
    #ifdef DEBUG
    cout << "---Timing : constructeur par défaut---" << endl;
    #endif

    jour = NULL;
}

Timing::Timing(const char* j, Temps h, Temps d) //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Timing : constructeur initialisation---" << endl;
    #endif

    jour = NULL;

    setHeure(h);
    setDuree(d);
    setJour(j);
}

Timing::Timing(const Timing& t)  //COPIE
{
    #ifdef DEBUG
    cout << "---Timing : constructeur de copie---" << endl;
    #endif

    jour = NULL;

    setHeure(t.getHeure());
    setDuree(t.getDuree());
    setJour(t.getJour());
}

//DESTRUCTEUR
Timing::~Timing()
{
    #ifdef DEBUG
    cout << "---Timing : destructeur---" << endl;
    #endif

    if(jour) delete jour;
}

//SETTERS/GETTERS
void Timing::setJour(const char* j)
{
    if(j == NULL) return;

    if(strcmp(j, LUNDI)                             != 0)
        if(strcmp(j, MARDI)                         != 0)
            if(strcmp(j, MERCREDI)                  != 0)
                if(strcmp(j, JEUDI)                 != 0)
                    if(strcmp(j, VENDREDI)          != 0)
                        if(strcmp(j, SAMEDI)        != 0)
                            if(strcmp(j, DIMANCHE)  != 0)
                                throw TimingException("Jour incorrect", 0); 

    if(jour) delete jour;
    jour = new char[strlen(j)+1];
    strcpy(jour,j);
}

void Timing::setHeure(Temps h)
{
    heure = h;
}

void Timing::setDuree(Temps d)
{
    duree = d;
}

const char* Timing::getJour() const
{
    return jour;
}

Temps Timing::getHeure() const
{
    return heure;
}

Temps Timing::getDuree() const
{
    return duree;
}

//SURCHARGE OPERATEURS
int Timing::operator<(const Timing& t)
{
    return compT(t)==-1;
}

int Timing::operator>(const Timing& t)
{
    return compT(t)==1;
}

int Timing::operator==(const Timing& t)
{
    return compT(t)==0;
}

int Timing::compT(const Timing& t)
{
    //ATTRIBUER VALEUR AUX JOUR POUR CHAQUE TIMING
    int jourVal1, jourVal2;

    jourVal1 = NumDuJour(*this);
    jourVal2 = NumDuJour(t);

    //COMPARAISONS
    if(jourVal1 < jourVal2) return -1;
    if(jourVal1 > jourVal2) return 1;
    //Meme jour
    if(getHeure() < t.getHeure()) return -1;
    if(getHeure() > t.getHeure()) return 1;
    //Meme heure
    if(getDuree() < t.getDuree()) return -1;
    if(getDuree() > t.getDuree()) return 1;
    //Meme duree
    return 0;
}

//METHODES
void Timing::Affiche() const
{
    cout << "Timing : Jour = ";

    if(jour)
    {
        cout << jour;
    }
    else
    {
        cout << "/";
    }

    cout << " // Heure = "; 
    heure.Affiche();
    cout << " // Durée = ";
    duree.Affiche();
    
}

int Timing::NumDuJour(const Timing& t)
{
    int jourVal = 0;

    if(strcmp(t.getJour(),LUNDI) == 0)
    {
        jourVal = 1;
        return jourVal;
    }    
    if(strcmp(t.getJour(),MARDI) == 0)
    {
        jourVal = 2;
        return jourVal;
    }    
    if(strcmp(t.getJour(),MERCREDI) == 0)
    {
        jourVal = 3;
        return jourVal;
    }
    if(strcmp(t.getJour(),JEUDI) == 0)
    {
        jourVal = 4;
        return jourVal;
    }
    if(strcmp(t.getJour(),VENDREDI) == 0)
    {
        jourVal = 5;
        return jourVal;
    }
    if(strcmp(t.getJour(),SAMEDI) == 0)
    {
        jourVal = 6;
        return jourVal;
    }
    if(strcmp(t.getJour(),DIMANCHE) == 0)
    {
        jourVal = 7;
        return jourVal;
    }

    return jourVal;
}

void Timing::Save(ofstream& fichier) const 
{
    if(!fichier.is_open())
    {
        cout << "ERREUR : Ouverture fichier impossible" << endl;
        exit(1);
    } 

    getHeure().Save(fichier);
    getDuree().Save(fichier);

    int longueurJour = strlen(getJour());
 
    fichier.write((char *)&longueurJour, sizeof(int));
    fichier.write(getJour(), longueurJour);
}

void Timing::Load(ifstream& fichier) 
{
    if(!fichier.is_open())
    {
        cout << "ERREUR : Ouverture fichier impossible" << endl;
        exit(1);
    } 

    Temps tmpH;
    Temps tmpD;
    char* tmpJ = NULL;
    int longueurJour = 0;

    tmpH.Load(fichier);
    tmpD.Load(fichier);

    setHeure(tmpH);
    setDuree(tmpD);

    fichier.read((char *)&longueurJour, sizeof(int));

    tmpJ = new char[longueurJour];
    fichier.read(tmpJ, longueurJour);
    
    setJour(tmpJ);
}