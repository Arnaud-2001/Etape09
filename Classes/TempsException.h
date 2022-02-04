#ifndef TEMPSEXCEPTION_H
#define TEMPSEXCEPTION_H

#include "Exception.h"

class TempsException : public Exception
{
    private:
        int code;

    public:
        
        //CONSTRUCTEURS
        TempsException();
        TempsException(const char* m, int c);
        TempsException(const TempsException& te);

        //DESTRUCTEUR
        ~TempsException();

        //SETTERS/GETTERS
        void setCode(int c);

        int getCode() const; //Issu de la méthode virtuelle Exception.h

        //METHODES


        //VARIABLES STATIQUES
        const static int HEURE_INVALIDE, MINUTE_INVALIDE, DEPASSEMENT, FORMAT_INVALIDE;
        
};

#endif