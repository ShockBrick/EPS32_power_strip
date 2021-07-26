//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial
#include "DHT.h"
#include "BluetoothSerial.h"

#define DHTPIN 4  

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


//Power sockets
#define PS1  19
#define PS2  18
#define PS3  25
#define PS4  33


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

String message = "";
char incomingChar;
String temperature_humidity_String ="";

unsigned long previousMillis = 0;
const long interval = 10000;


void setup() {
  pinMode (PS1, OUTPUT);
  pinMode (PS2, OUTPUT);
  pinMode (PS3, OUTPUT);
  pinMode (PS4, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("Power Strip 1"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
   dht.begin();
}

void loop() {
   float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    temperature_humidity_String = "Temperatura wynosi: "+ String(t) + " C "+ "a, wilgotność wynosi: "+String(h)+" %";
    SerialBT.println(temperature_humidity_String);
}

if(SerialBT.available())
{
  if (message.length()==3)
  message="";

  
  char incomingChar = SerialBT.read();
  if(incomingChar != '\n'){
    message+=String (incomingChar);}
    else
    {message="";}
    Serial.println(message);
  }
  if (message =="1_0"){digitalWrite(PS1,LOW);Serial.println("Low");}
  else if (message =="1_1"){digitalWrite(PS1,HIGH);Serial.println("High");}
  else if (message =="2_0"){digitalWrite(PS2,LOW);}
  else if (message =="2_1"){digitalWrite(PS2,HIGH);}
  else if (message =="3_0"){digitalWrite(PS3,LOW);}
  else if (message =="3_1"){digitalWrite(PS3,HIGH);}
  else if (message =="4_0"){digitalWrite(PS4,LOW);}
  else if (message =="4_1"){digitalWrite(PS4,HIGH);}
  delay(20);
}
