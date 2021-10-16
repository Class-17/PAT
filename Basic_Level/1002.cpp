#include<cstdio>
#include<cstring>
int main()
{
    char record[100]= {0};
    char cast[10][5] = {"ling", "yi", "er", "san", "si",
                      "wu", "liu", "qi", "ba", "jiu"};
    scanf("%s", record);
    int count = 0, ans[3] = {0};
    for(int i = 0; i < strlen(record); i++)
        count += record[i] - '0';
    for(int i = 0; count > 0; count /= 10)
        ans[i++] = count % 10;
    for(int i = 2; i > 0; i--)
        if(ans[i] != 0)
            while(i > 0) printf("%s ", cast[ans[i--]]);
    printf("%s\n", cast[ans[0]]);
    return 0;
}