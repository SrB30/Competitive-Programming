#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1000];
    int n, time = 0, now;
    int hour, min, sec, speed=0, newSpeed;
    double distance=0;

    while (gets(buffer))
    {
        n = sscanf(buffer, "%d:%d:%d %d", &hour, &min, &sec, &newSpeed);
        now = hour * 3600 + min * 60 + sec;

        distance += (now - time) * speed;
        time = now;

        if (n == 3)
            printf("%02d:%02d:%02d %.2lf km\n", hour, min, sec, distance/3600);
        else if (n == 4)
            speed = newSpeed;
    }

    return 0;
}
