#include <stdio.h>

int main()
{
    int p[20], bt[20], at[20], wt[20], tat[20], i, n, cpu = 0, temp, t, x = 0;
    float swt = 0, stat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process number, burst time, and arrival time:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &p[i], &bt[i], &at[i]);
    }

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time");

    while (x < n)
    {
        temp = 100;

        // Find process with smallest burst time that has arrived and not yet processed
        for (i = 0; i < n; i++)
        {
            if (at[i] <= cpu && bt[i] > 0)
            {
                if (bt[i] < temp)
                {
                    temp = bt[i];
                    t = i;
                }
            }
        }

        // If no process found, wait for the next process to arrive
        if (temp == 100)
        {
            cpu++;
            continue;
        }

        cpu += bt[t];
        tat[t] = cpu - at[t];
        stat += tat[t];
        wt[t] = tat[t] - bt[t];
        swt += wt[t];

        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", p[t], bt[t], at[t], wt[t], tat[t]);
        bt[t] = 0; // Mark the process as completed
        x++;
    }

    swt = swt / n;
    stat = stat / n;
    printf("\nAverage Waiting Time: %f\nAverage Turnaround Time: %f", swt, stat);

    return 0;
}