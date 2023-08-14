#include <stdio.h>
int main()
{
    int p[20], f[20], fn, i, j, k, fi, n, farthest, pos, found;
    printf("\n enter the number of pages");
    scanf("%d", &n);
    printf("\n enter the sequence");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("\n enter the number of frames");
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
                found = 1; // hit
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
            for (j = 0; j < fn; j++) // finding page not frequently used in furure
            {
                fi = -1;
                for (k = i + 1; k < n; k++)
                {
                    if (f[j] == p[k])
                    {
                        fi = k;
                        break;
                    }
                }
                if (fi == -1)
                {
                    pos = j;
                    break;
                }
                if (fi > farthest)
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