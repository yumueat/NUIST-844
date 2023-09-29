#include <stdio.h>
#define MAX 101
void Plan(int a[MAX][MAX], int k)
{
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 2;
    a[2][2] = 1;
    int block_size = 1;
    for (int now_k = 2; now_k <= k; now_k++)
    {
        block_size *= 2;
        for (int i = 1; i <= block_size; i++)
        {
            for (int j = 1; j <= block_size; j++)
            {
                a[i + block_size][j] = a[i][j] + block_size;
                a[i][j + block_size] = a[i + block_size][j];
                a[i + block_size][j + block_size] = a[i][j];
            }
        }
    }
}
int main()
{
    int a[MAX][MAX];
    int k = 3;
    int n = 1 << k;
    Plan(a, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}