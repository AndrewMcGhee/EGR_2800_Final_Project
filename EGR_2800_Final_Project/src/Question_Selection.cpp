#include "../include/Question_Selection.hpp"

bool Answer; 
int RandNum;
/*string*/ int Question;

char SelectQuestionMath(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
        const char* falseMathQuestions[4][128] = { {"(11+9)*12 = 220"},
                                               {"The absolute value of a real negative number is negative."},
                                               {"Pi can be correctly written as a fraction."},
                                               {"-4 is a natural number."}      
                                             };
    return *falseMathQuestions [ getRandomValue(1,4) ];
    }
    else if (Answer == true) {
        const char* trueMathQuestions[4][128] = { {"9 x 8 = 72."},
                                                  {"19 + 14 ÷ 7 = 3 × 7"}
                                                  {"Natural numbers include all positive counting numbers"}
                                                  {"Real numbers are the set of all rational and irrational numbers"}
                                                };
    return *TrueMathQuestions [ getRandomValue(1,4) ];
    }

}

char SelectQuestionGeo(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    return(Question); 
}

const char* SelectQuestionBio(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
    const char* falseBioQuestions[4][128] = { { "The Large intestine is the longest part of digestive system of human." },
                                           { "Sharks are mammals." },
                                           { "The human skeleton is made up of less than 100 bones." },
                                           { "Water is an example of a chemical element." },
                                         };

    return *falseQuestions[ getRandomValue(1,4) ];
    }
    if (Answer == true) {
    const char* trueBioQuestions[4][128] = { {"Dogs have 42 teeth." }, 
                                             {"Rabbits are not carnivores."},
                                             {"Mitochondria is the powerhouse of the cell"},
                                             {"An algae is a type of autotroph."}
                                           };

    return *trueBioQuestions [ getRandomValue(1,4) ];
    }
    
}
char SelectQuestionTrivia( int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }

    return(Question);
}