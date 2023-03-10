#include<stdio.h>
int main()
{
int ACTION=1;

    if(ACTION == 1)
    {
        printf("Blink green led\n"); //for temperature range in between -90 to 90 degree celsius
    }
     if(ACTION == 2)
    {
        printf("Red led on \n");//for temperature above 90 degree celsius
    }
     if(ACTION == 3)
    {
        printf("Red led off\n");//for temperature below -90 degree celsius
    }
    return 1;
}

