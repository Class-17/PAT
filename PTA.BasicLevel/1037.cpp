#include<cstdio>
int main()
{
    int Gallen, Sickle, Knut;
    scanf("%d.%d.%d", &Gallen, &Sickle, &Knut);
    int sum = Gallen * 17 * 29 + Sickle * 29 + Knut;
    scanf("%d.%d.%d", &Gallen, &Sickle, &Knut);
    sum = Gallen * 17 * 29 + Sickle * 29 + Knut - sum;
    if(sum < 0) {printf("-"); sum *= -1;}
    Gallen = sum / 17 / 29;
    Sickle = sum % (17 * 29) / 29;
    Knut = sum % 29;
    printf("%d.%d.%d\n", Gallen, Sickle, Knut);
    return 0;
}