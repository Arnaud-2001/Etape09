#ifndef HORAIRE_H
#define HORAIRE_H

#include "ListeTriee.h"
#include "Professeur.h"
#include "Groupe.h"
#include "Local.h"
#include "Iterateur.h"

class Horaire
{
    private :
        ListeTriee<Professeur> professeurs;
        ListeTriee<Groupe> groupes;
        ListeTriee<Local> locaux;
    public:

        //CONSTRUCTEUR
        Horaire();

        //DESTRUCTEUR
        ~Horaire();

        //GETTERS
        ListeTriee<Local>       getLocaux() const;
        ListeTriee<Groupe>      getGroupes() const;
        ListeTriee<Professeur>  getProfesseurs() const;

        //METHODES
        void ajouteProfesseur(const char* nom, const char* prenom);
        void afficheProfesseurs();
        void supprimeProfesseurParIndice(int ind);
        void supprimeProfesseurParId(int id);

        void ajouteGroupe(int numero);
        void afficheGroupes();
        void supprimeGroupeParIndice(int ind);
        void supprimeGroupeParId(int id);

        void ajouteLocal(const char* nom);
        void afficheLocaux();
        void supprimeLocalParIndice(int ind);
        void supprimeLocalParId(int id);
};

#endif