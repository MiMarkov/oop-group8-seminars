#ifndef MOSTTIMEIN15CENTURY_H
#define MOSTTIMEIN15CENTURY_H

#include "Competition.h"

class MostTimeIn15Century: public Competition
{
    public:
        MostTimeIn15Century();
        MostTimeIn15Century(const Date&,std::string);
        ~MostTimeIn15Century();
        TimeLord& winner() const;
    protected:
    private:
};

#endif // MOSTTIMEIN15CENTURY_H
