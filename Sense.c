#include <stdio.h>
#include <stdint.h>

struct temp  // Temperature sensor details
{
            int slave_add; //Tempeature sensor slave address
            int data:16; // data length
};

void sense(struct temp sensor); // Sense function Prototype
struct temp sensor; // Structure Variable or Object

int main()
{
            sensor.slave_add=0x54; // Slave address for Temperature sensor
            sensor.data=76;  // Temperature sensor data
            sense(sensor); // Sense function Prototype
            return 0;
}

void sense(struct temp sensor)
{
            printf("Data Reading From Temperature Sensor\n");
            printf(" Slave Address: %x \n", sensor.slave_add);  //Display Temperature sensor Slave addresss
            printf(" Sensor data: %d \n", sensor.data);  //Display Temperature Sensor Data
}
