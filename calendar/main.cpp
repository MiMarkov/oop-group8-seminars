#include <iostream>
#include <vector>
#include "Event.h"
#include "WeeklyEvent.h"
#include "Calendar.h"
#include "Date.h"
#include "TimeLord.h"
#include "Competition.h"
#include "EarliestEventComp.h"
#include "MostExperiencedEventComp.h"
#include "MostTimeIn15Century.h"

int main()
{
    //initializing TimeLords
    TimeLord lord1("Arthur");

    lord1.newCalendar("Cal1");
    Event event1(Date(2019, 6, 17), 2, 8, "First Event", "Sleeping time!","Home");
    Event event2(Date(1704, 7, 12), 8, 13, "Second Event", "Party time!","Carnaval");
    Event event3(Date(1887, 10, 16), 18, 20, "Third Event", "Disco time!","Cotton");
    Event event4(Date(1797, 6, 2), 1, 3, "Fourth Event", "Homework time!","Home");
    Event event5(Date(2016, 5, 1), 7, 19, "Fifth Event", "Study time!","FMI");
    Event event6(Date(1841, 11, 30), 1, 23, "Sixth Event", "Reading time!","Library");
    lord1.newEvent(event1);
    lord1.newEvent(event2);
    lord1.newEvent(event3);
    lord1.newCalendar("Cal2");
    lord1.newEvent(event4);
    lord1.newEvent(event5);
    lord1.newEvent(event6);

    TimeLord lord2("Dent");

    lord2.newCalendar("Cal1");
    event1 = Event(Date(2248, 4, 5), 1, 7, "First Event", "Sleeping time!","Home");
    event2 = Event(Date(1447, 7, 12), 5, 13, "Second Event", "Party time!","Carnaval");
    event3 = Event(Date(1445, 10, 16), 17, 21, "Third Event", "Disco time!","Cotton");
    event4 = Event(Date(1487, 6, 2), 9, 13, "Fourth Event", "Homework time!","Home");
    event5 = Event(Date(2157, 4, 17), 4, 19, "Fifth Event", "Study time!","FMI");
    lord2.newEvent(event1);
    lord2.newEvent(event2);
    lord2.newEvent(event3);
    lord2.newCalendar("Cal2");
    lord2.newEvent(event4);
    lord2.newEvent(event5);

    TimeLord lord3("John");

    lord3.newCalendar("Cal1");
    event1 = Event(Date(1214, 4, 5), 1, 7, "First Event", "Sleeping time!","Home");
    event2 = Event(Date(1997, 7, 12), 5, 13, "Second Event", "Party time!","Carnaval");
    event3 = Event(Date(1558, 10, 16), 17, 21, "Third Event", "Disco time!","Cotton");
    event4 = Event(Date(2417, 6, 2), 9, 13, "Fourth Event", "Homework time!","Home");
    lord3.newEvent(event1);
    lord3.newEvent(event2);
    lord3.newEvent(event3);
    lord3.newCalendar("Cal2");
    lord3.newEvent(event4);

    TimeLord lord4("Ivan");

    lord4.newCalendar("Cal1");
    event1 = Event(Date(1457, 4, 5), 1, 7, "First Event", "Sleeping time!","Home");
    event2 = Event(Date(1543, 7, 12), 5, 13, "Second Event", "Party time!","Carnaval");
    event3 = Event(Date(1687, 10, 16), 17, 21, "Third Event", "Disco time!","Cotton");
    event4 = Event(Date(1345, 6, 2), 9, 13, "Fourth Event", "Homework time!","Home");
    event5 = Event(Date(1957, 5, 1), 4, 19, "Fifth Event", "Study time!","FMI");
    event6 = Event(Date(1567, 11, 30), 5, 22, "Sixth Event", "Reading time!","Library");
    Event event7(Date(1612, 11, 30), 5, 22, "Seventh Event", "Traveling!","Time");
    lord4.newEvent(event1);
    lord4.newEvent(event2);
    lord4.newEvent(event3);
    lord4.newCalendar("Cal2");
    lord4.newEvent(event4);
    lord4.newEvent(event5);
    lord4.newEvent(event6);
    lord4.newEvent(event7);

    //initializing competition list
    std::vector <Competition*> compList;
    compList.reserve(4);

    Competition *c;

    c=new Competition(Date(1850,1,1),"FMI");
    compList.push_back(c);

    c=new EarliestEventComp(Date(1950,2,2),"Center");
    compList.push_back(c);

    c=new MostExperiencedEventComp(Date(2050,3,3),"Moon");
    compList.push_back(c);

    c=new MostTimeIn15Century(Date(2150,4,4),"Mars");
    compList.push_back(c);

    //adding participants
    compList[0]->registerComp(lord1);
    compList[0]->registerComp(lord2);
    compList[0]->registerComp(lord3);
    compList[0]->registerComp(lord4);

    compList[1]->registerComp(lord1);
    compList[1]->registerComp(lord2);
    compList[1]->registerComp(lord3);
    compList[1]->registerComp(lord4);

    compList[2]->registerComp(lord1);
    compList[2]->registerComp(lord2);
    compList[2]->registerComp(lord3);
    compList[2]->registerComp(lord4);

    compList[3]->registerComp(lord1);
    compList[3]->registerComp(lord2);
    compList[3]->registerComp(lord3);
    compList[3]->registerComp(lord4);

    //announcing winners of the competitions
    for(unsigned int i=0;i<compList.size();i++)
    {
        std::cout<<"Winner of competition No"<<i+1<<" is:"<<compList[i]->winner().getName()<<std::endl;
    }

    //freeing allocated memory
    for(unsigned int i=0;i<compList.size();i++)
        delete compList[i];
    return 0;
}
