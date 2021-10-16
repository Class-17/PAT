#include <stdio.h>
#define MAXN 100000

int main()
{
    int a, n, record[MAXN] = {0};;
    scanf("%d %d", &a, &n);
    if(n == 0) { // 特判 N为 0
    	printf("0\n");
    	return 0;
	}
    for(int i = 0; i < n; i++) {
        record[i] += a * (n - i); // 每一位上数值对应的公式
        if(record[i] > 9) {     // 进位
            record[i + 1] = record[i] / 10;
            record[i] = record[i] % 10;
        }
    }
    if(record[n] != 0)        // 检测第 n + 1位是否存在，不存在直接输出
        printf("%d",record[n]);
    for(int i = n - 1; i >= 0; i--)     // 输出剩下 n位
        printf("%d",record[i]);
    return 0;
}

/*
思路演示：
把结果按位储存在数组中
1 2 3 4 5 N
9 9 9 9 9 9 
  9 9 9 9 9
    9 9 9 9
      9 9 9
        9 9
          9
每一位的值即为 A * （N - i（位数））
最后将每一位的数进位，再按位从大到小输出  
*/