#include <stdio.h>
int main()
{
    int p[20], f[20], fn, n, i, j, found, k, farthest, pos, fi;
    printf("\n enter the no of pages:");
    scanf("%d", &n);
    printf("\n enter the page sequence:\n");
    for (i = 0; i < n; i++)
    {
        scanf("\t%d", &p[i]);
    }
    printf("\n enter the numberof frames:");
    scanf("%d", &fn);
    for (j = 0; j < fn; j++)
        f[j] = -1;
    for (i = 0; i < n; i++)
    {
        found = 0;               // initialising flag
        for (j = 0; j < fn; j++) // check each frame for the specified page,if found flag set
        {
            if (f[j] == p[i])
            {
                found = 1; // hit
                break;
            }
        }

        if (found == 0) // miss
        {
            for (j = 0; j < fn; j++) // inserting the page if empty space available
            {
                if (f[j] == -1)
                {
                    f[j] = p[i];
                    goto l1;
                }
            }
            farthest = 100;
            pos = 100;
            for (j = 0; j < fn; j++) // finding the least recent frame
            {
                fi = 100;
                for (k = i - 1; k >= 0; k--)
                {
                    if (f[j] == p[k])
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
        for (j = 0; j < fn; j++)
            printf("%d\t", f[j]);
    }
    return 0;
}