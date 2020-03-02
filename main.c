/**
 *das Programm rechnet den Tag des Jahres aus für das jeweilige eingegebene Datum
 *
 *Author: Kerem Koc und Muhammed Yarar
 *Datum: 11.02.2020
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    struct date date;
    date.day = 0;
    date.month = 0;
    date.year = 0;
    input_date(&date);
    printf("Tag des Jahres: %i\n", day_of_the_year(date));
    return 0;
}
