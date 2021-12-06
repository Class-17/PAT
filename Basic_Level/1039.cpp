#include<cstdio>
int main()
{
    int hashTabel[126] = {0};
    char temp;
    do
    {
        scanf("%c", &temp);
        if(temp == '\n') break;
        hashTabel[temp]++;
    } while (temp != '\n');
    do
    {
        scanf("%c", &temp);
        if(temp == '\n') break;
        hashTabel[temp]--;
    } while (temp != '\n');
    int need = 0, extra = 0;
    for(int i = 0; i < 126; i++)
        if(hashTabel[i] > 0) extra += hashTabel[i];
        else if(hashTabel[i] < 0) need -= hashTabel[i];
    if(need == 0) printf("Yes %d\n", extra);
    else          printf("No %d\n", need);
    return 0;    
}