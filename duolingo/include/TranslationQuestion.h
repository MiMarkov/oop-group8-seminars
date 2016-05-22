#ifndef TRANSLATIONQUESTION_H
#define TRANSLATIONQUESTION_H

#include <string>
#include "Question.h"

class TranslationQuestion : public Question
{
    public:
        TranslationQuestion(std::string, std::string, int);
        std::string askQuestion() const;
        std::string getHelpMessage() const;
    protected:
        std::string source;
        std::string translation;
    private:
};

#endif // TRANSLATIONQUESTION_H
