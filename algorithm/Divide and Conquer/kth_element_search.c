/*
 * @Description: 分治法-寻找一个序列中第K小的元素
 * @Author: yumu
 * @TimeComplexityRecurrence: T(n) = T(n/2) + O(n) => T(n) = O(n)
 * @BestCaseTimeComplexity: O(n) 当每次划分的基准/枢轴恰好是中位数，也即正好能将一个序列划分为长度大致相等的两个子序列时是最好的情况
 * @WorstCaseTimeComplexity: O(n^2) 当每次划分的基准恰好是序列中的最大值或者最小值时，处理区间只比上一次减少1个元素，这是最坏的情况
 * @AverageCaseTimeComplexity: O(n)
 */
#include <stdio.h>
int QuickSelect(int *a, int start, int end, int k)
{
    // 如果要寻找的子序列中只有一个元素且这个元素正好是要找的第k小元素(这里能这样判断其实是因为,前面的寻找的过程其实都是在排序,能找到这一个的时候这个元素的位置绝对是正确的)
    if (start == end && start == k - 1)
    {
        return a[start];
    }
    // 这里其实还有一种找不到的情况，但是题目一般不会这样去给定k的值，而且目前的程序虽然不能处理超范围的值，但是也不会出错，其实主要是我懒得加了
    else if (start < end)
    {
        // 记录枢轴的值
        int pivot = a[start];
        // 用另外的变量来代替start和end避免破坏start和end的值,后面递归的时候还要用到
        int i = start, j = end;
        // 外层这个循环主要是保证进行多次循环，直到比枢轴元素大的元素都到枢轴元素的右边，比枢轴元素小的元素全部到枢轴元素的左边，也即是确定枢轴元素的位置
        while (i != j)
        {
            // 从右往左扫描，直到找到比枢轴元素小的元素
            while (j > i && a[j] >= pivot)
            {
                j--;
            }
            // 把比枢轴元素小的元素移动到左边的空位（第一个空位其实就是枢轴的位置）
            a[i] = a[j];
            // 从左往右扫描，直到找到比枢轴元素大的元素
            while (i < j && a[i] <= pivot)
            {
                i++;
            }
            // 把比枢轴元素大的元素移动到右边的空位
            a[j] = a[i];
        }
        // 把枢轴元素放回队列
        a[i] = pivot;
        // 找到了的情况
        if (i == k - 1)
        {
            return a[i];
        }
        // 要找的元素在右区间,对右区间继续递归查找
        else if (k - 1 > i)
        {
            return QuickSelect(a, i + 1, end, k);
        }
        // 要找的元素在左区间,对左区间继续递归查找
        else
        {
            return QuickSelect(a, start, i - 1, k);
        }
    }
}
int main()
{
    // 指定序列长度
    int n = 10;
    // 设置序列
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    int res;
    // 这里相当于是把所有的k都试了一遍,实际上一般只会问一个k值
    for (int k = 1; k <= n; k++)
    {
        res = QuickSelect(a, 0, n - 1, k);
        printf("第%d小的元素是%d\n", k, res);
    }
    return 0;
}