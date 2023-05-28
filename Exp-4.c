#include <stdio.h>

int main()
{
    int i, j, temp, b[10], c[10], arr, n, ch, a;

    printf("\n\t\t FIRST FIT, BEST FIT, WORST FIT\n\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the size of block %d: ", i);
        scanf("%d", &b[i]);
        c[i] = b[i];
    }

    printf("\nEnter the size of arriving block: ");
    scanf("%d", &arr);

    printf("\n1. First fit\n2. Best fit\n3. Worst fit\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            for (i = 1; i <= n; i++)
            {
                if (b[i] >= arr)
                {
                    printf("Arriving block is allocated to block %d.", i);
                    break;
                }
                else
                    continue;
            }
            break;
        
        case 2:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j < n - i; j++)
                {
                    if (b[j] >= b[j + 1])
                    {
                        temp = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp;
                    }
                }
            }
            
            for (i = 1; i <= n; i++)
            {
                if (b[i] >= arr)
                {
                    a = b[i];
                    break;
                }
                else
                    continue;
            }
            
            for (i = 1; i <= n; i++)
            {
                if (c[i] == a)
                {
                    printf("Arriving block is allocated to block %d.", i);
                }
            }
            break;
        
        case 3:
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j < n; j++)
                {
                    if (b[j] >= b[j + 1])
                    {
                        temp = b[j];
                        b[j] = b[j + 1];
                        b[j + 1] = temp;
                    }
                }
            }
            
            for (i = 1; i <= n; i++)
                printf(" %d", b[i]);
            break;
        
        default:
            printf("Enter a valid choice.");
    }
    
    printf("\n\n");
    return 0;
}
