#include<cstdio>
int main()
{
    long long Gallen, Sickle, Knut;
    scanf("%lld.%lld.%lld", &Gallen, &Sickle, &Knut);
    long long sum = Gallen * 17 * 29 + Sickle * 29 + Knut;
    scanf("%lld.%lld.%lld", &Gallen, &Sickle, &Knut);
    sum += Gallen * 17 * 29 + Sickle * 29 + Knut ;
    Gallen = sum / 17 / 29;
    Sickle = sum % (17 * 29) / 29; 
    Knut = sum % 29;
    printf("%lld.%lld.%lld\n", Gallen, Sickle, Knut);
    return 0;
}