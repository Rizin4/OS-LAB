#include <stdio.h>
int main()
{
    int p[20], f[20], fn, n, i, j, found, k, farthest, pos, fi;
    printf("\n enter the no of pages:");
    scanf("%d", &n);
    printf("\n enter the sequence:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\n enter the numberof frames:");
    scanf("%d", &fn);
    for (j = 0; j < fn; j++)
        f[j] = -1;
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
            for (j = 0; j < fn; j++)
            {
                if (f[j] == -1)
                {
                    f[j] = p[i];
                    found = 1;
                    goto l1;
                }
            }
            farthest = 100;
            pos = 100;
            for (j = 0; j < fn; j++)
            {
                fi = 100;
                for (k = i - 1; k >= 0; k--)
                {
                    if (p[k] == f[j])
                    {
                        fi = k;
                        break;
                    }
                }

                if (fi < farthest)
                {
                    farthest = fi;
                    pos = j;
                }
            }
            f[pos] = p[i];
        }
    l1:
        printf("\n");

        {
            for (j = 0; j < fn; j++)
                printf("%d\t", f[j]);
        }
    }
    return 0;
}