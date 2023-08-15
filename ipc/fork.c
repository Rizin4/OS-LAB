#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int n = fork();
    int m = fork();
    printf("n1:%d m1:%d\n", n, m);
    printf("n2:%d m2:%d\n", n, m);
    printf("n3:%d m3:%d\n\n", n, m);
    return 0;
}