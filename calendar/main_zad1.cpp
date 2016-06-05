#include <iostream>
#include "Event.h"
#include "WeeklyEvent.h"
#include "Calendar.h"
#include "Date.h"
#include "TimeLord.h"

int main()
{
    TimeLord lord("Arthur");
    lord.newCalendar("Cal1");

    Event event1(Date(2019, 6, 17), 2, 8, "First Event", "Sleeping time!","Home");
    Event event2(Date(1804, 7, 12), 8, 13, "Second Event", "Party time!","Carnaval");
    Event event3(Date(1887, 10, 16), 18, 20, "Third Event", "Disco time!","Cotton");
    Event event4(Date(1797, 6, 2), 1, 3, "Fourth Event", "Homework time!","Home");
    Event event5(Date(2016, 5, 1), 7, 19, "Fifth Event", "Study time!","FMI");
    Event event6(Date(1841, 11, 30), 1, 23, "Sixth Event", "Reading time!","Library");

    lord.newEvent(event1);
    lord.newEvent(event2);
    lord.newEvent(event3);

    lord.newCalendar("Cal2");

    lord.newEvent(event4);
    lord.newEvent(event5);
    lord.newEvent(event6);

    std::cout<<"Time spent in 19 century: "<<lord.timeSpentInCentury(19)<<std::endl;
    std::cout<<"Number of events: "<<lord.numEvents()<<std::endl;
    std::cout<<lord.allArchives()<<std::endl;
    std::string place="FMI";

    if(lord.canVisit(place,Date(2016,05,01),10))
        std::cout<<"Yes he can visit FMI on 2016/05/01 at 10 am!"<<std::endl;
    else
        std::cout<<"He cannot visit FMI on 2016/05/01 at 10 am!"<<std::endl;

    std::cout<<lord.earliestVisitedEvent()<<std::endl;
    return 0;
}
