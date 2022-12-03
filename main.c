#include <stdio.h>

/*
 * first Name: Farzam
 * last Name: Koohi Ronaghi
 * student Id: 401106403
 */

// This is program to convert a number to binary

int a , b = 0 ,i = 0;

int main()
{
    scanf("%d" , &a);
    while (a>0)
    {
        int m=a%2;
        b = b + m * (int)pow(10 , i);
        i++;
        a = a/2;
    }
    printf("%d" , b);
}