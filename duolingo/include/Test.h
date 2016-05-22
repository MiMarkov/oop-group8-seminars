#ifndef TEST_H
#define TEST_H

#include <vector>
#include "Question.h"

class Test
{
    public:
        void addQuestion(Question* question);
        double test() const;
    protected:
    private:
        std::vector<Question*> questions;
};

#endif // TEST_H
