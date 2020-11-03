//
// Created by mim on 31/10/20.
//

#ifndef AEDA2020_PORTAGENS_DATE_H
#define AEDA2020_PORTAGENS_DATE_H

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
    Date(string& date); //"day/month/year hour:minute:second"
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    string getInfo() const;
    int setYear(const int new_year);
    int setMonth(const int new_month);
    int setDay(const int new_day);
    int setHour(const int new_hour);
    int setMinute(const int new_minute);
    int setSecond(const int new_second);
};


#endif //AEDA2020_PORTAGENS_DATE_H
