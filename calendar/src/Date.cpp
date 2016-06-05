#include "Date.h"
#include <iostream>

Date::Date(int year, int month, int day): m_year(year),m_month(month),m_day(day)
{
    // empty - all work is done in the initializer list
}

int Date::dayOfWeek() const {
    int y = this->m_year;
    int m = this->m_month;
    int d = this->m_day;
    // formula taken from Wikipedia
    // returns 0 for Sunday, 1 for Monday, ..., 6 for Saturday
    // https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Implementation-dependent_methods
    return (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400) % 7;
}

bool Date::isLeapYear() const {
    return (m_year % 100 != 0 && m_year % 4 == 0) || m_year % 400 == 0;
}

bool Date::isLastDayOfMonth() const {
    switch (m_month) {
    case 4:
    case 6:
    case 9:
    case 11:
        return m_day == 30;
    case 2:
        if (isLeapYear()) {
            return m_day == 29;
        } else {
            return m_day == 28;
        }
    default:
        // all other months have 31 days
        return m_day == 31;
    }
}

bool Date::isLastMonthOfYear() const {
    return m_month == 12;
}

bool Date::operator==(const Date& other) const {
    return m_year == other.m_year &&
            m_month == other.m_month &&
            m_day == other.m_day;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator< (const Date& other) const {
    if (m_year > other.m_year) {
        return false;
    }
    if (m_year == other.m_year &&
        (m_month > other.m_month || (m_month == other.m_month && m_day >= other.m_day))) {
        return false;
    }
    return true;
}

bool Date::operator<= (const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator> (const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>= (const Date& other) const {
    return !(*this < other);
}

// prefix operator ++date
Date& Date::operator++() {
    if (!isLastDayOfMonth()) {
        m_day++;
    } else {
        m_day = 1;
        if (!isLastMonthOfYear()) {
            m_month++;
        } else {
            m_month = 1;
            m_year++;
        }
    }
    return *this;
}

// postfix operator date++
Date Date::operator++(int dummy) {
    Date old(*this);
    ++*this;
    return old;
}

Date Date::operator+(int days) const {
    Date result(*this);
    while (days) {
        ++result;
        --days;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.m_year << "-" << date.m_month << "-" << date.m_day;
    // return the same stream to enable chaining
    return out;
}

std::istream& operator>> (std::istream& in, Date& date) {
    in >> date.m_year >> date.m_month >> date.m_day;
    // return the same stream to enable chaining
    return in;
}

Date& Date::operator=(const Date& source)
{
    m_year=source.m_year;
    m_month=source.m_month;
    m_day=source.m_day;
    return *this;
}

int Date::getYear() const
{
    return m_year;
}
