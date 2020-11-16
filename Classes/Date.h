//
// Created by mim on 31/10/20.
//

#ifndef AEDA2020_PORTAGENS_DATE_H
#define AEDA2020_PORTAGENS_DATE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Date {
    string s_date;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    Date(string date); //"day/month/year hour:minute:second"
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
