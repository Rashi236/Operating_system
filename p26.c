
#include <stdio.h>

int main(void)
{
    int n, i;
    int at[20], bt[20], pid[20];
    int ct[20], wt[20], tat[20];
    int completed[20] = {0};

    int time = 0, count = 0;
    int min, pos;

    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    while(count < n)
    {
        min = 9999;
        pos = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(bt[i] < min)
                {
                    min = bt[i];
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

            avgWT = avgWT + wt[pos];
            avgTAT = avgTAT + tat[pos];

            completed[pos] = 1;
            count++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgWT/n);
    printf("Average TAT = %.2f\n", avgTAT/n);

    return 0;
}
