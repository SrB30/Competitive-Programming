#include <stdio.h>

int main()
{
    int i=0, check, mod4, mod100, mod400, mod15, mod55, leap;
    char year;

    while (++i)
    {
        leap= check= mod4= mod100= mod400= mod15= mod55= 0;

        while(1)
        {
            if (scanf("%c", &year) == EOF)
                return 0;

            if (year == '\n')
                break;

            mod4 = ((mod4*10) + (year-48)) % 4;
            mod100 = ((mod100*10) + (year-48)) % 100;
            mod400 = ((mod400*10) + (year-48)) % 400;
            mod15 = ((mod15*10) + (year-48)) % 15;
            mod55 = ((mod55*10) + (year-48)) % 55;
        }
        if (i !=1)
            printf("\n");

        if ((mod4 == 0 && mod100 != 0) || mod400 == 0)
        {
            printf("This is leap year.\n");
            check = 1;
            leap=1;
        }

        if (mod15 == 0)
        {
            printf("This is huluculu festival year.\n");
            check = 1;
        }

        if (leap == 1 && mod55 == 0)
        {
            printf("This is bulukulu festival year.\n");
            check = 1;
        }

        if (check == 0)
            printf("This is an ordinary year.\n");
    }

    return 0;
}
