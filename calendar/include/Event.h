#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <string>
#include "Date.h"
class Event
{
    public:
        Event(const Date&, int, int,
             std::string title = "<Untitled Event>", std::string description= "",std::string place="");
        virtual ~Event();
        virtual bool isInProgress(const Date&, int) const;
        bool isHappeningAt(std::string ,const Date& , int) const;
        friend std::ostream& operator<< (std::ostream&, const Event&);
        friend std::istream& operator>> (std::istream&, Event&);
        friend bool operator<(const Event&, const Event&);
        friend bool operator>(const Event&, const Event&);
        Event& operator=(const Event&);
        int getCentury() const;
        int eventLength() const;
    protected:
        Date m_date;
        int m_startHour;
        int m_endHour;
        std::string m_title;
        std::string m_description;
        std::string m_place;
        virtual std::ostream& write(std::ostream& out) const;
};

#endif // EVENT_H_INCLUDED
