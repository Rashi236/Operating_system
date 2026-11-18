
#include <stdio.h>

int main(void)
{
    int n, i;

    int pid[20], at[20], bt[20];
    int priority[20], ct[20], wt[20], tat[20];
    int completed[20] = {0};

    int time = 0, count = 0;
    int pos, min;

    float avgWT = 0.0;
    float avgTAT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("P%d arrival time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d burst time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    while(count < n)
    {
        min = 9999;
        pos = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(priority[i] < min)
                {
                    min = priority[i];
                    pos = i;
                }
            }
        }

        if(pos == -1)
        {
            time++;
        }
        else
        {
            time = time + bt[pos];

            ct[pos] = time;
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];

            avgWT += wt[pos];
            avgTAT += tat[pos];

            completed[pos] = 1;
            count++;
        }
    }

    printf("\nPID\tAT\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
        pid[i], at[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgWT / n);
    printf("Average TAT = %.2f\n", avgTAT / n);

    return 0;
}
