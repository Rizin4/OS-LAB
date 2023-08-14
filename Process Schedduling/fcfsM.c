#include <stdio.h>
int main()
{
    int n;
    printf("enter the number of  processes");
    scanf("%d", &n);
    int at[n], bt[n], ct, wt, tat, ttat, twt;

    for (int i = 0; i < n; i++)
    {
        printf("enter the details of process[%d]", i + 1);
        printf("\narrival time=");
        scanf("%d", &at[i]);
        printf("\nburst time=");
        scanf("%d", &bt[i]);
    }
    printf("process arrival  burst   waiting turnaround");
    for (int i = 0; i < n; i++)
    {
        if (ct < at[i])
        {
            ct = at[i];
        }
        wt = ct - at[i];
        twt = twt + wt;
        tat = wt + bt[i];
        ttat = ttat + tat;
        printf("\n%d       %d      %d      %d      %d", i + 1, at[i], bt[i], wt, tat);
        ct += bt[i];
    }
    float avgwt = (float)twt / n;
    float avgtat = (float)ttat / n;
    printf("\naverage wt=%.2f", avgwt);
    printf("\naverage tat=%.2f", avgtat);
}