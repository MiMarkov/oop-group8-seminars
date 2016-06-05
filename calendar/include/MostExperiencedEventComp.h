#ifndef MOSTEXPERIENCEDEVENTCOMP_H
#define MOSTEXPERIENCEDEVENTCOMP_H

#include "Competition.h"

class MostExperiencedEventComp: public Competition
{
    public:
        MostExperiencedEventComp();
        MostExperiencedEventComp(const Date&,std::string);
        ~MostExperiencedEventComp();
        TimeLord& winner() const;
    protected:
    private:
};

#endif // MOSTEXPERIENCEDEVENTCOMP_H
