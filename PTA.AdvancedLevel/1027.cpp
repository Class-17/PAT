/*
1027 Colors in Mars (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

People in Mars represent the colors in their computers in a similar way as
the Earth people. That is, a color is represented by a 6-digit number, where
the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 
digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) 
instead of 16. Now given a color in three decimal numbers (each between 0 and 168),
you are supposed to output their Mars RGB values.

Input Specification:
Each input file contains one test case which occupies a line containing the 
three decimal color values.

Output Specification:
For each test case you should output the Mars RGB value in the following format:
first output #, then followed by a 6-digit number where all the English 
characters must be upper-cased. If a single color is only 1-digit long, you must
print a 0 to its left.

Sample Input:

15 43 71

Sample Output:

#123456

*/

#include<cstdio>
int main()
{
    char radix[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    printf("#%c%c", radix[r / 13], radix[r % 13]);  
    printf("%c%c", radix[g / 13], radix[g % 13]);
    printf("%c%c\n", radix[b / 13], radix[b % 13]);
    return 0;
}