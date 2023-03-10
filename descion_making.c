/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int data[10] = {-120,-130,-140,-150,120,130,140,40,50,60};
    int i;
    for(i=0;i<10;i++)
    {
        if(data[i] >= -90 && data[i] <= +90 )
        printf("take action 1 for temp range -90 to +90\n");
        
        if(data[i] >= +90 )
        printf("take action 2 for temp range above +90\n");
        
        if(data[i] <= -90 )
        printf("take action 3 for temp range below -90\n");
    }

    return 0;
}
