#include<SoftwareSerial.h>
SoftwareSerial obj(9,10);
unsigned char buffer[64];
int count=0;

void setup() {

obj.begin(9600);
Serial.begin(9600);
delay(100);
Serial.println("here we go!!");


}

void loop() {
  while(obj.available())
  {
    buffer[count++]=obj.read();
    if(count==64)
    break;
    
  }
 Serial.write(buffer,count);
 clearBufferArray();
 count=0;

 if(Serial.available())
 {
  byte b=Serial.read();
  if(b=='*')
  {
    obj.write(0x1a);
    
  }
  else
  {
    obj.write(b);
  
 }
 
 }
 delay(100);

}
void clearBufferArray(){
  for(int i=0;i<count;i++)
  {
    buffer[i]=NULL;
  }
  
  
  
}
