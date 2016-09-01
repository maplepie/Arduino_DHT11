# Arduino_DHT11
>##DHT11(pin)
**Syntax**
```
DHT11 dht11(pin);
```
**Parameters**   
```pin  ```the number of the pin

>##DHT11.requestData()
**Syntax**
```
byte code = DHT11.requestData();
```
**Parameters**   
**Returns**  
```code  ```0:get response,1:no response,2:data no correct  

>##DHT11.getTemperature()
**Syntax**
```
byte temperature = DHT11.getTemperature();
```
**Parameters**   
**Returns**  
```temperature  ```get the temperature

>##DHT11.getHumidity()
**Syntax**
```
byte humidity = DHT11.getHumidity();
```
**Parameters**   
**Returns**  
```humidity  ```get the humidity
