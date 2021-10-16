#include <stdio.h>
int main()
{
    double f1, f2; int i; char c;
    scanf("%lf %d %c %lf", &f1, &i, &c, &f2);
    printf("%c %d %.2f %.2f\n", c, i, f1, f2);
    return 0;
}