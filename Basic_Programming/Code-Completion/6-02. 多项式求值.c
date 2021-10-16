double f(int n, double a[], double x )
{
    double sum = a[0];
    for(int i = 1; i <= n; i++) {
        a[i] *= x;      // 从 1次幂开始， 依次求得各个项的结果
        sum += a[i];
        x *= x;         // 求得下一项数的变量值
    }
    return sum;
}