#include <stdio.h>
#include <stdint.h>

struct temp
{
            int slave_add;
            int data:16;
};

void sense(struct temp sensor);
struct temp sensor;

int main()
{
            sensor.slave_add=0x54;
            sensor.data=76;
            sense(sensor);
            return 0;
}

void sense(struct temp sensor)
{
            printf("Data Reading From Temperature Sensor\n");
            printf(" Slave Address: %x \n", sensor.slave_add);
            printf(" Sensor data: %d \n", sensor.data);
}
