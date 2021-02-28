#include "stdint.h"
#include "list.h"

 
enum object_type
{
    Object_Type_Device,
    Object_Type_User,
    Object_Type_Unknown
};

struct object
{
    char        name[100];
    enum object_type type;
    list_t      list;
};

typedef struct object *object_t;

enum device_type
{
    Device_Type_UART,
    Device_Type_I2C,
    Device_Type_SPI,
    Device_Type_Unknown
};


typedef struct device *device_t;
 
/**
 * Device structure
 */
struct device
{
    struct object          properties;
    uint8_t                device_id;
    enum device_type       type;
    uint8_t                flag;
             

    /* device call back */
    int  (*rx_interrupt)(device_t dev, uint8_t size);
    int  (*tx_complete)(device_t dev, void *buffer);

    int  (*init)(device_t dev);
    int  (*open)(device_t dev, uint16_t oflag);
    int  (*close)(device_t dev);
    int  (*read)(device_t dev, signed int pos, void *buffer, uint8_t size);
    int  (*write)(device_t dev, signed int pos, const void *buffer, uint8_t size);

};
 
