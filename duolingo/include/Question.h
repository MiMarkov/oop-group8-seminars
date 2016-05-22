#ifndef QUESTION_H
#define QUESTION_H

#include <string>
class Question
{
    public:
        Question(int=1);
        virtual std::string askQuestion() const = 0;
        virtual std::string getHelpMessage() const = 0;
        virtual double scoreAnswer(std::string) const = 0;
        int getDifficulty() const;
    private:
        int difficulty;
};

#endif // QUESTION_H
