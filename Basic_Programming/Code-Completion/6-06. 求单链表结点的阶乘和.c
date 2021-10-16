int FactorialSum(List L )
{
    if(L == NULL) return 0;         // 特判空链表，返回零
    if(L->Data == 0) L->Data = 1;   // 特判 0的阶乘为 1
    for(int i = L->Data - 1; i > 0; i--)    // 循环求得当前节点数据的阶乘
        L->Data *= i;
    if(L->Next != NULL) return L->Data + FactorialSum(L->Next); // 递归求得所有节点阶乘和
    else                return L->Data;
}