#include <stdio.h>
int main()
{
    int p[20], f[20], fn, i, j, k, n, temp, found, pos, ct = 0;
    printf("\n enter the number of pages");
    scanf("%d", &n);
    printf("\n enter the sequence:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\n enter number of frames:");
    scanf("%d", &fn);
    for (j = 0; j < fn; j++)
    {
        f[j] = -1;
    }
    for (i = 0; i < n; i++)
    {
        found = 0;
        for (j = 0; j < fn; j++)
        {
            if (f[j] == p[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            for (j = 0; j < fn; j++) // inserting the page if empty space available
            {
                if (f[j] == -1)
                {
                    f[j] = p[i];
                    goto l1;
                }
            }
            f[ct] = p[i];
            ct = (ct + 1) % fn;
        }
    l1:
        for (j = 0; j < fn; j++)
            printf("%d\t", f[j]);
        printf("\n");
    }
}