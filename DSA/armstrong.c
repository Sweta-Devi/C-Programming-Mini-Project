/* WAP to find armstrong number in C */
#include<stdio.h>
int main()
{
    int num, original, rem, result;
    printf("Enter a number : ");
    scanf("%d", &num);

    original = num;

    while(original != 0)
    {
        rem = original % 10;    
        /* rem contains last digit of num, 153 % 10 = 15.3 and reminder is 3
        then 15 % 10, rem = 5 */

        result += rem * rem * rem;  
        original /= 10; //to retain the original number
    }
    if(original == num)
        printf("%d is an armstrong number.\n\n", num);
    else
        printf("%d is not an armstrong number.\n\n", num);

    return 0;
}