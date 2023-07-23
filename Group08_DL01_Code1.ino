#include <VirtualWire.h>

void setup()
{
    vw_set_rx_pin(11);
    vw_setup(2000);
    vw_rx_start();
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(3,  OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
    analogWrite(3, 120);
    analogWrite(5, 120);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='f')
      {  
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        Serial.println("Forward");
      }  
      else if(buf[0]=='b')
      {
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        Serial.println("Backward");
      }
      else if(buf[0]=='l')
      {
        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        Serial.println("Left");
      }
      else if(buf[0]=='r')
      {
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        Serial.println("Right");
      }
      else
      {
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, LOW);
        Serial.println("STOP");
      }
    }
t}
