#include "ListeTriee.h"

using namespace std;

//CONSTRUCTEURS
template <class T>
ListeTriee<T>::ListeTriee() : Liste<T>()                            //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---ListeTriee : constructeur par defaut---" << endl; //TRACE
    #endif
}

template <class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T>& l) : Liste<T>(l)     //DE COPIE
{
    #ifdef DEBUG
    cout << "---ListeTriee : constructeur de copie---" << endl; //TRACE
    #endif
}

//DESTRUCTEUR
template <class T>
ListeTriee<T>::~ListeTriee()
{
    #ifdef DEBUG
    cout << "---ListeTriee : destructeur---" << endl; //TRACE
    #endif
}

//METHODES
template <class T>
void ListeTriee<T>::insere(const T& val)
{
    Cellule<T> *pNouveau    = new Cellule<T>(val, NULL);
    Cellule<T> *pCurrent    = this->pTete;
    Cellule<T> *pPrecedent  = NULL;

    int modifOK = 0;

    if(this->estVide())   //Si this est vide
    {
        this->pTete = pNouveau;           //La tête devient pNouveau
    }
    else            //Sinon
    {
        if(pNouveau->valeur < pCurrent->valeur)     //Si le nouveau est inférieur au premier
        {
            pNouveau->suivant = pCurrent;               //Le suivant du nouveau est la liste entière
            this->pTete = pNouveau;                     //La tête devient pNouveau
            modifOK = 1;                                //On notifie de la modification
        }

        while(pCurrent->suivant && modifOK == 0)    //Tant qu'il y a un suivant ET qu'il n'y a pas eu de modification
        {
            pPrecedent = pCurrent;                      //On stocke l'actuel en tant que précédent
            pCurrent = pCurrent->suivant;               //L'actuel passe au suivant

            if(pNouveau->valeur < pCurrent->valeur)     //Si celui à insérer a une valeur inférieure à celle de l'actuel
            {
                pNouveau->suivant = pCurrent;               //Le suivant du nouveau devient l'actuel
                pPrecedent->suivant = pNouveau;             //Le suivant du précédent devient le nouveau
                modifOK = 1;                                //On notifie de la modification
            }
        }

        if(modifOK == 0)            //S'il n'y a pas eu de modification (et qu'on est du coup arrivé à la fin)
        {
            pCurrent->suivant = pNouveau;   //Le suivant de pCurrent devient pNouveau
        }
    }
}

//INSTANCIATION DES TEMPLATES
template class ListeTriee<int>;
#include "Professeur.h"
template class ListeTriee<Professeur>;
#include "Groupe.h"
template class ListeTriee<Groupe>;
#include "Local.h"
template class ListeTriee<Local>;