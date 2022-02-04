#include "TempsException.h"

//VARIABLES STATIQUES
const int TempsException::HEURE_INVALIDE    = 0;
const int TempsException::MINUTE_INVALIDE   = 1;
const int TempsException::DEPASSEMENT       = 2;
const int TempsException::FORMAT_INVALIDE   = 3;

//CONSTRUCTEURS
TempsException::TempsException() : Exception()
{
    #ifdef DEBUG
    cout << "---TempsException : constructeur par defaut---" << endl;
    #endif

    setCode(0);
}

TempsException::TempsException(const char* m, int c) : Exception(m)
{
    #ifdef DEBUG
    cout << "---TempsException : constructeur d'initialisation---" << endl;
    #endif

    setCode(c);
}

TempsException::TempsException(const TempsException& te) : Exception(te)
{
    #ifdef DEBUG
    cout << "---TempsException : constructeur de copie---" << endl;
    #endif

    setCode(te.getCode());
}

//DESTRUCTEUR
TempsException::~TempsException()
{
    #ifdef DEBUG
    cout << "---TempsException : destructeur---" << endl;
    #endif
}

//SETTERS/GETTERS
void TempsException::setCode(int c)
{
    if(code < 0)
        code = 0;
    else
        code = c;
}

int TempsException::getCode() const     //Issu de la méthode virtuelle Exception.h
{
    return code;
}

//METHODES