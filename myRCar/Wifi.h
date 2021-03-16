///*
//    Wireless Serial using UDP ESP8266
//    Hardware: NodeMCU
//    Circuits4you.com
//    2018
//    Master Board creates Access Point
//*/
//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//
//const char *ssid = "circuits4you";
//const char *pass = "password"; 
//char ch[2];
//
//unsigned int localPort = 4210; // local port to listen for UDP packets
//
//IPAddress ServerIP(192,168,4,1);
//IPAddress ClientIP(192,168,4,2);
//
//// A UDP instance to let us send and receive packets over UDP
//WiFiUDP udp;
//
//char packetBuffer[9];   //Where we get the UDP data
//char buttonstate;
//
////=======================================================================
////                Setup
////=======================================================================
//void WifiInit()
//{
//    
//    Serial.println();
//    WiFi.softAP(ssid, pass);    //Create Access point
//
//    //Start UDP
//    Serial.println("Starting UDP");
//    udp.begin(localPort);
//    Serial.print("Local port: ");
//    Serial.println(udp.localPort());
//}
////======================================================================
////                MAIN LOOP
////======================================================================
//void loop2()
//{
//    int cb = udp.parsePacket();
//    
//    if(cb){
//      // We've received a UDP packet, send it to serial
//      udp.read(packetBuffer, 1); // read the packet into the buffer, we are reading only one byte
//      Serial.print(packetBuffer);
//      buttonstate = *packetBuffer;
//      delay(20);
//    }
//   //Serial.println(buttonstate);
//}
////======================================================================

















#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "lenovo";
const char* password = "44567890";

IPAddress local_IP(192,168,43,72);

int k=0;
int r=0;
int h=0;
char buttonstate;
WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back
bool state = false;

void WifiInit()
{
  //Serial.begin(115200);
  Serial.println();
  pinMode(D0, OUTPUT);
  digitalWrite(D0, 0);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    state = !state;
    digitalWrite(D0, state);
  }
  Serial.println(" connected");
  digitalWrite(D0, LOW);

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop2()
{


  
//    k=millis();
//    Udp.beginPacket(local_IP, localUdpPort);
//    Udp.write(k);
//    Udp.endPacket();
//    while(1){
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
  }
//    r=millis();
// break;
//  }}
//  h=r-k;
//  Serial.println(h);
  
}
