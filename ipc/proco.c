#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty, x = 0;
void producer()
{
    --mutex;
    --empty;
    x++;
    printf("producer produces item %d", x);
    ++full;
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    printf("consumer consumes item %d", x);
    --x;
    ++empty;
    ++mutex;
}
int main()
{
    int n, i;
    printf("enter the size of the buffer");
    scanf("%d", &empty);
    printf("\n1.press 1 for producer \n2.press 2 for consumer \n3.press 3 for exit");
    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                producer();
            }
            else
            {
                printf("Buffer is full!!");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0)
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty!!");
            }
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}