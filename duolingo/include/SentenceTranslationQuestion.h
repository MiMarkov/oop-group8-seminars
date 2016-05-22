#ifndef SENTENCETRANSLATIONQUESTION_H
#define SENTENCETRANSLATIONQUESTION_H

#include <string>
#include <vector>
#include "TranslationQuestion.h"

class SentenceTranslationQuestion : public TranslationQuestion
{
    public:
        SentenceTranslationQuestion(std::string, std::string);
        double scoreAnswer(std::string) const;
    protected:
    private:
        static std::vector<std::string> splitSentence(std::string sentence);
};

#endif // SENTENCETRANSLATIONQUESTION_H
