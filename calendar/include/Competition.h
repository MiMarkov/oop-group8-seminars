#ifndef COMPETITION_H
#define COMPETITION_H

#include "TimeLord.h"
#include <time.h>
#include <cstdlib>

class Competition
{
    public:
        Competition();
        Competition(const Date &date,std::string place);
        virtual ~Competition();
        bool registerComp(TimeLord&);
        int numParticipants() const;
        void print() const;
        virtual TimeLord& winner() const;
    private:
    protected:
        Date m_date;
        std::string m_place;
        std::vector <TimeLord*> m_participants;
};

#endif // COMPETITION_H
