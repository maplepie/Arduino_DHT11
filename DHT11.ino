const byte pin = 2;
byte data[5];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  request();
  if(getResponse()){
    String str = "Temperture : " + String(getTemperture()) + "C , Humidity : " + String(getHumidity()) + "%";
    Serial.println(str);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void request() {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delayMicroseconds(100);
  digitalWrite(pin, LOW);
  delay(20);
  digitalWrite(pin, HIGH);
  delayMicroseconds(20);
  pinMode(pin, INPUT_PULLUP);
  delayMicroseconds(60);


}

boolean getResponse() {
  if (digitalRead(pin) != 0) {
    Serial.println("No Response");
    return false;
  }
  delayMicroseconds(40);


  unsigned long duration;
  for (byte j = 0; j < 5; j++) {
    byte temp = 0;
    for (int i = 7; i >= 0; i--) {
      duration = 0;
      duration = pulseIn(pin, HIGH,150);
      if (duration > 30) {
        bitWrite(temp, i, 1);
      }
    }
    data[j] = temp;

  }

if(data[4]!=data[0]+data[2]){
  Serial.println("Data not Correct");
  return false;
}
  
  return true;
}

byte getTemperture(){
  return data[2];
}

byte getHumidity(){
  return data[0];
}
