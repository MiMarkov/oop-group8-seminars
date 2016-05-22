#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "TranslationPair.h"
#include "Test.h"
#include "TestGenerator.h"
using namespace std;

void populateFromFile(const char* filename, std::vector<TranslationPair>& expressions) {
    ifstream f(filename);
    TranslationPair p;
    while (f >> p) {
        expressions.push_back(p);
        std::cout << p.source << " " << p.translation << std::endl;
    }
    f.close();
}

int main()
{
    std::vector<TranslationPair> words;
    std::vector<TranslationPair> sentences;
    // for simplicity, assume the file consists of an expression on one line
    // followed by a line with its translation
    populateFromFile("words.txt", words);
    populateFromFile("sentences.txt", sentences);
    TestGenerator tg(words, sentences);
    Test* t = tg.generateTest(3);
    double score = t->test();
    std::cout << "Average score: " << score << std::endl;
    return 0;
}
