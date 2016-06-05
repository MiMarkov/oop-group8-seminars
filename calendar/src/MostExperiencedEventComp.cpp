#include "MostExperiencedEventComp.h"

MostExperiencedEventComp::MostExperiencedEventComp()
{
}

MostExperiencedEventComp::MostExperiencedEventComp(const Date &date,std::string place)
        :Competition(date,place)
{
}

MostExperiencedEventComp::~MostExperiencedEventComp()
{
}

TimeLord& MostExperiencedEventComp::winner() const
{
    int index=0;
    int mostEvents=m_participants[index]->numEvents();
    for(unsigned int i=1;i<m_participants.size();i++)
    {
        if(mostEvents<m_participants[i]->numEvents())
        {
            index=i;
            mostEvents=m_participants[i]->numEvents();
        }
    }
    return *m_participants[index];
}
