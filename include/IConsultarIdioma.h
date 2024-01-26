#ifndef CONSULTARIDIOMA_H
#define CONSULTARIDIOMA_H

#include <string>
#include <set>

using namespace std;

class IConsultarIdioma
{
public:
    virtual set<string> listarIdiomas() = 0;
};

#endif