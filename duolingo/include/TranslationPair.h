#ifndef TRANSLATIONPAIR_H
#define TRANSLATIONPAIR_H

#include <string>
#include <istream>

struct TranslationPair
{
    std::string source;
    std::string translation;
    friend std::istream& operator>> (std::istream& in, TranslationPair& p) {
        std::getline(in, p.source);
        std::getline(in, p.translation);
        return in;
    }
};

#endif // TRANSLATIONPAIR_H
