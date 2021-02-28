#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "device.h"
 
static LIST_HEAD(device_list);

 int  ini(device_t dev){
    printf("%s initialization with id = %d\n",dev->properties.name,dev->device_id);
 }

void main()
{
    struct device uart; 
        strcpy(uart.properties.name,"UART");
        uart.device_id = 5;
        uart.type = Device_Type_UART;
        uart.flag = 1;
        uart.properties.type = Object_Type_Device;
        uart.init = ini;
    list_add(&uart.properties.list, &device_list);

  struct device spi; 
        strcpy(spi.properties.name,"SPI");
        spi.device_id = 7;
        spi.type = Device_Type_SPI;
        spi.flag = 1;
        spi.properties.type = Object_Type_Device;
        spi.init = ini;
    list_add(&spi.properties.list, &device_list);

  struct device i2c; 
        strcpy(i2c.properties.name,"I2C");
        i2c.device_id = 3;
        i2c.type = Device_Type_I2C;
        i2c.flag = 1;
        i2c.properties.type = Object_Type_Device;
        i2c.init = ini;
    list_add(&i2c.properties.list, &device_list);

    list_t *p;
    list_for_each(p, &device_list){
        struct device *u = list_entry(p,struct device,properties.list);
        u->init(u);
    }
}
