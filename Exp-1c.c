#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[100][5]; // Matrix for storing Process Id, Burst Time, Arrival Time, Waiting Time, Turn Around Time.
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("\nEnter Burst Time and Arrival Time:\n");
    // User Input Burst Time and Arrival Time and allocating Process Id.
    for (i = 0; i < n; i++)
    {
        printf("P%d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &A[i][1]);
        printf("Arrival Time: ");
        scanf("%d", &A[i][2]);
        A[i][0] = i + 1;
    }
    
    // Sorting the processes based on their Burst Time and Arrival Time.
    for (i = 0; i < n; i++)
    {
        index = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j][1] < A[index][1])
            {
                index = j;
            }
            else if (A[j][1] == A[index][1] && A[j][2] < A[index][2])
            {
                index = j;
            }
        }
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        temp = A[i][2];
        A[i][2] = A[index][2];
        A[index][2] = temp;

        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    
    A[0][3] = 0; // Waiting time for the first process is 0.
    
    // Calculation of Waiting Times and Turn Around Times.
    for (i = 1; i < n; i++)
    {
        int sum = 0;
        for (j = 0; j < i; j++)
        {
            sum += A[j][1];
        }
        A[i][3] = sum - A[i][2];
        total += A[i][3];
    }
    
    avg_wt = (float)total / n;
    total = 0;
    
    printf("\nP    BT    AT    WT    TAT\n");
    // Calculation of Turn Around Time and printing the data.
    for (i = 0; i < n; i++)
    {
        A[i][4] = A[i][1] + A[i][3];
        total += A[i][4];
        printf("P%d   %d     %d     %d     %d\n", A[i][0],
               A[i][1], A[i][2], A[i][3], A[i][4]);
    }
    
    avg_tat = (float)total / n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n\n", avg_tat);
    
    return 0;
}
