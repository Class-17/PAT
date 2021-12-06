#include<cstdio>
int main()
{
    int num, maximum = 0, record = 0;
    scanf("%d", &num);
    int school[num] = {0};
    while (num--)
    {
        int schoolID, score;
        scanf("%d %d", &schoolID, &score);
        school[schoolID] += score;
        if(school[schoolID] >= maximum)
        {
            maximum = school[schoolID];
            record = schoolID;
        }    
    }
    printf("%d %d\n", record, school[record]);
    return 0;
}