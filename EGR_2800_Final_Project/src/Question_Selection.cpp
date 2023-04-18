#include "../include/Question_Selection.hpp"

bool Answer; 
int RandNum;
/*string*/ int Question;

char SelectQuestionMath(int Number) {


    return(Question);
}

char SelectQuestionGeo(int Number) {

    return(Question);
}

char SelectQuestionBio(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {

    switch(RandNum) {
     case 1:

        //string Question  = "The Large intestine is the longest part of digestive system of human.";
        break;
     case 2:
        //string Question = "Sharks are mammals.";
        break;
     case 3:
        //string Question = "The human skeleton is made up of less than 100 bones.";
        break;
     case 4: 
        //string Question = "Water is an example of a chemical element.";
        break;
    }
    }
    if (Answer == true) {

    switch(RandNum) {
        case 1: 
            //string Question = "Dogs have 42 teeth."
            break;
        case 2:
            //string Question = "Rabbits are not carnivores."
            break;
        case 3:

        break;
        case 4:
        
        break;
    }
    }
    return(Question);
}

char SelectQuestionTrivia( int Number) {

    return(Question);
}