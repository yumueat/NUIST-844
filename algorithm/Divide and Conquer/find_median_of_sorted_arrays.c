#include <stdio.h>
// 处理前半部分
void prepart(int *start, int *end)
{
    *end = (*start + *end) / 2;
}
// 处理后半部分
void postpart(int *start, int *end)
{
    int m = (*start + *end) / 2;
    // 如果长度为偶数就从一半的后面开始取
    if ((*end - *start + 1) % 2 == 0)
    {
        *start = m + 1;
    }
    // 如果长度为奇数就从一半开始取
    else
    {
        *start = m;
    }
}
// 获取中位数
int GetMidNum(int *a, int a_start, int a_end, int *b, int b_start, int b_end)
{
    // 当两个序列都只有一个元素的时候小的那个就是要找的中位数
    if (a_start == a_end && b_start == b_end)
    {
        return a[a_start] < b[b_start] ? a[a_start] : b_start;
    }
    else
    {
        int a_midnum = a[(a_start + a_end) / 2], b_midnum = b[(b_start + b_end) / 2];
        if (a_midnum == b_midnum)
        {
            return a_midnum;
        }
        else if (a_midnum > b_midnum)
        {
            prepart(&a_start, &a_end);
            postpart(&b_start, &b_end);
            return GetMidNum(a, a_start, a_end, b, b_start, b_end);
        }
        else if (a_midnum < b_midnum)
        {
            postpart(&a_start, &a_end);
            prepart(&b_start, &b_end);
            return GetMidNum(a, a_start, a_end, b, b_start, b_end);
        }
    }
}
int main()
{
    int a[] = {11, 13, 15, 17, 19};
    int b[] = {2, 4, 6, 8, 20};
    int midnum = GetMidNum(a, 0, 4, b, 0, 4);
    printf("%d", midnum);
}