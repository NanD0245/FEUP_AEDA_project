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
    /**
     * @brief Constructor of date class, initializes date to be equal to the string provided
     * @arg date string that provides the date in the following format: "day/month/year hour:minute:second"
     */
    Date(string date);

    /**
     * @return object's year
     */
    int getYear() const;

    /**
     * @return object's month
     */
    int getMonth() const;

    /**
     * @return object's day
     */
    int getDay() const;

    /**
     * @return object's hour
     */
    int getHour() const;

    /**
     * @return object's minute
     */
    int getMinute() const;

    /**
     * @return object's second
     */
    int getSecond() const;

    /**
     * @return current info - info is the string provided when one initializes the constructor
     * info has the following format: "day/month/year hour:minute:second"
     */
    string getInfo() const;

    /**
     * @brief Overloads the '==' operator to be able to know if two different dates are the same
     * @arg d1 Object of class Date to compare the current object to
     * @return true if the year, month and day are the same on both objects, false otherwise
     */
    bool operator==(Date d1) const;

    /**
     * @brief overloads the '>' operator to be able to know if one date is after the other
     * @arg d1 Object of class Date to compare the current object to
     * @return true if current date is after date of object d1, false otherwise
     */
    bool operator>(Date d1) const;
};


#endif //AEDA2020_PORTAGENS_DATE_H
