#include "Event.h"
#include <string>
#include <iostream>
Event::Event(const Date& date, int start, int end,
              std::string title, std::string description,std::string place)
                :m_date(date),m_startHour(start),m_endHour(end), m_title(title),m_description(description),m_place(place)
{ }

Event::~Event () {}

bool Event::isInProgress(const Date& when, int hour) const {
    return m_date == when && hour >= m_startHour && hour < m_endHour;
}

std::ostream& Event::write(std::ostream& out) const {
    out << m_title << "@" << m_date <<
        " (from " << m_startHour << "h to " << m_endHour << "h)" << " in " <<m_place << std::endl;
    out << m_description << std::endl;
    return out;
}

std::ostream& operator<< (std::ostream& out, const Event& e) {
    return e.write(out);
}

std::istream& operator>> (std::istream& in, Event& e) {
    in >> e.m_title;
    in >> e.m_date;
    in >> e.m_startHour >> e.m_endHour;
    in >> e.m_description;
    in >> e.m_place;
    return in;
}

bool Event::isHappeningAt(std::string place,const Date& date, int hour) const
{
    if((m_date==date&&hour>=m_startHour&&hour<=m_endHour)||(m_date==date&&hour==-1))
        if(m_place==""||m_place==place)
            return true;
    return false;
}

bool operator<(const Event& d1, const Event& d2)
{
    if(d1.m_date<d2.m_date)
        return true;
    else if(d1.m_date==d2.m_date)
        return d1.m_endHour<d2.m_endHour;
    return false;
}

bool operator>(const Event& d1, const Event& d2)
{
    if(d1.m_date>d2.m_date)
        return true;
    else if(d1.m_date==d2.m_date)
        return d1.m_endHour>d2.m_endHour;
    return false;
}

Event& Event::operator=(const Event& source)
{
    m_date=source.m_date;
    m_startHour=source.m_startHour;
    m_endHour=source.m_endHour;
    m_title=source.m_title;
    m_description=source.m_description;
    m_place=source.m_place;
    return *this;
}

int Event::getCentury() const
{
    return m_date.getYear()/100+1;
}

int Event::eventLength() const
{
    return m_endHour-m_startHour;
}
