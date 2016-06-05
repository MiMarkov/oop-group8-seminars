#include "WeeklyEvent.h"

WeeklyEvent::WeeklyEvent(
     const Date& date, int start, int end, int numReps,
     std::string title, std::string description, std::string place)
     :Event(date, start, end, title, description,place), numRepetitions(numReps)
{ }

int WeeklyEvent::getNumRepetitions() const {
    return numRepetitions;
}
bool WeeklyEvent::isInProgress(const Date& when, int hour) const {
    return when >= this->m_date && when < this->m_date + 7 * this->numRepetitions &&
        when.dayOfWeek() == this->m_date.dayOfWeek() &&
        hour >= this->m_startHour && hour < this->m_endHour;
}

std::ostream& WeeklyEvent::write(std::ostream& out) const {
    // reuse the parent method
    // if we just try to call write(out), it will be a recursive call
    // to the function we are implementing
    // Event::write will specifically look for the parent implementation
    Event::write(out);
    out << "Will be repeated " << numRepetitions << " times." << std::endl;
    return out;
}
