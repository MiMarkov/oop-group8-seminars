#include "WordTranslationQuestion.h"

WordTranslationQuestion::WordTranslationQuestion(std::string word,
                                                 std::string translation)
    :TranslationQuestion(word, translation, 1)
{
    // word translation questions always have a difficulty of 1
}

double WordTranslationQuestion::scoreAnswer(std::string answer) const {
    return answer.compare(translation) == 0? getDifficulty() : 0;
}
