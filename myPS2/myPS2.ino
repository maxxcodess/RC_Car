#include "PS2.h"
#include "Wifi.h"

unsigned char button;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  PS2Init();
  WifiInit();
}

void loop() {
  if(error == 1) //skip loop if no controller found
    return; 
  
  else { //DualShock Controller
  ps2x.read_gamepad(false, vibrate);

  if(ps2x.Button(PSB_PAD_UP)) {      //will be TRUE as long as button is pressed
      Serial.print("Up held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
      button = 'U';    
      Serial.print('U');  
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("Right held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
      button = 'R';  
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
      button = 'L';  
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
      button = 'D';  
    }   

  if(ps2x.ButtonPressed(PSB_CIRCLE)){               //will be TRUE if button was JUST pressed
        Serial.println("Circle just pressed");
        button = 'C';
      }
  if(ps2x.ButtonPressed(PSB_CROSS)) {              //will be TRUE if button was JUST pressed OR released
        Serial.println("X just changed");
        button = 'X';
      }
  if(ps2x.ButtonPressed(PSB_SQUARE))  {            //will be TRUE if button was JUST released
        Serial.println("Square just released");
        button = 'S';
      }
  if(ps2x.Button(PSB_TRIANGLE))  {            //will be TRUE if button was JUST released
        Serial.println("Triangle just released");
        button = 'T';
      }
  if(ps2x.Button(PSB_R1))  {
        button = '\n';
      }
  if(ps2x.Button(PSB_CIRCLE)  &&  ps2x.Button(PSB_PAD_UP)){
        Serial.println("turn right");
        button = 'R';
      }
  if(ps2x.Button(PSB_SQUARE)  &&  ps2x.Button(PSB_PAD_UP))  {
        Serial.println("turn left");
        button = 'L';
      }
  if(ps2x.Button(PSB_CIRCLE)  &&  ps2x.Button(PSB_PAD_DOWN)){
        Serial.println("turn right");
        button = 'F';
      }
  if(ps2x.Button(PSB_SQUARE)  &&  ps2x.Button(PSB_PAD_DOWN))  {
        Serial.println("turn left");
        button = 'J';
      }
      
  if(ps2x.Analog(PSS_LY) < 100)
        button = 'U';
  
  if(ps2x.Analog(PSS_LY) > 150)         //0  125  255  'thoda ulta-pulta hai'
        button = 'D';
        
  if(ps2x.Analog(PSS_LY) > 150  &&  ps2x.Analog(PSS_RX) < 100)  
        button = 'J';
  if(ps2x.Analog(PSS_LY) > 150  &&  ps2x.Analog(PSS_RX) > 150)  
        button = 'F';
  if(ps2x.Analog(PSS_LY) < 100  &&  ps2x.Analog(PSS_RX) < 100)  
        button = 'L';
  if(ps2x.Analog(PSS_LY) < 100  &&  ps2x.Analog(PSS_RX) > 150)  
        button = 'R';
      
  }
                                 //  int cb = udp.parsePacket();
                                 //    if (!cb && button != '/') {
  if (button != '/') {
     Udp.beginPacket(local_IP, localUdpPort);
     Udp.write(button);
     Udp.endPacket();    
     yield(); 
     button = '/';
   }
  delay(50);
  }
