#include <stdio.h>
int main()
{
    int n, i, j, pid[10], bt[10], at[10], wt[10], tat[10], pos, temp[10], y, q, sum, count;
    float awt = 0.0, atat = 0.0;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);
    y = n;

    printf("Enter the process id of processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter the burst time of processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("Enter the arrival time time of processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter the quanta size:\n");
    scanf("%d", &q);

    printf("process|arrival|burst|waitingtime|turnaround|completion");
    sum = 0;
    j = 0;

    while (y != 0)
    {
        if (temp[j] <= q && temp[j] > 0)
        {
            sum = sum + temp[j];
            temp[j] = 0;
            count = 1;
        }
        else if (temp[j] > 0)
        {
            sum = sum + q;
            temp[j] = temp[j] - q;
        }

        if (temp[j] == 0 && count == 1)
        {
            y--;
            tat[j] = sum - at[j];
            wt[j] = tat[j] - bt[j];
            printf("\n%d\t%d\t%d\t%d\t%d\t%d\n", pid[j], at[j], bt[j], wt[j], tat[j], sum);

            count = 0;
        }
        if (j == n - 1)
        {
            j = 0;
        }
        else if (at[j + 1] <= sum)
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
    awt = awt / n;
    atat = atat / n;
    printf("Avg waiting time:%f", awt);
    printf("Avg tuurnaround time:%f", atat);
}