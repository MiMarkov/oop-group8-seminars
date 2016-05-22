#include <string>
#include "TranslationQuestion.h"

TranslationQuestion::TranslationQuestion(std::string source,
                                         std::string translation,
                                         int difficulty)
    :Question(difficulty), source(source), translation(translation)
{ }

std::string TranslationQuestion::askQuestion() const {
    return source;
}

std::string TranslationQuestion::getHelpMessage() const {
    return "Write the translation of the given expression";
}
