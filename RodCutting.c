#include <stdio.h>
#include <math.h>
int cutrod(int p[], int n)
{
    if (n <= 0)
        return 0;
    int q = -1000000;
    for (int i = 0; i < n; i++)
    {
        q = max(q, p[i] + cutrod(p, n - i - 1));
    }
    return q;
}
int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int maxrev = cutrod(a, n);
    printf("Maximum Revenue : ");
    printf("%d ", maxrev);
}