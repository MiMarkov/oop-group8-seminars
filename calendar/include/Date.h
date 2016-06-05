#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
class Date
{
    public:
        Date(int year=1970, int month=1, int day=1);
        bool operator== (const Date&) const;
        bool operator!= (const Date&) const;
        bool operator< (const Date&) const;
        bool operator<= (const Date&) const;
        bool operator> (const Date&) const;
        bool operator>= (const Date&) const;
        Date& operator++();
        Date operator++(int);
        Date operator+ (int) const;
        int dayOfWeek() const;
        bool isLastDayOfMonth () const;
        bool isLastMonthOfYear () const;
        bool isLeapYear() const;
        friend std::ostream& operator<< (std::ostream&, const Date&);
        friend std::istream& operator>> (std::istream&, Date&);
        Date& operator=(const Date&);
        int getYear() const;
    protected:
    private:
        int m_year;
        int m_month;
        int m_day;
};

#endif // DATE_H_INCLUDED
