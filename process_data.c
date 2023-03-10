#include "stdio.h"
int process_data(int data_high,int data_low)
{
   __int16 original_value = (data_high<<8)|data_low;
   float temp_in_Celsious= (original_value*0.016)+0.5;
   return temp_in_Celsious;
}
int main()
{
    int high_reg,low_reg,temprature;
    printf("Enter the data high value:");
    scanf("%d",&high_reg);
    printf("\n");
    printf("Enter the data low value:");
    scanf("%d",&low_reg);
    if(high_reg!=0 && low_reg!=0){
        temprature = process_data(high_reg,low_reg);
     printf("Temprature in Celcious:%d 'C",temprature);
     }
     else{
           printf("The sensor value is invalid...");
     }

}