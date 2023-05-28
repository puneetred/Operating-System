#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, bt[30], wait_t[30], turn_ar_t[30], av_wt_t = 0, avturn_ar_t = 0, i, j;
    printf("\nPlease enter the total number of processes(maximum 30): "); // the maximum process that be used to calculate is specified.
    scanf("%d", &n);

    printf("\nEnter The Process Burst Time\n");
    for (i = 0; i < n; i++) // burst time for every process will be taken as input
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wait_t[0] = 0;

    for (i = 1; i < n; i++)
    {
        wait_t[i] = 0;
        for (j = 0; j < i; j++)
            wait_t[i] += bt[j];
    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

    for (i = 0; i < n; i++)
    {
        turn_ar_t[i] = bt[i] + wait_t[i];
        av_wt_t += wait_t[i];
        avturn_ar_t += turn_ar_t[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t%d", i + 1, bt[i], wait_t[i], turn_ar_t[i]);
    }

    av_wt_t /= i;
    avturn_ar_t /= i; // average calculation is done here
    printf("\n\nAverage Waiting Time: %d", av_wt_t);
    printf("\nAverage Turnaround Time: %d\n", avturn_ar_t);

    system("read -n1 -p ' ' key");
    return 0;
}
