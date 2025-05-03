#include <gui/containers/Keyboard.hpp>
#include <touchgfx/utils.hpp>

Keyboard::Keyboard():
characterPartTwoMode(false),numberMode(false),capitalLetterMode(false),positionText(-1)// initialization 
{
}

void Keyboard::initialize()
{
    KeyboardBase::initialize();
    //buffer[0] = ' '; // initialization of the first character of the buffer string
}


/*********************************************************************************/
/**********               SWITCH THE LETTERS EN CAPITAL               ***********/
/*********************************************************************************/
/*  The displayCapitalLetters() action is used in the same way as deleteLastCharacter(). 
    It uses:
    - The buttonModeCapitalLetterCustomContainer Container
    - The valueCapitalLetterMode trigger on buttonModeCapitalLetterCustomContainer 
    - The putModeCapitalLetter interaction on buttonModeCapitalLetterCustomContainer 
    (valueCapitalLetterMode is emited when the capitalLetterToggleButton is cliked)
    - The displayCapitalLetters() action on the Keyboard
    - The displayButtons_CapitalLetters interaction on the Keyboard 
    (call displayCapitalLetters() when the valueCapitalLetterMode is emit)
*/
void Keyboard::displayCapitalLetters()
{ 
    capitalLetterMode= ! capitalLetterMode; //switch the mode
    if((capitalLetterMode == true)){    //make the containers visible or not, depending on what we want to display
        clavier.setVisible(false);
        clavier_MAJ.setVisible(true);
    }else{
        clavier.setVisible(true);
        clavier_MAJ.setVisible(false);
    }
    clavier.invalidate();
    clavier_MAJ.invalidate();
}


/*********************************************************************************/
/**********        DISPLAY THE SCREEN IN THE NUMBERED MODE, I.E.       ***********/
/**********  THE NUMBERS AND THE FIRST PARS OF THE SPECIAL CHARACTERS  ***********/
/*********************************************************************************/
/*  The displayNumbers() action is used in the same way as deleteLastCharacter(). 
    It uses:
    - The buttonModeNumberCustomContainer Container
    - The valueModeNumber trigger on buttonModeNumberCustomContainer 
    - The putModeNumber interaction on buttonModeNumberCustomContainer 
    (valueModeNumber is emited when the modeNumberToggleButton is cliked)
    - The displayNumbers() action on the Keyboard
    - The displayButtons_Numbers interaction on the Keyboard 
    (call displayNumbers() when the valueModeNumber is emit)
*/
void Keyboard::displayNumbers()
{
    numberMode=! numberMode; //switch the mode
    if((numberMode== true)){    
        //make the containers visible or not, depending on what we want to display
        numberModeContainer.setVisible(true);
        buttonModeCharPartTwoContainer.setVisible(true);
        clavier_MAJ.setVisible(false);
        clavier.setVisible(false);
        buttonModeCapitalLetterContainer.setVisible(false);
    }else{
        numberModeContainer.setVisible(false);
        specialCharPartTwoContainer.setVisible(false);
        buttonModeCharPartTwoContainer.setVisible(false);
        clavier_MAJ.setVisible(false);
        if((capitalLetterMode ==true)){  //check if the buttonModeCapitalLetterCustomContainer is still selected  
            clavier.setVisible(false);
            clavier_MAJ.setVisible(true);
        }else{
            clavier.setVisible(true);
            clavier_MAJ.setVisible(false);
        }
        buttonModeCapitalLetterContainer.setVisible(true);
    }
    numberModeContainer.invalidate();
    buttonModeCharPartTwoContainer.invalidate();
    clavier_MAJ.invalidate();
    clavier.invalidate();
    buttonModeCapitalLetterContainer.invalidate();
    specialCharPartTwoContainer.invalidate();
}


/*********************************************************************************/
/**********      DISPLAY THE SECOND PART OF THE SPECIAL CHARACTERS     ***********/
/*********************************************************************************/
/*  The displayCharactersPartTwo() action is used in the same way as deleteLastCharacter(). 
    It uses:
    - The buttonModeCharPartTwoCustomContainer Container
    - The valueModeCharPartTwo trigger on buttonModeCharPartTwoCustomContainer 
    - The putModeCharPartTwo interaction on buttonModeCharPartTwoCustomContainer 
    (valueModeCharPartTwo is emited when the characterPartTwoToggleButton is cliked)
    - The displayCharactersPartTwo() action on the Keyboard
    - The displayButtons_SpecialCharPartTwo interaction on the Keyboard 
    (call displayCharactersPartTwo() when the valueModeCharPartTwo is emit)
*/
void Keyboard::displayCharactersPartTwo()
{
    characterPartTwoMode=!characterPartTwoMode; //switch the mode
    if(characterPartTwoMode==true){    
        //make the containers visible or not, depending on what we want to display
        specialCharPartTwoContainer.setVisible(true);
        numberModeContainer.setVisible(false);
    }else{
        specialCharPartTwoContainer.setVisible(false);
        numberModeContainer.setVisible(true);
    }
    specialCharPartTwoContainer.invalidate();
    numberModeContainer.invalidate();
}

/*********************************************************************************/
/**********     RETURN THE TEXT ENTERED BY THE USER ON THE KEYBOARD    ***********/
/*********************************************************************************/
char* Keyboard::getText(){
    return buffer;
}