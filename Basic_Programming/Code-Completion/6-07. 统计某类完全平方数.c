int IsTheNumber(const int N )
{
    int num[10] = {0}, temp = N;
    if(N <= 0 || N != pow((int)sqrt(temp), 2)) return 0;   // N不为整数，返回零，为整数，不为平方数，返回零
    while (temp > 0) {           // 储存每一位数字的个数
        num[temp % 10] ++;
        temp /= 10;
    }
    for(int i = 0; i < 10; i++)   // 检测是否有数字出现次数超过 2
        if(num[i] > 1) return 1;
    return 0; 
}