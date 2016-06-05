#ifndef TIMELORD_H
#define TIMELORD_H

#include <vector>
#include <string>
#include "Event.h"
#include "Date.h"
#include "Calendar.h"

class TimeLord
{
    public:
        TimeLord(std::string name="<New_TimeLord>");
        TimeLord(const TimeLord &other);
        TimeLord& operator=(const TimeLord &other);
        ~TimeLord();
        void newCalendar(std::string);
        void newEvent(const Event&);
        Calendar allArchives() const;
        std::string getName();
        bool canVisit(std::string place,const Date &date, int hour=-1) const;
        int numEvents() const;
        Event earliestVisitedEvent() const;
        int timeSpentInCentury(int century) const;
        friend std::ostream& operator<<(std::ostream&, const TimeLord&);
    private:
        std::string m_name;
        std::vector <Calendar*> m_calendars;
        void destroy();
        void init(const TimeLord &other);
};

#endif // TIMELORD_H
