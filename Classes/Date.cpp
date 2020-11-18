//
// Created by mim on 31/10/20.
//

#include "Date.h"

using namespace std;

/*!
 * @brief Constructor of date class, initializes date to be equal to the string provided
 * @arg date string that provides the date in the following format: "day/month/year hour:minute:second"
 */
Date::Date(string date) : s_date(date) { //"day/month/year hour:minute:second"
    int count = 0;
    while (count != 6) {
        int index;
        string s;
        for (int i = 0; i < date.length(); i++) {
            if (date[i] == '/' || date[i] == ':') {
                s = date.substr(0,i);
                date.erase(0,i+1);
                break;
            }
            else if (date[i] == ' ') {
                s = date.substr(0,i);
                date.erase(0,i+1);
                break;
            }
            if (i == date.length()-1)
                s = date;
        }
        switch (count) {
            case 0:
                day = stoi(s, nullptr);
                count++;
                break;
            case 1:
                month = stoi(s, nullptr);
                count++;
                break;
            case 2:
                year = stoi(s, nullptr);
                count++;
                break;
            case 3:
                hour = stoi(s, nullptr);
                count++;
                break;
            case 4:
                minute = stoi(s, nullptr);
                count++;
                break;
            case 5:
                second = stoi(s, nullptr);
                count++;
                break;
        }
    }
}


int Date::getYear() const {return year;}

int Date::getMonth() const {return month;}

int Date::getDay() const {return day;}

int Date::getHour() const {return hour;}

int Date::getMinute() const {return minute;}

int Date::getSecond() const {return second;}

/*!
 * @return current info - info is the string provided when one initializes the constructor
 * info has the following format: "day/month/year hour:minute:second"
 */
string Date::getInfo() const {return s_date;}

void Date::setYear(const int new_year) { year = new_year; }

void Date::setMonth(const int new_month) { month = new_month; }

void Date::setDay(const int new_day) { day = new_day; }

void Date::setHour(const int new_hour) { hour = new_hour; }

void Date::setMinute(const int new_minute) { minute = new_minute; }

void Date::setSecond(const int new_second) { second = new_second; }

/**
 * @brief Overloads the '==' operator to be able to know if two different dates are the same
 * @arg d1 Object of class Date to compare the current object to
 * @return true if the year, month and day are the same on both objects, false otherwise
 */
bool Date::operator==(Date d1) const {
    return year == d1.getYear() && month == d1.getMonth() && day == d1.getDay();
}

/**
 * @brief overloads the '>' operator to be able to know if one date is after the other
 * @arg d1 Object of class Date to compare the current object to
 * @return true if current date is after date of object d1, false otherwise
 */
bool Date::operator>(Date d1) const {
    if (year > d1.getYear())
        return true;
    else if (year == d1.getYear()) {
        if (month > d1.getMonth())
            return true;
        else if (month == d1.getMonth()) {
            if (day > d1.getDay())
                return true;
            else if (day == d1.getDay()){
                if (hour > d1.getHour())
                    return true;
                else if (hour == d1.getHour()) {
                    if (minute > d1.getMinute()) {
                        return true;
                    }
                    else if (minute == d1.getMinute())
                        if (second >= d1.getSecond())
                            return true;
                }
            }
        }
    }
    return false;
}