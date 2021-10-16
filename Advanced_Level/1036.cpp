/*
1036 Boys vs Girls (25point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

This time you are asked to tell the difference between the lowest grade of all
 the male students and the highest grade of all the female students.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, 
followed by N lines of student information. Each line contains a student's name, 
gender, ID and grade, separated by a space, where name and ID are strings of no 
more than 10 characters with no space, gender is either F (female) or M (male), 
and grade is an integer between 0 and 100. It is guaranteed that all the grades 
are distinct.

Output Specification:
For each test case, output in 3 lines. The first line gives the name and ID of 
the female student with the highest grade, and the second line gives that of the
male student with the lowest grade. The third line gives the difference 
gradeF−grade​M. If one such kind of student is missing, output Absent in the 
corresponding line, and output NA in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95

Sample Output 1:

Mary EE990830
Joe Math990112
6

Sample Input 2:

1
Jean M AA980920 60

Sample Output 2:

Absent
Jean AA980920
NA

*/

#include<cstdio>
struct Info
{
    char name[15], ID[15];
    int grade;
}temp, M, F;
int main()
{
    int N;
    M.grade = 101;
    F.grade = -1;
    scanf("%d", &N);
    if(N == 0) {printf("Absent\nAbsent\nNA\n"); return 0;}
    for(int i = 0; i < N; i++)
    {
        char gender;
        scanf("%s %c %s %d", temp.name, &gender, temp.ID, &temp.grade);
        if(gender == 'M' && temp.grade < M.grade)      M = temp;
        else if(gender == 'F' && temp.grade > F.grade) F = temp;
    }
    if(M.grade == 101)     printf("%s %s\nAbsent\nNA\n", F.name, F.ID);
    else if(F.grade == -1) printf("Absent\n%s %s\nNA\n", M.name, M.ID);
    else
    printf("%s %s\n%s %s\n%d\n", F.name, F.ID, M.name, M.ID, F.grade - M.grade);
    return 0;
}