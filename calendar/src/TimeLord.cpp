#include "TimeLord.h"

TimeLord::TimeLord(std::string name) :m_name(name)
{
}

TimeLord::TimeLord(const TimeLord &other)
{
    init(other);
}

TimeLord& TimeLord::operator=(const TimeLord &other)
{
    if(this!=&other)
    {
        destroy();
        init(other);
    }
    return *this;
}

TimeLord::~TimeLord()
{
    destroy();
}

std::string TimeLord::getName()
{
    return m_name;
}

void TimeLord::init(const TimeLord &other)
{
    m_name=other.m_name;
    m_calendars=other.m_calendars;
    for(unsigned int i=0;i<m_calendars.size();i++)
    {
        m_calendars[i]=new Calendar(*m_calendars[i]);
    }
}

void TimeLord::destroy()
{
    for(unsigned int i=0;i<m_calendars.size();i++)
        delete m_calendars[i];
}

void TimeLord::newCalendar(std::string name="<Default_Calendar>")
{
    Calendar *c=new Calendar(name);
    m_calendars.push_back(c);
}

void TimeLord::newEvent(const Event& event)
{
    if(m_calendars.empty())
        newCalendar();
    (m_calendars.back())->addEvent(event);
}

Calendar TimeLord::allArchives() const
{
    //This function causes memory leak.
    //Can be solved by keeping track of all the calenders
    //created by the function in a private member vector
    //and freeing the memory in in the destructor.
    //Other way is to return pointer to calendar and hoping
    //that the user will take care of deleting it.
    Calendar *newCal=new Calendar("<Complete_Calender>");
    for(unsigned int i=0;i<m_calendars.size();i++)
    {
        *newCal+=*m_calendars[i];
    }
    return *newCal;
}

bool TimeLord::canVisit(std::string place,const Date &date, int hour) const
{
    for(unsigned int i=0;i<m_calendars.size();i++)
    {
        if(m_calendars[i]->hasEventAt(place,date,hour))
            return false;
    }
    return true;
}

int TimeLord::numEvents() const
{
    int events=0;
    for(unsigned int i=0;i<m_calendars.size();i++)
        events+=m_calendars[i]->numEvents();
    return events;
}

Event TimeLord::earliestVisitedEvent() const
{
    Event early=m_calendars[0]->earliestEvent();
    for(unsigned int i=1;i<m_calendars.size();i++)
    {
        if(early>m_calendars[i]->earliestEvent())
            early=m_calendars[i]->earliestEvent();
    }
    return early;
}

int TimeLord::timeSpentInCentury(int century) const
{
    int time=0;
    for(unsigned int i=0;i<m_calendars.size();i++)
        time+=m_calendars[i]->timeSpentInCentury(century);
    return time;
}

std::ostream& operator<<(std::ostream& out, const TimeLord& lord)
{
    out<<"Name: "<<lord.m_name<<std::endl
                 <<"Has been to: "<<std::endl;
    for(unsigned int i=0;i<lord.m_calendars.size();i++)
        out<<*lord.m_calendars[i]<<std::endl;
    return out;
}
