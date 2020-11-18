//
// Created by mim on 31/10/20.
//

#ifndef AEDA2020_PORTAGENS_DATE_H
#define AEDA2020_PORTAGENS_DATE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * The Date class is a class that provides a date that can
 * be used and/or compared to other dates
 *
 * When initialized, the user inputs a string in the format
 * "day/month/year hour:minute:second" that is then converted to
 * corresponding variables that will be used later on.
 *
 * @param s_date corresponds to the string inputted by the user when they initialize
 * the Date class and is in the format referred above
 */
class Date {
    string s_date;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    Date(string date);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    string getInfo() const;
    void setYear(const int new_year);
    void setMonth(const int new_month);
    void setDay(const int new_day);
    void setHour(const int new_hour);
    void setMinute(const int new_minute);
    void setSecond(const int new_second);
    bool operator==(Date d1) const;
    bool operator>(Date d1) const;
};


#endif //AEDA2020_PORTAGENS_DATE_H
