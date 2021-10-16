void PrintN (int N )
{
    if(N > 1)   PrintN(N - 1);      // 递归打印 N
    printf("%d\n", N);
}