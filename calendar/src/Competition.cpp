#include "Competition.h"

Competition::Competition()
{
}

Competition::Competition(const Date &date,std::string place)
        :m_date(date),m_place(place)
{
}

Competition::~Competition()
{
    for(unsigned int i=0;i<m_participants.size();i++)
    {
        delete m_participants[i];
    }
}

bool Competition::registerComp(TimeLord& lord)
{
    if(lord.canVisit(m_place,m_date))
    {
        TimeLord *newLord=new TimeLord(lord);
        m_participants.push_back(newLord);
        return true;
    }
    return false;
}

int Competition::numParticipants() const
{
    return m_participants.size();
}

void Competition::print() const
{
    std::cout<<"Competition @ "<<m_place<<" on "<<m_date<<std::endl;
    for(unsigned int i=0;i<m_participants.size();i++)
    {
        std::cout<<"Participant No"<<i+1<<":"<<std::endl<<*m_participants[i];
    }
}

TimeLord& Competition::winner() const
{
    srand(time(nullptr));
    int winner=rand()%m_participants.size();
    return *m_participants[winner];
}
