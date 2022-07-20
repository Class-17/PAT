/*
1001 A+B Format (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Calculate a+b and output the sum in standard format -- that is, the digits
must be separated into groups of three by commas (unless there are less 
than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integer 
a and b where −10^6≤a,b≤10^6​. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.

Sample Input:

-1000000 9

Sample Output:

-999,991

*/


// Method A: String processing
#include<cstdio>
int main()
{
    int a, b, count = 0, i = 0;
    scanf("%d %d", &a, &b);
    a += b;
    if(a < 0)       {printf("-"); a *= -1;}
    else if(a == 0) {printf("0"); return 0;}
    char num[15];
    while (a > 0)
    {
        if(count % 3 == 0 && count != 0) num[i++] = ',';
        num[i++] = a % 10 + '0';
        count++;
        a /= 10;
    }
    for(i -= 1; i >= 0; i--)
        printf("%c", num[i]); 
    return 0;
}

/*  Method B： Finding the output pattern
#include<cstdio>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    a += b;
    if(a < 0) {printf("-"); a *= -1;}
    if(a >= 1000000)    printf("%d,%03d,%03d\n", a / 1000000, a % 1000000 / 1000, a % 1000);
    else if(a >= 1000)  printf("%d,%03d\n", a / 1000, a % 1000);
    else                printf("%d\n",a);
    return 0;
}
*/