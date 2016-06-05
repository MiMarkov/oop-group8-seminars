#include "EarliestEventComp.h"

EarliestEventComp::EarliestEventComp()
{
}

EarliestEventComp::EarliestEventComp(const Date &date,std::string place)
        :Competition(date,place)
{
}

EarliestEventComp::~EarliestEventComp()
{
}

TimeLord& EarliestEventComp::winner() const
{
    int index=0;
    Event earliest=m_participants[index]->earliestVisitedEvent();
    for(unsigned int i=1;i<m_participants.size();i++)
    {
        if(earliest>m_participants[i]->earliestVisitedEvent())
            {
                index=i;
                earliest=m_participants[i]->earliestVisitedEvent();
            }
    }
    return *m_participants[index];
}
