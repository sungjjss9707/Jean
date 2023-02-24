#define SSID "SJH hotspot"       //"공유기의 SSID"  

#define PASSWORD "asdfghjk"    //"공유기의 비밀번호"  

#define SERVERIP "sungjjss9707.dothome.co.kr"  //"서버 아이피"
#define Storename "거기자리있소?"
#define port "80"
int flag = 1;
int jeonnumofpeople = 0;
int nownumofpeople = 0;
int numofpeople=0;

void setup()
{
  // Open Serial1 communications and wait for port to open:

 
  Serial3.begin(115200);
  Serial3.setTimeout(5000);
  Serial2.begin(9600);
  Serial.begin(9600); 
  Serial.println("ESP8266 AT command test");
  boolean connected=false;  
   for(int i=0;i<10;i++)  
   {  
       if(connectWiFi())  
       {  
         connected = true;  
         break;  
       }  
   }  
     
   if (!connected){while(1);}  
   delay(5000);  
    
   Serial.println("AT+CIPMUX=0"); 
  
}


boolean connectWiFi()  
{  
   //mySerial.println("AT+CWMODE=1");  
     
   String cmd="AT+CWJAP=\"";  
   cmd+=SSID;  
   cmd+="\",\"";  
   cmd+=PASSWORD;  
   cmd+="\"";  
   Serial3.println(cmd);  
   Serial.println(cmd);  
   delay(3000);  
    
   if(Serial3.find("OK"))  
   {  
     Serial.println("OK, Connected to WiFi.");  
     return true;  
   }  
   else  
   {  
     Serial.println("Can not connect to the WiFi.");  
     return false;  
   }  
 }  

void printnumofpeople(){
     String cmd = "AT+CIPSTART=\"TCP\",\"";  
     cmd += SERVERIP;  
     cmd += "\",";
     cmd += port;  
     Serial.println(cmd);  
     Serial3.println(cmd);  
     if(Serial3.find("Error"))  
    {  
      Serial.println( "TCP connect error" );  
      return;  
    }  
    char test[20];  
    //String temp(floatToString(test,tempC, 2, 0));  
    String temp = (String)numofpeople;  
    cmd = "GET /insert_data.php?num=";
    cmd+= numofpeople;
    cmd+= "&storename=";
    cmd+= Storename;
    flag++;
    cmd += " HTTP/1.0\r\nHost: sungjjss9707.dothome.co.kr\r\n\r\n\r\n";
    Serial3.print("AT+CIPSEND=");  
    Serial3.println(cmd.length());  
    //Serial.println(cmd.length());      
       
    //Serial.println(cmd);  
       
       
    if(Serial3.find(">")){  
       Serial.print(">");  
    }
    else{  
       Serial3.println("AT+CIPCLOSE");  
       Serial.println("connect timeout");  
       delay(1000);  
       return;  
    }  
         
    Serial3.print(cmd);
    //erial.println(cmd);  
    delay(500);  
    //Serial.find("+IPD");
    //Serial.println(Serial.available()); 
    
    while (Serial.available()){
      //Serial.println("2  fuckk");   
      char c = Serial.read();  
      Serial3.write(c);
       
      if(c=='\r') Serial3.print('\n');  
    }  
    
    Serial.println("====");  
    delay(1000);
}

void getnumber(){
  if(Serial2.available())
  {
      nownumofpeople = Serial2.read();
      numofpeople = nownumofpeople;
      Serial.print("사람수 : ");
      Serial.println(numofpeople);
      //jeonnumofpeople-nownumofpeople>10 || nownumofpeople-jeonnumofpeople>10
      
      /*if(nownumofpeople>100){
        //numofpeople = jeonnumofpeople;
        //Serial.print("사람수 : ");
        //Serial.println(numofpeople);
      }
      else{
        numofpeople = nownumofpeople;
        Serial.print("사람수 : ");
        Serial.println(numofpeople);
      }
      */
  }
  jeonnumofpeople = nownumofpeople;
}
void loop()
{
  getnumber();
  printnumofpeople();
}
