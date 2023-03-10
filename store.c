#include<stdio.h>
struct temperature
{
    int add;
    int data;
};
int store(struct temperature*);
main()
{

    struct temperature sensor;
    int value=0;
    sensor.add=0x90;
    printf("enter the data\n");
    scanf("%d",&sensor.data);
    value=store(&sensor);
    if(value == 1)
    {

        printf("successfully stored\n");
    }
    else
    {
        printf("not stored\n");
    }
}
int store(struct temperature *sensor)
{

    int store_data=0;
    store_data=sensor->data;
    if(store_data != 0)
        return 1;
    else
        return 0;

}
