
#include <SoftwareSerial.h>

#define ARDUINO_RX 6//TX
#define ARDUINO_TX 5//RX
SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);

static int8_t Send_buf[8] = {0} ;

#define CMD_SET_VOLUME 0X06
#define CMD_PLAY_W_INDEX 0X08
#define CMD_SEL_DEV 0X09
  #define DEV_TF 0X02
#define CMD_PLAY 0X0D
#define CMD_PAUSE 0X0E
#define CMD_SINGLE_CYCLE 0X19
  #define SINGLE_CYCLE_ON 0X00
  #define SINGLE_CYCLE_OFF 0X01
#define CMD_PLAY_W_VOL 0X22

void setup() 
{
 mySerial.begin(9600);
  
}
void loop() 
{
  while(1)
  {
     
  delay(500);/
    sendCommand(CMD_SEL_DEV, DEV_TF); 
  //wait for 200ms
sendCommand(CMD_PLAY_W_VOL, 0X0F01);
delay(10000);
}

}

void sendCommand(int8_t command, int16_t dat)
{
  delay(20);
  Send_buf[0] = 0x7e; 
  Send_buf[1] = 0xff; 
  Send_buf[2] = 0x06; 
  Send_buf[3] = command; 
  Send_buf[4] = 0x00;
  Send_buf[5] = (int8_t)(dat >> 8);
  Send_buf[6] = (int8_t)(dat);
  Send_buf[7] = 0xef; 
  for(uint8_t i=0; i<8; i++)
  {
    mySerial.write(Send_buf[i]) ;
  }
}
