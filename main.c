/**
 *das Programm rechnet den Tag des Jahres aus für das jeweilige eingegebene Datum
 *
 *Author: Kerem Koc und Muhammed Yarar
 *Datum: 11.02.2020
 **/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day = 0;
    int month = 0;
    int year = 0;
    input_date(&day, &month, &year);
    printf("Tag des Jahres: %i\n", day_of_the_year(*day, *month, *year));
    return 0;
}
