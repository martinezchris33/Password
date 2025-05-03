#include <gui/containers/TextAreaVisualisation.hpp>

TextAreaVisualisation::TextAreaVisualisation()
{

}

void TextAreaVisualisation::initialize()
{
    TextAreaVisualisationBase::initialize();
    buffer[0] = ' ';
}

/*********************************************************************************/
/**********  DISPLAY THE CHARACTER ON THE TEXT, WHEN THE USER CHOOSES  ***********/
/**********         IT BY CLICKING ON THE BUTTON OF HIS CHOICE.        ***********/
/*********************************************************************************/
/*  You can see several buttons on the Keyboard container. Each button is included 
    in different containers depending on its type. For example you can find the
    buttons numbers in the container named numberCustomContainer.

    Finally, the writeCharacter() action is implemented to
    add the character to a variable buffer and then assign the buffer to the TextArea Text.
*/
void TextAreaVisualisation::writeCharacter(char value){
    // value-> corresponds to the character associated with the button that was clicked
    if (positionText < 60) { // string length limit
        positionText++;
        buffer[positionText] = value; // ajoute le caractère dans le buffer

    }
    visualizationText();
}

void TextAreaVisualisation::visualizationText(){
    if (visibleButton.getState()){
        Unicode::strncpy(textArea1Buffer, buffer, TEXTAREA1_SIZE);
    } else{
        // Crée un buffer temporaire rempli de 'x'
        Unicode::UnicodeChar maskedBuffer[TEXTAREA1_SIZE];
        for (int i = 0; i < TEXTAREA1_SIZE; i++) {
            maskedBuffer[i] = 0; // on nettoie d'abord le buffer
        }
        for (int i = 0; i <= positionText; i++) {
            maskedBuffer[i] = 'x'; // on remplace chaque caractère tapé par 'x'
        }
        Unicode::strncpy(textArea1Buffer, maskedBuffer, TEXTAREA1_SIZE);
    }
    
    textArea1.invalidate();
    textArea1.resizeToCurrentText();
    textArea1.invalidate();
}

/*********************************************************************************/
/**********           DELETE THE LAST CHARACTER ON THE TEXT,           ***********/
/**********        WHEN THE USER HAS CLICKED ON DELETEFLEXBUTTON       ***********/
/*********************************************************************************/
/*  For the function deleteLastCharacter() we use:
    - The buttonDeleteCustomContainer Container
    - The valueDelete trigger on buttonDeleteCustomContainer 
    - The deleteCharacter interaction on buttonDeleteCustomContainer 
    (valueDelete is emited when the deleteFlexButton is cliked)
    - The deleteLastCharacter() action on the Keyboard
    - The deleteTheLastCharacter interaction on the Keyboard 
    (call deleteLastCharacter() when the valueDelete is emit)
*/
void TextAreaVisualisation::deleteLastChracter()
{
    // Delete the last character of the buffer:
    buffer[positionText] = '\0';
    if (positionText>-1){
        positionText--;  
    }else { //put a space if we delete all the characters of string 
        positionText=-1;
    }
    // Affiche le texte normal
    visualizationText();
}