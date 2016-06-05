#include "MostTimeIn15Century.h"

MostTimeIn15Century::MostTimeIn15Century()
{
}

MostTimeIn15Century::MostTimeIn15Century(const Date &date,std::string place)
        :Competition(date,place)
{
}

MostTimeIn15Century::~MostTimeIn15Century()
{
}

TimeLord& MostTimeIn15Century::winner() const
{
    int index=0;
    int mostTime=m_participants[index]->timeSpentInCentury(15);
    for(unsigned int i=1;i<m_participants.size();i++)
    {
        if(mostTime<m_participants[i]->timeSpentInCentury(15))
        {
            index=i;
            mostTime=m_participants[i]->timeSpentInCentury(15);
        }
    }
    return *m_participants[index];
}
