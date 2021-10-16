#include<cstdio>
#include<cstring>
int main()
{
    char s[10001];
    scanf("%[^\n]", s);
    getchar();
    bool hashTable[128] = {false};
    do
    {
        char temp;
        scanf("%c", &temp);
        if(temp == '\n') break;
        hashTable[temp] = true;
    } while (true);
    for(int i = 0, len = strlen(s); i < len; i++)
        if(hashTable[s[i]] == false)
            printf("%c", s[i]);
    return 0;
}