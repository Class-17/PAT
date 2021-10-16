int Factorial(const int N )
{
    if(N < 0)  return 0;
    if(N <= 1) return 1;
    return N * Factorial(N - 1);
}