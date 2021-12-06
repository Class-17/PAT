/*
1061 Dating (20point(s))

Code Size Limit 16 KB   Time Limit 200 ms  Memory Limit 64 MB

Sherlock Holmes received a note with some strange strings: Let's date! 3485djDkxh4hhGE 
2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm. It took him only a minute to figure out that those 
strange strings are actually referring to the coded time Thursday 14:04 -- since the first common 
capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D,
representing the 4th day in a week; the second common character is the 5th capital letter E, 
representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers 
from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by 
the last two strings is s at the 4th position, representing the 4th minute. Now given two pairs of 
strings, you are supposed to help Sherlock decode the dating time.

Input Specification:
Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 
characters without white space in 4 lines.

Output Specification:
For each test case, print the decoded time in one line, in the format DAY HH:MM, where DAY 
is a 3-character abbreviation for the days in a week -- that is, MON for Monday, TUE for Tuesday, 
WED for Wednesday, THU for Thursday, FRI for Friday, SAT for Saturday, and SUN for Sunday. It is 
guaranteed that the result is unique for each case.

Sample Input:

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm

Sample Output:

THU 14:04

*/

#include<cstdio>
int main()
{
    char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    char s[4][61];
    scanf("%s %s %s %s", s[0], s[1], s[2], s[3]);
    for(int i = 0, count = 0; s[0][i] != '\0'; i++)
    {
        if(count == 1 && s[0][i] == s[1][i] &&((s[0][i] >= 'A' && s[0][i] <= 'N') || (s[0][i] >= '0' && s[0][i] <= '9')))
        {
            if(s[0][i] >= 'A' && s[0][i] <= 'N')
                printf("%02d:", s[0][i] - 'A' + 10);
            else
                printf("%02d:", s[0][i] - '0');   
            break;
        }
        if(count == 0 && s[0][i] == s[1][i] && s[0][i] >= 'A' && s[0][i] <= 'G')
        {
            printf("%s ", week[s[0][i] - 'A']);
            count = 1;
        }
    }
    for(int i = 0; s[2][i] != '\0'; i++)
    {
        if(s[2][i] == s[3][i] && ((s[2][i] >= 'A' && s[3][i] <= 'Z') || (s[2][i] >= 'a' && s[3][i] <= 'z')))
        {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}