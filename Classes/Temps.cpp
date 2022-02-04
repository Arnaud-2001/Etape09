#include "Temps.h"

//CONSTRUCTEURS
Temps::Temps()                //PAR DÉFAUT
{
    #ifdef DEBUG
    cout << "---Temps : constructeur par défaut---" << endl;
    #endif
    setHeure(0);
    setMinute(0);
}

Temps::Temps(int h, int m)    //INITIALISATION HEURE + MINUTE
{
    #ifdef DEBUG
    cout << "---Temps : constructeur initialisation---" << endl;
    #endif

    setHeure(h);
    setMinute(m);
}

Temps::Temps(int m)           //INITIALISATION MINUTE
{
    #ifdef DEBUG
    cout << "---Temps : constructeur initialisation---" << endl;
    #endif

    if(m >= 60)
    {
        setHeure((m/60));
        setMinute((m%60));
    }
    else
    {
        setHeure(0);
        setMinute(m);
    }
}

Temps::Temps(const Temps& t)  //COPIE
{
    #ifdef DEBUG
    cout << "---Temps : constructeur de copie---" << endl;
    #endif

    setHeure(t.getHeure());
    setMinute(t.getMinute());
}

//DESTRUCTEUR
Temps::~Temps()
{
    #ifdef DEBUG
    cout << "---Temps : destructeur---" << endl;
    #endif
}

//SETTERS/GETTERS
void Temps::setHeure(int h)
{
    if(h >= 0 && h <= 23)
    {
        heure = h;
    }
    else
    {
        throw TempsException("Heure invalide", 0);
    }
}

void Temps::setMinute(int m)
{
    if(m >= 0 && m <= 59)
    {
        minute = m;
    }
    else
    {
        throw TempsException("Minute invalide", 1);
    }
}

int Temps::getHeure() const
{
    return heure;
}

int Temps::getMinute() const
{
    return minute;
}

//SURCHARGE OPERATEURS
const Temps& Temps::operator=(const Temps& t)
{
    setHeure(t.getHeure());
    setMinute(t.getMinute());

    return (*this);
}

const Temps Temps::operator+(int i)
{
    Temps newTemps(*this);

    int minutes = newTemps.getMinute() + i;

    if(minutes > 59)
    {
        int heures = newTemps.getHeure() + minutes/60;
        minutes = minutes%60;

        if(heures >= 24)
        {
            throw TempsException("Addition qui depasse", 2);
            return newTemps;
        }

        newTemps.setHeure(heures);
    }

    newTemps.setMinute(minutes);

    return newTemps;
}

const Temps Temps::operator+(const Temps& t)
{
    Temps newTemps(*this);

    int minutes = newTemps.getMinute() + t.getMinute();
    int heures = newTemps.getHeure() + t.getHeure();

    if(minutes > 59)
    {
        heures = heures + minutes/60;
        minutes = minutes%60;


        if(heures >= 24)
        {
            throw TempsException("Addition qui depasse", 2);
            return newTemps;
        }

    }

    newTemps.setHeure(heures);
    newTemps.setMinute(minutes);

/*
    int minutes = t.getHeure()*60 + t.getMinute();

    newTemps = newTemps + minutes;
*/
    return newTemps;
}

const Temps operator+(const Temps& t1, int i)
{
    Temps newTemps(t1);

    int minutes = newTemps.getMinute() + i;

    if(minutes > 59)
    {
        int heures = newTemps.getHeure() + minutes/60;
        minutes = minutes%60;

        if(heures >= 24)
        {
            throw TempsException("Addition qui depasse", 2);
            return newTemps;
        }

        newTemps.setHeure(heures);
    }

    newTemps.setMinute(minutes);

/*
    newTemps = newTemps + i;
*/
    return newTemps;
}

const Temps operator+(int i, const Temps& t1)
{
    Temps newTemps(t1);

    return newTemps + i;
}

const Temps Temps::operator-(int i)
{
    Temps newTemps(*this);

    int minutes = newTemps.getMinute() - i;
    int heures = newTemps.getHeure();

    while(minutes < 0)
    {
        minutes = minutes + 60;
        heures = heures - 1;
    }

    if(heures < 0)
    {
        throw TempsException("Soustraction qui depasse", 2);
        return newTemps;
    }

    newTemps.setMinute(minutes);
    newTemps.setHeure(heures);

    return newTemps;
}

const Temps Temps::operator-(const Temps& t)
{
    Temps newTemps(*this);

    int minutes = newTemps.getMinute() - t.getMinute();
    int heures = newTemps.getHeure() - t.getHeure();

    while(minutes < 0)
    {
            minutes = minutes + 60;
            heures = heures - 1;
    }

    if(heures < 0)
    {
        throw TempsException("Soustraction qui depasse", 2);
        return newTemps;
    }

    newTemps.setHeure(heures);
    newTemps.setMinute(minutes);

    return newTemps;
}

const Temps operator-(const Temps& t1, int i)
{
    Temps newTemps(t1);

    int minutes = newTemps.getMinute() - i;
    int heures = newTemps.getHeure();

    while(minutes < 0)
    {
        minutes = minutes + 60;
        heures = heures - 1;
    }

    if(heures < 0)
    {
        throw TempsException("Soustraction qui depasse", 2);
        return newTemps;
    }

    newTemps.setMinute(minutes);
    newTemps.setHeure(heures);

    return newTemps;
}

const Temps operator-(int i, const Temps& t1)
{
    Temps newTemps(i);      //Attention changement car sinon on ne respecte pas l'ordre de la soustraction
    Temps tempsEnMoins(t1);

    return newTemps - tempsEnMoins;
}

int Temps::operator<(const Temps& t)
{
    return compT(t)==-1;
}

int Temps::operator>(const Temps& t)
{
    return compT(t)==1;
}

int Temps::operator==(const Temps& t)
{
    return compT(t)==0;
}

int Temps::compT(const Temps& t)
{
    //Comparer heures
    if(getHeure() < t.getHeure()) return -1;
    if(getHeure() > t.getHeure()) return 1;
    //Meme heure, comparer minutes
    if(getMinute() < t.getMinute()) return -1;
    if(getMinute() > t.getMinute()) return 1;
    //Temps egaux
    return 0;
}

ostream& operator<<(ostream& s, const Temps& t)
{

    s << t.getHeure() << "h";

    if(t.getMinute() < 10)
        s << "0";

    s << t.getMinute();

    return s;
}

istream& operator>>(istream& s, Temps& t)
{
    int heures, minutes;
    cout << endl << "Entrez l'heure :       ";
    cin >> heures;
    cout << "Entrez les minutes :   ";
    cin >> minutes;

    if(heures < 0 || heures > 24 || minutes < 0 || minutes > 59)
    {
        throw TempsException("Saisie incorrecte", 3);
    }

    t.setHeure(heures);
    t.setMinute(minutes);

    return s;
}

Temps Temps::operator++()
{
    (*this) = (*this) + 30;
    return (*this);
}

Temps Temps::operator++(int)
{
    Temps tmp(*this);
    (*this) = (*this) + 30;
    return tmp;
}

Temps Temps::operator--()
{
    (*this) = (*this) - 30;
    return (*this);
}

Temps Temps::operator--(int)
{
    Temps tmp(*this);
    (*this) = (*this) - 30;
    return tmp;
}

//METHODES
void Temps::Affiche() const
{
    cout << heure << "h";
    
    if(minute < 10)
        cout << "0";
    
    cout << minute;
}

void Temps::Save(ofstream& fichier) const 
{
    if(!fichier.is_open())
    {
        cout << "ERREUR : Ouverture fichier impossible" << endl;
        exit(1);
    } 

    int h = getHeure(), m = getMinute();

    fichier.write((char *)&h, sizeof(int));
    fichier.write((char *)&m, sizeof(int));
}

void Temps::Load(ifstream& fichier) 
{
    int h = 0;
    int m = 0;

    if(!fichier.is_open())
    {
        cout << "ERREUR : Ouverture fichier impossible" << endl;
        exit(1);
    } 

    fichier.read((char*)&h, sizeof(int));
    fichier.read((char*)&m, sizeof(int));

    setHeure(h);
    setMinute(m);
}
