#include <stdio.h>

int main()
{
    int n, TIME_QUANTUM, i;
    int arrival_time[10], burst_time[10], remaining_time[10];
    int completed = 0, time = 0, wt = 0, tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    printf("\n enter quantum time ");
    scanf("%d", &TIME_QUANTUM);

    for (i = 0; i < n; i++)
    {
        remaining_time[i] = burst_time[i];
    }

    while (completed < n)
    {
        for (i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0)
            {
                if (arrival_time[i] <= time)
                {
                    int execution_time = (remaining_time[i] < TIME_QUANTUM) ? remaining_time[i] : TIME_QUANTUM;
                    remaining_time[i] -= execution_time;
                    time += execution_time;

                    if (remaining_time[i] == 0)
                    {
                        completed++;
                        tat = time - arrival_time[i];
                        wt = tat - burst_time[i];
                        printf("\nProcess %d completed at time %d\t tat:%d\twt:%d", i, time, tat, wt);
                    }
                }
            }
        }
    }
    return 0;
}