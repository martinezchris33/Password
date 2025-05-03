#ifndef CLAVIER_MAJ_HPP
#define CLAVIER_MAJ_HPP

#include <gui_generated/containers/Clavier_MAJBase.hpp>

class Clavier_MAJ : public Clavier_MAJBase
{
public:
    Clavier_MAJ();
    virtual ~Clavier_MAJ() {}

    virtual void initialize();
protected:
};

#endif // CLAVIER_MAJ_HPP
