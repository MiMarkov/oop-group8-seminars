#include <string>
#include <sstream>
#include <vector>
#include "SentenceTranslationQuestion.h"

SentenceTranslationQuestion::SentenceTranslationQuestion(std::string sentence,
                                                         std::string translation)
    :TranslationQuestion(sentence, translation, 2)
{
    // sentence translations are worth 2 points (i.e. have difficulty = 2)
}

std::vector<std::string> SentenceTranslationQuestion::splitSentence(std::string sentence) {
    std::stringstream tokenizer(sentence);
    std::vector<std::string> result;
    std::string word;
    while(std::getline(tokenizer, word, ' ')) {
        result.push_back(word);
    }
    return result;
}

double SentenceTranslationQuestion::scoreAnswer(std::string answer) const {
    std::vector<std::string> splitTranslation = splitSentence(translation);
    std::vector<std::string> splitAnswer = splitSentence(answer);
    int wrongWords = 0, transLen = splitTranslation.size(), ansLen = splitAnswer.size();
    int minSentLen = transLen < ansLen? transLen : ansLen;
    for (int i = 0; i < minSentLen; ++i) {
        if (splitTranslation[i].compare(splitAnswer[i]) != 0) {
            ++wrongWords;
        }
    }
    // If the actual translation is longer than the given answer, count the missing words as wrong
    wrongWords += transLen - minSentLen;
    // if the actual translation is shorter than the given answer, count the extra words as wrong
    wrongWords += ansLen - minSentLen;

    // give partial score if exactly one word is wrong
    if (wrongWords == 0) {
        return getDifficulty();
    } else if (wrongWords == 1) {
        return getDifficulty() / 2.0;
    } else {
        // more than one wrong word, no score earned
        return 0.0;
    }
}
