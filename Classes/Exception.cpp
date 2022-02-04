#include "Exception.h"

//CONSTRUCTEURS
Exception::Exception()                  //DEFAUT
{
    #ifdef DEBUG
    cout << "---Exception : constructeur par defaut---" << endl;
    #endif

    message = NULL;
}

Exception::Exception(const char* m)     //INITIALISATION
{
    #ifdef DEBUG
    cout << "---Exception : constructeur d'initialisation---" << endl;
    #endif

    message = NULL;
    setMessage(m);
}

Exception::Exception(const Exception& e)      //COPIE
{
    #ifdef DEBUG
    cout << "---Exception : constructeur de copie---" << endl;
    #endif

    message = NULL;
    setMessage(e.getMessage());
}

//DESTRUCTEUR
Exception::~Exception()
{
    #ifdef DEBUG
    cout << "---Exception : destructeur---" << endl;
    #endif

    if(message) delete message;
}

//SETTERS/GETTERS
void Exception::setMessage(const char* m)
{
    if(m == NULL)
        return;

    if(message) delete message;
    message = new char[strlen(m)+1];
    strcpy(message,m);    
}

const char* Exception::getMessage() const
{
    return message;
}