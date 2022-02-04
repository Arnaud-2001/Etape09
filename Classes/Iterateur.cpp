#include "Iterateur.h"

//CONSTRUCTEURS
template <class T>
Iterateur<T>::Iterateur(Liste<T>& l) : liste(l)  //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Iterateur : constructeur d'initialisation---" << endl; //TRACE
    #endif

    setCurrent(l.getTete());
}

//DESTRUCTEUR
template<class T>
Iterateur<T>::~Iterateur()
{
    #ifdef DEBUG
    cout << "---Iterateur : destructeur---" << endl; //TRACE
    #endif

    setCurrent(NULL);
}

//SET/GET
template <class T>
void Iterateur<T>::setListe(const Liste<T>& l) 
{ 
    liste = l; 
}

template <class T>
Liste<T>& Iterateur<T>::getListe() const 
{ 
    return liste; 
}

template <class T>
void Iterateur<T>::setCurrent(Cellule<T> *pC) 
{ 
    pCurrent = pC; 
}

template <class T>
Cellule<T>* Iterateur<T>::getCurrent() const 
{ 
    return pCurrent; 
}

//METHODES
template <class T>
bool Iterateur<T>::end() 
{ 
    if(!getCurrent())
        return true;
    else
        return false;
}

template <class T>
void Iterateur<T>::reset() 
{ 
    setCurrent(getListe().getTete()); 
}

template <class T>
Iterateur<T> Iterateur<T>::operator++()
{
    if (getCurrent())
    {
        setCurrent(getCurrent()->suivant);
        return *this;
    }
    else
        return *this;
}

template <class T>
Iterateur<T> Iterateur<T>::operator++(int) 
{ 
    Iterateur<T> tmp(*this);

    if (getCurrent())
    {
        setCurrent(getCurrent()->suivant);
        return tmp;
    }
    else
        return *this;
}

template <class T>
Iterateur<T>::operator T() const 
{ 
    return this->getCurrent()->valeur; 
}

//INSTANCIATION DES TEMPLATES
template class Iterateur<int>;
#include "Professeur.h"
template class Iterateur<Professeur>;
#include "Groupe.h"
template class Iterateur<Groupe>;
#include "Local.h"
template class Iterateur<Local>;