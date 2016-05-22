#ifndef WORDTRANSLATIONQUESTION_H
#define WORDTRANSLATIONQUESTION_H

#include "TranslationQuestion.h"


class WordTranslationQuestion : public TranslationQuestion
{
    public:
        WordTranslationQuestion(std::string, std::string);
        double scoreAnswer(std::string) const;
    protected:
    private:
};

#endif // WORDTRANSLATIONQUESTION_H
