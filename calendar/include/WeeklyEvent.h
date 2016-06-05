#ifndef WEEKLYEVENT_H_INCLUDED
#define WEEKLYEVENT_H_INCLUDED

#include "Event.h"


class WeeklyEvent : public Event
{
    private:
        int numRepetitions;
    public:
        WeeklyEvent(const Date&, int, int, int, std::string="<Repeating event>", std::string="",std::string="");
        int getNumRepetitions () const;
        bool isInProgress (const Date&, int) const;
    protected:
        std::ostream& write(std::ostream& out) const;
};

#endif // WEEKLYEVENT_H_INCLUDED
