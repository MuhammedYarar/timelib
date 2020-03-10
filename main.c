/**
 *Calculates the day of the year, which you enter using the date
 *
 *Author: Muhammed Yarar
 *Date: 11.02.2020
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    struct date date_input;
    date_input.day = 0;
    date_input.month = 0;
    date_input.year = 0;
    date_input=input_date();
    printf("Tag des Jahres: %i\n", day_of_the_year(date_input));
    return 0;
}
