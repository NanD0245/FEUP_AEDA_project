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
    int getYear() const {return year;}
    int getMonth() const {return month;}
    int getDay() const {return day;}
    int getHour() const {return hour;}
    int getMinute() const {return minute;}
    int getSecond() const {return second;}
    string getInfo() const {return s_date;}
};


#endif //AEDA2020_PORTAGENS_DATE_H
