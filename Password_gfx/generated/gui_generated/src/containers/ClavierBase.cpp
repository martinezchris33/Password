/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/ClavierBase.hpp>

ClavierBase::ClavierBase() :
    clavierCharCallback(0),
    clavierUKCharValueLetterCallback(this, &ClavierBase::clavierUKCharValueLetterCallbackHandler),
    clavierFRCharValueLetterCallback(this, &ClavierBase::clavierFRCharValueLetterCallbackHandler)
{
    setWidth(265);
    setHeight(108);
    clavierFR.setXY(0, 0);
    clavierFR.setVisible(false);
    clavierFR.setCharValueLetterCallback(clavierFRCharValueLetterCallback);
    add(clavierFR);

    clavierUK.setXY(0, 0);
    clavierUK.setCharValueLetterCallback(clavierUKCharValueLetterCallback);
    add(clavierUK);
}

ClavierBase::~ClavierBase()
{

}

void ClavierBase::initialize()
{
    clavierFR.initialize();
    clavierUK.initialize();
}

void ClavierBase::clavierUKCharValueLetterCallbackHandler(char value)
{
    //writeCharacterUK
    //When clavierUK charValueLetter emit clavierChar callback
    //Emit callback
    emitClavierCharCallback(value);
}

void ClavierBase::clavierFRCharValueLetterCallbackHandler(char value)
{
    //writeCharacterFR
    //When clavierFR charValueLetter emit clavierChar callback
    //Emit callback
    emitClavierCharCallback(value);
}

void ClavierBase::language(int8_t value)
{
    //DisplayChoice
    //When language is called execute C++ code
    //Execute C++ code
    // Masquer tous les claviers au début
    clavierFR.setVisible(false);
    clavierUK.setVisible(false);
    // clavierES.setVisible(false); // Ajoute ici d'autres si besoin
    // clavierDE.setVisible(false);
    
    switch (value) {
        case 1:
            clavierFR.setVisible(true);
            break;
        case 2:
            clavierUK.setVisible(true);
            break;
        // case 3:
        //     clavierES.setVisible(true);
        //     break;
        default:
            clavierUK.setVisible(true); //clavier par défaut
            break;
    }
    
    // Invalider tous les claviers
    clavierFR.invalidate();
    clavierUK.invalidate();
    // clavierES.invalidate();
    // clavierDE.invalidate();
}
