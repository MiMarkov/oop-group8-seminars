#include "Question.h"

Question::Question(int difficulty)
    :difficulty(difficulty) { }

int Question::getDifficulty() const {
    return difficulty;
}
