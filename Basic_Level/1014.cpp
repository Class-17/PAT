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