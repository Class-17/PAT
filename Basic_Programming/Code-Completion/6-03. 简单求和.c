int Sum (int List[], int N )
{
    if(N > 1) return List[N - 1] + Sum(List, N - 1);    // 采用递归求和
    else      return List[0];
}