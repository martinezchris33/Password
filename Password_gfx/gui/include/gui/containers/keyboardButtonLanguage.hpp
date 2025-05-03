#ifndef KEYBOARDBUTTONLANGUAGE_HPP
#define KEYBOARDBUTTONLANGUAGE_HPP

#include <gui_generated/containers/keyboardButtonLanguageBase.hpp>

class keyboardButtonLanguage : public keyboardButtonLanguageBase
{
public:
    keyboardButtonLanguage();
    virtual ~keyboardButtonLanguage() {}

    virtual void initialize();
protected:
};

#endif // KEYBOARDBUTTONLANGUAGE_HPP
