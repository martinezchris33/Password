#ifndef TEXTAREAVISUALISATION_HPP
#define TEXTAREAVISUALISATION_HPP

#include <gui_generated/containers/TextAreaVisualisationBase.hpp>

class TextAreaVisualisation : public TextAreaVisualisationBase
{
public:
    TextAreaVisualisation();
    virtual ~TextAreaVisualisation() {}

    virtual void initialize();

    /******  INITIALIZATION OF FUNCTIONS *******/
    virtual void writeCharacter(char value);
    virtual void deleteLastChracter();
    virtual void visualizationText();
protected:
    char buffer[60] = {}; // variable that will be displayed in the TextArea -> Text (contains the characters entered by the user)
    int positionText = -1; // position of the character (entered by the user on the keyboard) in the variable buffer. 
};

#endif // TEXTAREAVISUALISATION_HPP
