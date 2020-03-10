#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/** \brief User enter the date
 * \param date_input.day
 * \param date_input.month
 * \param date_input.year
 * \return date_input
 */

struct date input_date()
{
    struct date date_input;
    do {
        printf("Bitte das Datum eingeben an dem der Tag des Jahres ausgerechnet werden soll!\n");
        printf("Tag: ");
        scanf("%i", &(date_input).day);
        fflush(stdin);
        printf("Monat: ");
        scanf("%i", &(date_input).month);
        fflush(stdin);
        printf("Year: ");
        scanf("%i", &(date_input).year);
        fflush(stdin);
    } while(!exists_date((date_input).day, (date_input).month, (date_input).year));
    return date_input;
}

/** \brief the function "is_leapyear" checks if the year is a leapyear
 * \param year
 * \return 1 = true, 0 = false, -1 = false input
 */

int is_leapyear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return -1;
}

/** \brief outputs the days for the month
 * \param month
 * \param year
 * \return days_in_month or -1 if false
 */

int get_days_for_month(int month, int year)
{
    month = month - 1;
    int days_in_Month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days = 0;
    if(month > 12 && month < 0 )
    {
        return -1;
    }

    if(is_leapyear(year) > 0)
    {
        days_in_Month[1] = 29;
        return days_in_Month[month];
    }

    return days_in_Month[month];
}

/** \brief checks if the date is correct
 * \param day
 * \param month
 * \param year
 * \return 0 = false or 1 = true
 */

int exists_date(int day, int month, int year)
{
    if(month > 12 && month < 1 )
    {
        return 0;
    }
    if(year < 1582 || year > 2400)
    {
        return 0;
    }
    if(day < 1 || day > get_days_for_month(month,year))
    {
        return 0;
    }
    return 1;
}

/** \brief calculates the day of the year
 * \param date_input.day
 * \param date_input.month
 * \param date_input.year
 * \return 0 = false day = number of days
 */

int day_of_the_year(struct date date_input)
{
    int i = 0;
    if(exists_date(date_input.day,date_input.month,date_input.year))
    {
        for(i = 0; i < date_input.month - 1; i++)
        {
            date_input.day += get_days_for_month(i, date_input.year);
        }
        return date_input.day;
    }
    return 0;
}
