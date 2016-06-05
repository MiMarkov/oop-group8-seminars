#include "Calendar.h"
#include "Event.h"
#include "WeeklyEvent.h"

void Calendar::init(const Calendar& other) {
    m_name = other.m_name;
    m_events = other.m_events;
    for (unsigned int i = 0; i < m_events.size(); i++) {
        // copy the events so that they are not shared
        // between the calendars
        m_events[i] = new Event(*m_events[i]);
    }
}

void Calendar::destroy() {
    // delete all events that we have created using new
    for (unsigned int i = 0; i < m_events.size(); i++) {
        delete m_events[i];
    }
}

Calendar::Calendar(std::string name="<Default Calendar>"): m_name(name) {
    // empty implementation
    // events is automatically initialized
    // using its default constructor
}

Calendar::Calendar(const Calendar& other) {
    init(other);
}

Calendar::~Calendar()
{
    destroy();
}

Calendar& Calendar::operator=(const Calendar& other) {
    if (this != &other) {
        destroy();
        init(other);
    }
    return *this;
}

Calendar& Calendar::operator+=(const Calendar& other)
{
    Event* e;
    for(unsigned int i=0;i<other.m_events.size();i++)
    {
        e=new Event(*(other.m_events[i]));
        m_events.push_back(e);
    }
    return *this;
}

std::string Calendar::getName() const{
    return m_name;
}

void Calendar::rename(const std::string& newName) {
    m_name = newName;
}

bool Calendar::isFree(const Date& date, int hour) const {
    for (unsigned int i = 0; i < m_events.size(); i++) {
        if (m_events[i]->isInProgress(date, hour)) {
            return false;
        }
    }
    return true;
}

void Calendar::addEvent(const Date& date, int start, int end, std::string title, std::string descr, std::string place) {
    Event* e = new Event(date, start, end, title, descr, place);
    m_events.push_back(e);
}

void Calendar::addEvent(const Event& event)
{
    Event* e=new Event(event);
    m_events.push_back(e);
}

void Calendar::addWeeklyEvent(const Date& date, int start, int end, int numReps,
                        std::string title, std::string descr, std::string place) {
    Event* we = new WeeklyEvent(date, start, end, numReps, title, descr,place);
    m_events.push_back(we);
}

/*
bool cancelEvent(const Event& event);
bool cancelEvents(const Date& date);
*/

std::ostream& operator<< (std::ostream& out, const Calendar& cal) {
    out <<"Calendar: " << cal.m_name << std::endl;
    out << "Events:" << std::endl;
    for (unsigned i = 0; i < cal.m_events.size(); i++) {
        out << *cal.m_events[i] ;//<< std::endl;
    }
    return out;
}

bool Calendar::hasEventAt(std::string place, const Date& date, int hour) const
{
    for(unsigned int i=0;i<m_events.size();i++)
    {
        if(m_events[i]->isHappeningAt(place,date,hour))
            return true;
    }
    return false;
}

Event Calendar::earliestEvent() const
{
    Event earliest=*m_events[0];
    for (unsigned int i=1;i<m_events.size();i++)
        if(earliest>*(m_events[i]))
            earliest=*m_events[i];
    return earliest;
}

int Calendar::timeSpentInCentury(int century) const
{
    int time=0;
    for(int i=0;i<m_events.size();i++)
        if(m_events[i]->getCentury()==century)
        {
            time+=m_events[i]->eventLength();
        }
    return time;
}

int Calendar::numEvents() const
{
    return m_events.size();
}
