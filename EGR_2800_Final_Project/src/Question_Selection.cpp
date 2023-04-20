#include "../include/Question_Selection.hpp"

bool Answer; 
int RandNum;


const char* SelectQuestionMath(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
        const char* falseMathQuestions[3][128] = { "The absolute value of a real negative number is negative.",
                                                   "Pi can be correctly written as a fraction.",
                                                   "-4 is a natural number."      
                                                };
    return *falseMathQuestions [ random(1,3) ];
    }
    else if (Answer == true) {
        const char* trueMathQuestions[3][128] = { "19 + 14 ÷ 7 = 3 × 7",
                                                  "Natural numbers include all positive counting numbers",
                                                  "Real numbers are the set of all rational and irrational numbers",
                                                };
    return *trueMathQuestions [ random(1,3) ];
    }

}

const char* SelectQuestionGeo(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
        const char* falseGeoQuestions[3][128] = { "The Great Barrier Reef is located in Australia",
                                                  "The Mississippi River is the longest river in the United States.",
                                                  "Mount Rushmore is located in the state of California."
                                                };
        return *falseGeoQuestions[ random(1,3) ];
        }
    if (Answer == true) {
        const char* trueGeoQuestions[3][128] = { "Mount Everest is the highest mountain in the world.",
                                                "The state of Alaska has a coastline longer than the entire contiguous United States.",
                                                "The highest point in the continental United States is Mount Whitney in California."
                                              };
        return *trueGeoQuestions[ random(1,3) ];
        }
    }

const char* SelectQuestionBio(int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
    const char* falseBioQuestions[3][128] = { "The Large intestine is the longest part of digestive system of human." ,
                                           "The human skeleton is made up of less than 100 bones.",
                                           "Water is an example of a chemical element.",
                                         };

    return *falseBioQuestions[ random(1,3) ];
    }
    if (Answer == true) {
    const char* trueBioQuestions[3][128] = {"Dogs have 42 teeth.", 
                                             "Mitochondria is the powerhouse of the cell",
                                             "An algae is a type of autotroph."
                                           };

    return *trueBioQuestions[ random(1,3) ];
    } 
}

const char* SelectQuestionTrivia( int Number) {
    if (Number == 1) { 
        Answer = true;
    }
    else {
        Answer = false;
    }
    if (Answer == false) {
        const char* falseTriviaQuestions[3][128] {
            "All the kings in a standard deck of cards have a mustache.",
            "The name of Batman’s butler is Albert.",
            "Henry VIII had eight wives."
        };
        return *falseTriviaQuestions[random(1,3) ];
    }
    if (Answer == true) {
        const char* trueTriviaQuestions[3][128] {
            "The tallest mammal in the world is the giraffe.",
            "George Washington was the first president of the United States.",
            "Before becoming queen, Queen Elizabeth II trained as a mechanic."
        };
        return *trueTriviaQuestions [ random(1,3) ];
    }
}