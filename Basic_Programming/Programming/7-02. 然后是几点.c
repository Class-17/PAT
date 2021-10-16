#include <stdio.h>
int main()
{
    int time, past;
    scanf("%d %d", &time, &past);
    time = time / 100 * 60 + time % 100 + past; //先对读入的时间做处理，在加上过去的时间
    time = time / 60 * 100 + time % 60; // 将时间的格式转换回来
    printf("%03d\n", time);
    return 0;
}
/*
本题我们把题目给出的时间读入，但是这个格式是一个“小时”和“分钟”连在一起的数字
在此把它转换成一个以分钟为单位的时间，然后直接加上“过去的时间”（以分钟为单位的）
运算完成后，再将时间的格式转换回去，输出。
*/