#include "Horaire.h"

//CONSTRUCTEUR
Horaire::Horaire()
{
    #ifdef DEBUG
    cout << "--- Horaire : constructeur ---"<< endl;
    #endif
}

//DESTRUCTEUR
Horaire::~Horaire()
{
    #ifdef DEBUG
    cout << "--- Horaire : destructeur ---"<< endl;
    #endif
}

//GETTERS
ListeTriee<Professeur> Horaire::getProfesseurs() const 
{ 
    return professeurs; 
}

ListeTriee<Groupe> Horaire::getGroupes() const 
{ 
    return groupes; 
}

ListeTriee<Local> Horaire::getLocaux() const 
{ 
    return locaux; 
}

//METHODES

//*****Professeurs*****
void Horaire::ajouteProfesseur(const char* nom, const char* prenom)
{
    professeurs.insere(Professeur(0, nom, prenom));
}

void Horaire::afficheProfesseurs()
{
    professeurs.Affiche();
}

void Horaire::supprimeProfesseurParIndice(int ind)
{
    professeurs.retire(ind);
}

void Horaire::supprimeProfesseurParId(int id)
{
    int tmp = 0;

    Iterateur<Professeur> it(professeurs);
    it.reset();
    while(!(it.end()))
    {
        if(((Professeur)it).getId() != id)
        {
            tmp++;
            it++;
        }
        else
        {
            professeurs.retire(tmp);
            return;
        }
    }

    cout << "Professeur a supprimer introuvable" << endl;
}

//*****Groupes*****
void Horaire::ajouteGroupe(int numero)
{
    groupes.insere(Groupe(0, numero));
}

void Horaire::afficheGroupes()
{
    groupes.Affiche();
}

void Horaire::supprimeGroupeParIndice(int ind)
{
    groupes.retire(ind);
}

void Horaire::supprimeGroupeParId(int id)
{
    int tmp = 0;

    Iterateur<Groupe> it(groupes);
    it.reset();
    while(!(it.end()))
    {
        if(((Groupe)it).getId() != id)
        {
            tmp++;
            it++;
        }
        else
        {
            groupes.retire(tmp);
            return;
        }
    }
        
    cout << "Groupe a supprimer introuvable" << endl;
    
}

//*****Locaux*****
void Horaire::ajouteLocal(const char* nom)
{
    locaux.insere(Local(0, nom));
}

void Horaire::afficheLocaux()
{
    locaux.Affiche();
}

void Horaire::supprimeLocalParIndice(int ind)
{
    locaux.retire(ind);
}

void Horaire::supprimeLocalParId(int id)
{
    int tmp = 0;

    Iterateur<Local> it(locaux);
    it.reset();
    while(!(it.end()))
    {
        if(((Local)it).getId() != id)
        {
            tmp++;
            it++;
        }
        else
        {
            locaux.retire(tmp);
            return;
        }
    }
        
    cout << "Local a supprimer introuvable" << endl;
}
