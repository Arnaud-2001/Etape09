#include "Liste.h"

//CONSTRUCTEURS
template <class T> 
Liste<T>::Liste()                   //PAR DEFAUT
{
    #ifdef DEBUG
    cout << "---Liste : constructeur par défaut---" << endl; //TRACE
    #endif

    setTete(NULL);
}   

template <class T> 
Liste<T>::Liste(const Liste<T>& l)     //COPIE
{
    #ifdef DEBUG
    cout << "---Liste : constructeur de copie---" << endl; //TRACE
    #endif

    setTete(NULL);
    *this = l;
}

//DESTRUCTEUR
template <class T> 
Liste<T>::~Liste()
{
    #ifdef DEBUG
    cout << "---Liste : destructeur---" << endl; //TRACE
    #endif

    Cellule<T> *pCurrent = NULL, *pPrecedent = NULL;

    pCurrent = getTete();

    while (pCurrent != NULL)
    {
        pPrecedent = pCurrent;
        pCurrent = pCurrent->suivant;
        delete pPrecedent;
    }

    delete pCurrent;
}

//SET/GET
template <class T>
void Liste<T>::setTete(Cellule<T> *t) 
{ 
    pTete = t; 
}

template <class T>
Cellule<T> *Liste<T>::getTete() const 
{ 
    return pTete; 
}

//SURCHARGE OPERATEURS
template <class T> 
Liste<T>& Liste<T>::operator=(const Liste& l)
{
    #ifdef DEBUG
    cout << "---Liste : operator=---" << endl; //TRACE
    #endif

    //Si this contient quelque chose, on le vide d'abord
    if(!estVide())
    {
        Cellule<T> *pTmp        = getTete();
        Cellule<T> *pSuivant    = pTmp->suivant;

        //Ci-dessous, on supprime une à une les cellules de this
        while(pTmp)
        {
            pSuivant = pTmp->suivant;
            delete pTmp;
            pTmp = pSuivant;
        }

        //On efface alors la tête de this
        setTete(NULL);
    }

    if(!l.estVide())    //Si la liste à copier contient quelque chose
    {
        Cellule<T> *pCurrent    = NULL;         //Pointeur actuel
        Cellule<T> *pCreation   = NULL;         //Pointeur pour la création
        Cellule<T> *pListe      = l.getTete();  //Pointeur pour se déplacer dans la liste à copier

        while(pListe)       //Tant qu'il y a quelque chose à copier depuis pListe
        {
            pCreation = new Cellule<T>(pListe->valeur, NULL);   //On crée une cellule depuis pListe
            
            if(estVide())           //Si this est vide
            {
                setTete(pCreation);         //La tête de this devient la cellule créée
                pCurrent    = pCreation;    //On déplace le pointeur actuel à la cellule créée
            }
            else                    //Sinon
            {
                pCurrent->suivant   = pCreation;            //La cellule suivante sera celle créée
                pCurrent            = pCurrent->suivant;    //La cellule actuelle devient celle suivante (donc celle qu'on vient de créer et assigner ci-dessus)
            }

            pListe = pListe->suivant;   //On passe à la cellule suivante à copier
        }
    }
    else                //Sinon
    {
        setTete(NULL);  //This devient NULL puisqu'il n'y a rien à copier
    }

    return *this;
}

//METHODES
template <class T> 
bool Liste<T>::estVide() const
{
    if(getTete() == NULL)
        return true;
    else
        return false;
}

template <class T> 
int Liste<T>::getNombreElements() const
{
    int compte              = 0;
    Cellule<T> *pCurrent    = NULL;

    pCurrent = getTete();

    //Si dessous, tant qu'il y a quelque chose, on augmente le compteur puis on passe à la cellule suivante
    while (pCurrent != NULL)
    {
        compte++;
        pCurrent = pCurrent->suivant;
    }

    return compte;
}

template <class T> 
void Liste<T>::Affiche() const
{
    if(estVide())
    {
        cout << "Liste vide" << endl;
        return;
    }

    int numeroActuel = 0;
    Cellule<T> *pCurrent = getTete();

    while (pCurrent != NULL)
    {
        cout << "N°" << numeroActuel << " -> " << pCurrent->valeur << endl;

        pCurrent = pCurrent->suivant;
        numeroActuel++;
    }
}

template <class T> 
void Liste<T>::insere(const T &val)
{
    Cellule<T> *pNouveau = new Cellule<T>(val, NULL);
    Cellule<T> *pCurrent = getTete(); 

    //Si this est vide
    if(estVide())
    {
        setTete(pNouveau);   //La tête devient pNouveau
    }
    //Sinon
    else
    {
        //Tant qu'il y a un suivant
        while(pCurrent->suivant)
        {
            pCurrent = pCurrent->suivant;   //On passe au suivant
        }

        pCurrent->suivant = pNouveau;   //Le suivant de pCurrent devient pNouveau
    }
}

template <class T> 
T Liste<T>::retire(int ind)
{
    int i = 0;
    Cellule<T> *pCurrent    = getTete();
    Cellule<T> *pTmp        = NULL;
    Cellule<T> *pPrecedent  = NULL;
    T valeur;

    if(estVide())
    {
        cout << "ERREUR : liste deja vide" << endl;
    }
    else
    {
        if(ind == 0)                //Si celui à supprimer est le premier
        {
            pTmp = pCurrent->suivant;   //On conserve le suivant du premier
            delete pCurrent;            //On supprime le premier
            setTete(pTmp);              //Le suivant conservé devient le premier
        }
        else
        {
            //On vérifie que ind ne dépasse pas le nomde d'éléments dans la liste
            if(ind <= getNombreElements())
            {
                while(i < ind)              //Tant qu'on est pas à cellule demandée
                {
                    pPrecedent = pCurrent;          //On conserve pCurrent en tant que précédent
                    pCurrent = pCurrent->suivant;   //L'actuel devient le suivant
                    i++;                            //On augmente i
                }

                //Une fois la cellule à supprimer atteinte
                valeur = pCurrent->valeur;     //On récupère la valeur de l'actuel
                pTmp = pCurrent->suivant;      //On récupère le suivant dans pTmp
                delete pCurrent;               //On supprime l'actuel
                pPrecedent->suivant = pTmp;    //Le suivant du précédent n'est plus celui supprimé mais celui conservé dans pTmp
            }
            else
            {
                return pCurrent->valeur;
            }
        }
    }

    return valeur;
}

//INSTANCIATION DES TEMPLATES
template struct Cellule<int>;
template class Liste<int>;
#include "Professeur.h"
template struct Cellule<Professeur>;
template class Liste<Professeur>;
#include "Groupe.h"
template struct Cellule<Groupe>;
template class Liste<Groupe>;
#include "Local.h"
template struct Cellule<Local>;
template class Liste<Local>;