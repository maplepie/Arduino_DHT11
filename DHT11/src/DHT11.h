/*
作者：maplepie
创建日期：2016/9/1
用途：使用DHT11获取温度和湿度
版本：1.0.0
*/

#ifndef DHT11_H
#define DHT11_H

#include "Arduino.h"

class DHT11
{
public:
	DHT11(byte pin);
	byte requestData();
	byte getTemperature() const;
	byte getHumidity() const;
private:
	byte _pin;
	byte data[5];
};

#endif