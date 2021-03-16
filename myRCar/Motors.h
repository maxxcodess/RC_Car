#define  IN1  D7 //13
#define  IN2  D6 //12
#define  IN3  D3
#define  IN4  D2
#define  PWM1 D8
#define  PWM2 D5

#define LED_BUILTI  D0

void stopbot() {
    digitalWrite(IN1, 0);     //  D7
    digitalWrite(IN2, 0);     //  D6
    digitalWrite(IN3, 0);     //  D3
    digitalWrite(IN4, 0);     //  D4
}

void MotorsInit() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWM2, OUTPUT);
  
  pinMode(LED_BUILTI, OUTPUT);
  //Serial.begin(115200);
}


void parsPacket() {
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets
   int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf(incomingPacket);
    buttonstate = incomingPacket[0];
    Serial.println(buttonstate);

  if(buttonstate == 'U') {
    digitalWrite(IN1, 1);     //  D7
    digitalWrite(IN2, 0);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }
  
  if(buttonstate == 'R') {    
    digitalWrite(IN3, 0);     //  D3
    digitalWrite(IN4, 1);     //  D4
    analogWrite(PWM2, 20000);   //  D5
    digitalWrite(IN1, 1);     //  D7
    digitalWrite(IN2, 0);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }
  
  if(buttonstate == 'L') {    
    digitalWrite(IN3, 1);     //  D3
    digitalWrite(IN4, 0);     //  D4
    analogWrite(PWM2, 20000);   //  D5
    digitalWrite(IN1, 1);     //  D7
    digitalWrite(IN2, 0);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }
  
  if(buttonstate == 'D') {
    digitalWrite(IN1, 0);     //  D7
    digitalWrite(IN2, 1);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }

  if(buttonstate == 'F') {
    digitalWrite(IN3, 0);     //  D3
    digitalWrite(IN4, 1);     //  D4
    analogWrite(PWM2, 20000);   //  D5
    digitalWrite(IN1, 0);     //  D7
    digitalWrite(IN2, 1);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }

  if(buttonstate == 'J') {
    digitalWrite(IN3, 1);     //  D3
    digitalWrite(IN4, 0);     //  D4
    analogWrite(PWM2, 20000);   //  D5
    digitalWrite(IN1, 0);     //  D7
    digitalWrite(IN2, 1);     //  D6
    analogWrite(PWM1, 40000);  //  D8
  }

  digitalWrite(D4,LOW);
  delay(50);
  }
  
  else {
    stopbot();
    digitalWrite(D4,HIGH);
  }
}

void parsPacket1() {
//  if(udp.parsePacket()) {
//      udp.read(packetBuffer, 1); // read the packet into the buffer, we are reading only one byte
//      yield();
//      //Serial.print(packetBuffer);
//      buttonstate = *packetBuffer;
int i=0;
int packetSize = Udp.parsePacket();
if (packetSize)
{
//  Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
  int len = Udp.read(incomingPacket, 255);
  if (len > 0)
  {
    incomingPacket[len] = '\0';
  }
  while(i<len){
   if(incomingPacket[i] == 'U'){
//
//  if(buttonstate == 'U') {
//    digitalWrite(IN1, 0);     //  D7
//    digitalWrite(IN2, 1);     //  D6
//    analogWrite(PWM1, 40000);  //  D8
//  }
//  
//  if(buttonstate == 'R') {    
//    digitalWrite(IN3, 0);     //  D3
//    digitalWrite(IN4, 1);     //  D4
//    analogWrite(PWM2, 20000);   //  D5
//  }
//  
//  if(buttonstate == 'L') {    
//    digitalWrite(IN3, 1);     //  D3
//    digitalWrite(IN4, 0);     //  D4
//    analogWrite(PWM2, 20000);   //  D5
//  }
//  
//  if(buttonstate == 'D') {
//    digitalWrite(IN1, 1);     //  D7
//    digitalWrite(IN2, 0);     //  D6
//    analogWrite(PWM1, 40000);  //  D8
//  }

  digitalWrite(D4,LOW);
  i++;
   }
   delay(20);
   digitalWrite(D4,HIGH);
  }
  i=0;
 }
  
  else {
    stopbot();
    digitalWrite(D4,HIGH);
  }
}



void loop1() {
  //forward
  digitalWrite(IN1, 0);     //  D7
  digitalWrite(IN2, 1);     //  D6
  analogWrite(PWM1, 500);  //  D8
  
  digitalWrite(IN3, 0);     //  D3
  digitalWrite(IN4, 1);     //  D4
  analogWrite(PWM2, 500);   //  D5
    
  //blink led
  digitalWrite(LED_BUILTI, HIGH);
  delay(100);
  digitalWrite(LED_BUILTI, LOW);
  delay(100);
  
}
