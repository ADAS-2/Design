#include "stdio.h"
 struct temperature  
    {
        int sensor_value; //sensor value
    };
void validate(struct temperature *);
 int main()
 {
    struct temperature sensor[5];
    for(int i=0;i<5;i++)
    {
    printf("Enter value: \n");
    scanf("%d",&sensor[i].sensor_value);
    }
    validate(sensor);
    return 0;
 }   
void validate(struct temperature *sensor) 
{
    int count_invalid_data=0,loop;
    for(loop=0;loop<5;loop++)
    {
        if(sensor[loop].sensor_value==0) //checking sensor value is coming or not
        {
            count_invalid_data++; 
            if(count_invalid_data==4)
            {
                printf("red led \n");
            }
        }
        else
        {
           printf("calling process\n");
        }
    }
}