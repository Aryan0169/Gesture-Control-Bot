#include <VirtualWire.h>

char *data;
int m = 0, n = 0;
int x_val, y_val, z_val;

void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  x_val = analogRead(A1);
  y_val = analogRead(A2);
  z_val = analogRead(A3);
  Serial.begin(9600);
}

void loop()
{
  m = analogRead(A1); //x
  n = analogRead(A2); //y
  Serial.println(m);
  Serial.println(n);
  if(n - y_val > 70) // forward motion
  {
    Serial.println("Forward");
    data="f";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
    else if(y_val - n > 70)
  {
    Serial.println("Backward");
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else if( m - x_val > 70)
  {
    Serial.println("Right");
    data="r";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else if(x_val - m > 70)
  {
    Serial.println("Left");
    data="l";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  else
  {
    Serial.println("Stop");
    data="s";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
  }
  delay(500);
}
