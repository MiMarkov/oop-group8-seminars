#include <vector>
#include <cstdlib>
#include "TestGenerator.h"
#include "Test.h"
#include "Question.h"
#include "WordTranslationQuestion.h"
#include "SentenceTranslationQuestion.h"

TestGenerator::TestGenerator(std::vector<TranslationPair> wordList,
                             std::vector<TranslationPair> sentenceList)
             :wordList(wordList), sentenceList(sentenceList)
{ }

Test* TestGenerator::generateTest(int numQuestions) const {
    Test* test = new Test();
    for (int i = 0; i < numQuestions; i++) {
        // randomly decide what type of question to include
        if (rand()%2) {
            test->addQuestion(generateWordTranslationQuestion());
        } else {
            test->addQuestion(generateSentenceTranslationQuestion());
        }
    }
    return test;
}

Question* TestGenerator::generateWordTranslationQuestion() const {
    int randIdx = rand() % wordList.size();
    return new WordTranslationQuestion(wordList[randIdx].source, wordList[randIdx].translation);
}

Question* TestGenerator::generateSentenceTranslationQuestion() const {
    int randIdx = rand() % sentenceList.size();
    return new SentenceTranslationQuestion(sentenceList[randIdx].source, sentenceList[randIdx].translation);
}
