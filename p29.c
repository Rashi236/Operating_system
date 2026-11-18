
#include <stdio.h>

int main(void)
{
    int n, i, j;

    int pid[20];
    int at[20];
    int bt[20];
    int ct[20];
    int wt[20];
    int tat[20];

    float avgWT = 0.0;
    float avgTAT = 0.0;

    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("P%d arrival time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d burst time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                int temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(time < at[i])
            time = at[i];

        time = time + bt[i];

        ct[i] = time;

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", avgWT / n);
    printf("Average TAT = %.2f\n", avgTAT / n);

    return 0;
}
