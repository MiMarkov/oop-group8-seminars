#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <vector>
#include "TranslationPair.h"
#include "Question.h"
#include "Test.h"

class TestGenerator
{
    public:
        TestGenerator(std::vector<TranslationPair>, std::vector<TranslationPair>);
        Test* generateTest(int) const;
    private:
        std::vector<TranslationPair> wordList;
        std::vector<TranslationPair> sentenceList;
        Question* generateWordTranslationQuestion() const;
        Question* generateSentenceTranslationQuestion() const;
};

#endif // TESTGENERATOR_H
