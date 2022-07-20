#include<cstdio>
#include<cmath>
int main()
{
    int start, end, hours, minutes, seconds;
    scanf("%d %d", &start, &end);
    int result = (int)round((end - start) / 100.0);
    hours = result / 3600;
    minutes = result % 3600 / 60;
    seconds = result % 60;
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);  
    return 0;
}