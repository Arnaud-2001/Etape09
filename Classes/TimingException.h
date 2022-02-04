#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H

#include "Exception.h"

class TimingException : public Exception
{
    private:
        int code;

    public:
        
        //CONSTRUCTEURS
        TimingException();
        TimingException(const char* m, int c);
        TimingException(const TimingException& te);

        //DESTRUCTEUR
        ~TimingException();

        //SETTERS/GETTERS
        void setCode(int c);

        int getCode() const; //Issu de la méthode virtuelle Exception.h

        //METHODES


        //VARIABLES STATIQUES
        const static int JOUR_INVALIDE, AUCUN_TIMING;
        
};

#endif