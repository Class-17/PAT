int Search_Bin(SSTable T, KeyType k)  
{
    // 本题虽为 C++，函数部分完全可用 C 解答
    int lo = 0;     // 使用标准二分查找
    int hi = T.length - 1;
    while(lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if      (k < T.R[mid].key) hi = mid - 1;
      else if (k > T.R[mid].key) lo = mid + 1;
      else                       return mid;
    }
    return 0;
}