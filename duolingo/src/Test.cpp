#include <iostream>
#include "Test.h"

void Test::addQuestion(Question* question) {
    questions.push_back(question);
}

double Test::test() const {
    double maxScore = 0;
    double totalScore = 0;
    double currentScore;
    std::cout << "BEGIN TEST" << std::endl << std::endl;
    for (unsigned int i = 0; i < questions.size(); i++) {
        Question* q = questions[i];
        std::cout << q->getHelpMessage() << ": " << std::endl;
        std::cout << q->askQuestion() << std::endl;
        std::string answer;
        std::getline(std::cin, answer);

        currentScore = q->scoreAnswer(answer);
        totalScore += currentScore;
        maxScore += q->getDifficulty();
        std::cout << "You scored " << currentScore/q->getDifficulty() << " on this question." << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl << "END TEST" << std::endl;
    return totalScore / maxScore;
}
