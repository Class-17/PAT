#include<cstdio>

char compare(int array[])
{
    int i = 0;
    for(int j = 1; j < 3; j++)
    {
        if(array[j] > array[i]) i = j;
    }
    if(i == 0)      return 'B';
    else if(i == 1) return 'C';
    else if(i == 2) return 'J';
    return 'B';
}

int main()
{
    int N, hi[4] = {0}, lo[4] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char a, b;
        getchar();
        scanf("%c %c", &a, &b);
        switch (a)
        {
        case 'B': if(b == 'C') hi[0]++; 
                  else if(b == 'J') lo[2]++; break;
        case 'C': if(b == 'J') hi[1]++; 
                  else if(b == 'B') lo[0]++; break;
        case 'J': if(b == 'B') hi[2]++; 
                  else if(b == 'C') lo[1]++; break;
        }
    }
    hi[3] = hi[0] + hi[1] + hi[2];
    lo[3] = lo[0] + lo[1] + lo[2];
    printf("%d %d %d\n", hi[3], N - hi[3] - lo[3], lo[3]);
    printf("%d %d %d\n", lo[3], N - hi[3] - lo[3], hi[3]);
    printf("%c %c\n", compare(hi), compare(lo));
    return 0;
}