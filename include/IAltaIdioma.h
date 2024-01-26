#ifndef IALTAIDIOMA_H
#define IALTAIDIOMA_H

#include <string>

using namespace std;

class IAltaIdioma
{
public:
    virtual bool ingresoDatos(string idioma) = 0;
};

#endif