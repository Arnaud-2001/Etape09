#include "TimingException.h"

//VARIABLES STATIQUES
const int TimingException::JOUR_INVALIDE     = 0;
const int TimingException::AUCUN_TIMING      = 1;

//CONSTRUCTEURS
TimingException::TimingException() : Exception()
{
    #ifdef DEBUG
    cout << "---TimingException : constructeur par defaut---" << endl;
    #endif

    setCode(0);
}

TimingException::TimingException(const char* m, int c) : Exception(m)
{
    #ifdef DEBUG
    cout << "---TimingException : constructeur d'initialisation---" << endl;
    #endif

    setCode(c);
}

TimingException::TimingException(const TimingException& te) : Exception(te)
{
    #ifdef DEBUG
    cout << "---TimingException : constructeur de copie---" << endl;
    #endif

    setCode(te.getCode());
}

//DESTRUCTEUR
TimingException::~TimingException()
{
    #ifdef DEBUG
    cout << "---TimingException : destructeur---" << endl;
    #endif
}

//SETTERS/GETTERS
void TimingException::setCode(int c)
{
    if(code < 0)
        code = 0;
    else
        code = c;
}

int TimingException::getCode() const     //Issu de la méthode virtuelle Exception.h
{
    return code;
}

//METHODES