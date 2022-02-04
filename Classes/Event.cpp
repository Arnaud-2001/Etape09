#include "Event.h"

const int L_CHAR = 1;
int Event::codeCourant = 1;

Event::Event()   //CONSTRUCTEUR PAR DEFAUT
{
  #ifdef DEBUG
  cout << "---Event : constructeur par défaut---" << endl; //TRACE
  #endif

  intitule  = NULL;
  timing    = NULL;

  setCode(0);
  
  Event::codeCourant++;
}

Event::Event(int c, const char* i, Timing& t) //CONSTRUCTEUR D'INITIALISATION AVEC TIMING
{
  #ifdef DEBUG
  cout << "---Event : constructeur d'initialisation---" << endl; //TRACE
  #endif

  intitule  = NULL;
  timing    = NULL;

  setCode(c);
  setIntitule(i);
  
  Timing *tmp = new Timing(t.getJour(), t.getHeure(), t.getDuree());
  setTiming(*tmp);

  Event::codeCourant++;
}

Event::Event(int c, const char* i) //CONSTRUCTEUR D'INITIALISATION SANS TIMING
{
  #ifdef DEBUG
  cout << "---Event : constructeur d'initialisation---" << endl; //TRACE
  #endif

  intitule  = NULL;
  timing    = NULL;

  setCode(c);
  setIntitule(i);

  Event::codeCourant++;
}

Event::Event(const Event& e) //CONSTRUCTEUR DE COPIE
{
  #ifdef DEBUG
  cout << "---Event : constructeur de copie---" << endl; //TRACE
  #endif

  intitule  = NULL;
  timing    = NULL;

  setCode(e.getCode());
  setIntitule(e.getIntitule());
  setTiming(e.getTiming());

  Event::codeCourant++;
}

//DESTRUCTEUR
Event::~Event()  
{
  #ifdef DEBUG
  cout << "---Event : destructeur---" << endl; //TRACE
  #endif

  if(intitule) delete intitule; //Si pointeur non NULL alors delete
  if(timing) delete timing;

  Event::codeCourant--;
}

void Event::setCode(int c)
{
  if(c >= 0)
    code = c;
  else
    return;

}

//SETTERS/GETTERS
void Event::setIntitule(const char* i)
{
  if(i == NULL) return;
  
  if(intitule) delete intitule;
  intitule = new char[strlen(i)+1];
  strcpy(intitule,i);
}

void Event::setTiming(const Timing& t)
{
  if(timing) delete timing;

  timing = new Timing();
  timing->setJour(t.getJour());
  timing->setHeure(t.getHeure());
  timing->setDuree(t.getDuree());
}

int Event::getCode() const
{
  return code;
}

const char* Event::getIntitule() const
{
  return intitule;
}

Timing Event::getTiming() const
{
  if(!timing) throw TimingException("Timing inexistant", 1);

  return Timing(*timing);
}

//METHODES
void Event::Affiche() const //const après afin que la méthode ne peut modifier aucune variable membre de la classe -> Protection
{
  cout  << "Event : Code = " << code << " // Intitule = ";

  if(intitule)  //si intitule contient quelque chose alors on l'affiche sinon on signale "rien" par "/"
    cout << intitule;
  else
    cout << "/";

  cout << " // Timing = ";

  if(timing)
    timing->Affiche();
  else
    cout << "/";

}

void Event::Save(ofstream& fichier) const 
{
  if(!fichier)
  {
    cout << "ERREUR : Ouverture fichier impossible" << endl;
    exit(1);
  } 

  int c = getCode();
  int longueurIntitule = strlen(getIntitule());

  fichier.write((char *)&c, sizeof(int));

  fichier.write((char *)&longueurIntitule, sizeof(int));
  fichier.write(getIntitule(), longueurIntitule);

  getTiming().Save(fichier);
}

void Event::Load(ifstream& fichier) 
{
  if(!fichier)
  {
    cout << "ERREUR : Ouverture fichier impossible" << endl;
    exit(1);
  } 

  int     tmpC = 0;
  int     longueurIntitule = 0;
  char*   tmpI = NULL;
  Timing  tmpT;

  fichier.read((char *)&tmpC, sizeof(int));

  fichier.read((char *)&longueurIntitule, sizeof(int));
  tmpI = new char[longueurIntitule];
  fichier.read(tmpI, longueurIntitule);
  
  tmpT.Load(fichier);

  setCode(tmpC);
  setIntitule(tmpI);
  setTiming(tmpT);
} 

