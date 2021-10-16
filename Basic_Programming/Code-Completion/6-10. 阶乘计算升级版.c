void Print_Factorial(const int N )
{
    if(N < 0)   {printf("Invalid input\n"); return ;}
    int num[3000] = {1};        // 把结果按位分开储存，设个位为 1，其于位为 0
    for(int i = 1; i <= N; i++) {    // 阶乘
        for(int j = 2999; j >= 0; j--)
             num[j] *= i;               // 对当前数的每一位乘以当前数， 达到阶乘目的
        for(int i = 0; i <= 2999; i++)  // 进位
            if(num[i] > 9) {
                num[i + 1] += num[i] / 10;
                num[i] %= 10; 
            }
    }
    for(int i = 2999; i >= 0; i--)  // 从尾开始寻找不为零的第一个数，即阶乘结果的开头
        if(num[i] != 0) 
            while(i >= 0) printf("%d", num[i--]);
}