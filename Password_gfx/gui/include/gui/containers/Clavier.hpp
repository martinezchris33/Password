#ifndef CLAVIER_HPP
#define CLAVIER_HPP

#include <gui_generated/containers/ClavierBase.hpp>

class Clavier : public ClavierBase
{
public:
    Clavier();
    virtual ~Clavier() {}

    virtual void initialize();
protected:
};

#endif // CLAVIER_HPP
