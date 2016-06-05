#ifndef EARLIESTEVENTCOMP_H
#define EARLIESTEVENTCOMP_H

#include "Competition.h"

class EarliestEventComp: public Competition
{
    public:
        EarliestEventComp();
        EarliestEventComp(const Date &date,std::string place);
        ~EarliestEventComp();
        TimeLord& winner() const;
    protected:
    private:
};

#endif // EARLIESTEVENTCOMP_H
