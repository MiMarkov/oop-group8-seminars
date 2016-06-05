#ifndef CALENDAR_H_INCLUDED
#define CALENDAR_H_INCLUDED

#include <vector>
#include <string>
#include "Event.h"
#include "Date.h"

class Calendar
{
    public:
        Calendar(std::string name);
        Calendar(const Calendar& other);
        Calendar& operator=(const Calendar& other);
        Calendar& operator+=(const Calendar& other);
        ~Calendar();
        std::string getName() const;
        void rename(const std::string&);
        void addEvent(const Date&, int, int, std::string="Event", std::string="", std::string="");
        void addEvent(const Event&);
        void addWeeklyEvent(const Date&, int, int, int, std::string="Weekly Event", std::string="", std::string="");
        bool isFree (const Date&, int) const;
        bool hasEventAt(std::string, const Date&, int) const;
        friend std::ostream& operator<< (std::ostream&, const Calendar&);
        Event earliestEvent() const;
        int timeSpentInCentury(int century) const;
        int numEvents() const;
    protected:
    private:
        std::string m_name;
        std::vector<Event*> m_events;
        void init(const Calendar& other);
        void destroy();
};

#endif // CALENDAR_H_INCLUDED
