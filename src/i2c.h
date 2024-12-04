#ifndef I2C_H
#define I2C_H

#include <stdint.h>

#define TWI_FREQ 100000UL

void i2c_send(uint8_t data);
void i2c_init(uint8_t slaveAddr);

#endif // I2C_H
