#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class Exception
{

    protected:
        char* message;

    public:

        //CONSTRUCTEURS
        Exception();                        //DEFAUT
        Exception(const char* m);           //INITIALISATION
        Exception(const Exception& e);      //COPIE

        //DESTRUCTEUR
        virtual ~Exception();

        //SETTERS/GETTERS
        void setMessage(const char*);

        const char* getMessage() const;

        //METHODES
        virtual int getCode() const = 0;

};

#endif