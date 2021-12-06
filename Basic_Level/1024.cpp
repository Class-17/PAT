#include<cstdio>
char num[20000];
int main()
{
    int pow = 0, poPosition = 2, ePosition = 0;
    scanf("%s", num);
    if(num[0] == '-') printf("-");
    for(int i = 4; num[i] != '\0'; i++)
        if(num[i] == 'E')
        {
            for(int j = i + 2; num[j] != '\0'; j++)
            {
                pow = pow * 10 + num[j] - '0';
                num[j] = '\0';
            }
            if(num[i + 1] == '-') pow *= -1;
            num[i] = num[i + 1] = '\0';
            ePosition = i;
        }
    if(pow > 0)
        while(pow > 0)
        {
            num[poPosition] = num[poPosition + 1];
            if(num[poPosition] == '\0') num[poPosition] = '0';
            num[++poPosition] = '.';
            pow--;
            if(pow == 0 && num[poPosition + 1] == '\0')
                num[poPosition] = 0; 
        }   
    else if(pow < 0)
    {
        num[0] = '0'; num[2] = num[1]; num[1] = '.'; pow = (pow + 1) * -1;
        if(pow > 0)
            for(int i = ePosition - 1; i > 1; i--)
                 num[i + pow] = num[i]; 
        for(int i = 1 + pow; i > 1; i--)
            num[i] = '0';
    }
    for(int i = (num[0] == '0' ? 0 : 1); num[i] != '\0'; i++)
        printf("%c", num[i]);
    return 0;
}