#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
const uint8_t B_TX = 9;
const uint8_t B_RX = 10;
SoftwareSerial BT(B_TX, B_RX);// Definimos los pines RX y TX del Arduino conectados al Bluetooth

#define btn_a 2
#define btn_b 3
#define btn_c 4
#define btn_d 5
#define btn_e 6
#define btn_f 7
#define btn_k 8

#define eje_x A0
#define eje_y A1

void setup()
{
    init_joystick();
    BT.begin(9600); 
    Serial.begin(9600);
}
void loop()
{
  int Eje_x = analogRead(eje_x);
  int Eje_y = analogRead(eje_y);
  if(Eje_x<400 && Eje_y>600)
  {
    BT.write('1');
  }
  else if(Eje_x<400 && Eje_y<400)
  {
    BT.write('7');
  }
  else if(Eje_x>600 && Eje_y<400)
  {
    BT.write('9');
  }
  else if(Eje_x>600 && Eje_y>600)
  {
    BT.write('3');
  }
  else if(Eje_x<400)
  {
    BT.write('4');
  }
  else if(Eje_x>600)
  {
    BT.write('6');
  }
  else if(Eje_y<400)
  {
    BT.write('8');
  }
  else if(Eje_y>600)
  {
    BT.write('2');
  }
  else if(!digitalRead(btn_k))
  {
    BT.write('5');
  }
  
  else
  {
    BT.write('w');
  }
  Serial.println(Eje_x);
}
void init_joystick()
{
    pinMode(btn_a, INPUT_PULLUP);
    pinMode(btn_b, INPUT_PULLUP);
    pinMode(btn_c, INPUT_PULLUP);
    pinMode(btn_d, INPUT_PULLUP);
    pinMode(btn_e, INPUT_PULLUP);
    pinMode(btn_f, INPUT_PULLUP);
    pinMode(btn_k, INPUT_PULLUP);

}
