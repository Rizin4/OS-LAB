#include <stdio.h>

int main()
{
    int n;
    float awt = 0.0, atat = 0.0;
    int pid[10], at[10], bt[10], wt[10], tat[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process id: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }
    printf("\nEnter arrival time: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("\nEnter burst time:\ ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[j] < at[i] || (at[j] == at[i] && pid[j] < pid[i]))
            {
                int temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1] - at[i] + at[i - 1];
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
        awt += wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        atat += tat[i];
    }

    printf("Processid\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;
    printf("Average waiting time: %f\n", awt);
    printf("Average turnaround time: %f\n", atat);

    return 0;
}
