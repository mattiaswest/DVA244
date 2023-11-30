#include<stdio.h>
int sum(int x);

int main(void)
{
    int result = sum(5);
    return 0;
}
int sum(int x)
{
    int temp = 1;
    printf("sum(%d) anropas\n", x);
    if (x == 1)
    {
        printf("sum(%d) returnerar %d\n", x, temp);
        return x;
    }
    else if (x < 0)
        return 0;
    else
    {
        temp = x + sum(x - 1);
        printf("sum(%d) returnerar %d\n", x, temp);
        return temp;
    }

}