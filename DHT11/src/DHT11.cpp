/*
作者：maplepie
创建日期：2016/9/1
用途：使用DHT11获取温度和湿度
版本：1.0.0
*/

#include "Arduino.h"
#include "DHT11.h"

DHT11::DHT11(byte pin)
{
	_pin = pin;

}

byte DHT11::requestData()
{
	pinMode(_pin,OUTPUT);
	digitalWrite(_pin, HIGH);
  	delayMicroseconds(100);
  	digitalWrite(_pin, LOW);
  	delay(20);
  	digitalWrite(_pin, HIGH);
  	delayMicroseconds(20);
  	pinMode(_pin, INPUT_PULLUP);
  	delayMicroseconds(60);
  	if (digitalRead(_pin) != 0)
  	{
    	Serial.println("No Response");
    	return 1;
  	}
  	delayMicroseconds(40);
  	unsigned long duration;
  	for (byte j = 0; j < 5; j++)
  	{
    	byte temp = 0;
    	for (int i = 7; i >= 0; i--)
    	{
      		duration = 0;
      		duration = pulseIn(_pin, HIGH,150);
      		if (duration > 30)
      		{
        		bitWrite(temp, i, 1);
      		}
    	}
    	data[j] = temp;
  	}

	if(data[4]!=data[0]+data[2])
	{
		Serial.println("Data not Correct");
		return 2;
	}
	return 0;
}

byte DHT11::getTemperature() const{
  return data[2];
}

byte DHT11::getHumidity() const{
  return data[0];
}