#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <gui_generated/containers/PasswordBase.hpp>

class Password : public PasswordBase
{
public:
    Password();
    virtual ~Password() {}

    virtual void initialize();
protected:
};

#endif // PASSWORD_HPP
