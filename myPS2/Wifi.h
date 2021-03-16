///*
//    Wireless Serial using UDP ESP8266
//    Hardware: NodeMCU
//    Circuits4you.com
//    2018
//    Slave Board connects to Access Point
//*/
//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
//
//const char *ssid = "circuits4you";
//const char *pass = "password"; 
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
////======================================================================
////                Setup
////======================================================================
//void WifiInit()
//{
//
//    Serial.println();
//    WiFi.begin(ssid, pass);   //Connect to access point
//  
//    Serial.println("");
//
//  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    digitalWrite(LED_BUILTIN, LOW);
//    delay(250);
//    digitalWrite(LED_BUILTIN, HIGH);
//    delay(250);
//    Serial.print(".");    
//  }
//  
//  digitalWrite(LED_BUILTIN, HIGH);
//  Serial.println("");
//  Serial.print("Connected to ");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
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
//    if (!cb) 
//    {
//      //If serial data is recived send it to UDP
//      if(Serial.available()>0)
//        {
//        udp.beginPacket(ServerIP, 2000);  //Send Data to Master unit
//        //Send UDP requests are to port 2000
//        
//        char a[1];
//        a[0]=char(Serial.read()); //Serial Byte Read
//        udp.write(a,1); //Send one byte to ESP8266 
//        udp.endPacket();
//        }
//    }
//    else {
//      // We've received a UDP packet, send it to serial
//      udp.read(packetBuffer, 1); // read the packet into the buffer, we are reading only one byte
//      Serial.print(packetBuffer);
//      delay(20);
//    }
//}
////=======================================================================









#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "lenovo";
const char* password = "44567890";

IPAddress local_IP(192,168,43,207);

int k=0;
int r=0;
int h=0;

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
char  replyPacket[] = "Hi there! Got the message :-)";  // a reply string to send back
bool state = false;

void WifiInit()
{
  //Serial.begin(115200);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    state = !state;
    digitalWrite(LED_BUILTIN, state);
  }
  Serial.println(" connected");
  digitalWrite(LED_BUILTIN, LOW);

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}

