#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

void input_date(struct date *date)
{
    do {
        printf("Bitte das Datum eingeben an dem der Tag des Jahres ausgerechnet werden soll!\n");
        printf("Tag: ");
        scanf("%i", &(*date).day);
        fflush(stdin);
        printf("Monat: ");
        scanf("%i", &(*date).month);
        fflush(stdin);
        printf("Year: ");
        scanf("%i", &(*date).year);
        fflush(stdin);
    } while(!exists_date((*date).day, (*date).month, (*date).year));
}

/** \brief is_leapyear überprüft ob der übergebene parameter ein
 *  ein Schaltjahr ist.
 * \param year
 *
 * \return 1 = true, 0 = false, -1 = false input
 *
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

/** \brief gibt die Tage für den Monat aus für den Monat und das Jahr
 *
 * \param month
 * \param year
 * \return days_in_month or -1 if false
 *
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

/** \brief überprüft ob das Datum richtig ist
 *
 * \param day
 * \param month
 * \param year
 * \return 0 = false oder 1 = true
 *
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

/** \brief errechnet den Tag des Jahres
 *
 * \param date.day
 * \param date.month
 * \param date.year
 * \return 0 = false day = anzahl der Tage
 *
 */

int day_of_the_year(struct date date)
{
    int i = 0;
    if(exists_date(date.day,date.month,date.year))
    {
        for(i = 0; i < date.month - 1; i++)
        {
            date.day += get_days_for_month(i, date.year);
        }
        return date.day;
    }
    return 0;
}
