#define SSID "SJH hotspot"       //"공유기의 SSID"  

#define PASSWORD "asdfghjk"    //"공유기의 비밀번호"  

#define SERVERIP "sungjjss9707.dothome.co.kr"  //"서버 아이피"
#define Storename "준혁이집"
#define port "80"
int flag = 1;
int pir_first = 2;
int pir_second = 3;
int nowsensor1=0;
int nowsensor2=0;
int jeonsensor1=0;
int jeonsensor2=0;
int turnon1;
int turnon2;
int numofpeople=0;
void setup()
{
  // Open Serial1 communications and wait for port to open:
  pinMode(pir_first, INPUT);
  pinMode(pir_second, INPUT);
  
  
  Serial3.begin(115200);
  Serial3.setTimeout(5000);
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

void countnumofpeople(){
  nowsensor1 = digitalRead(pir_first);
  nowsensor2 = digitalRead(pir_second);
  if(nowsensor1==1&&jeonsensor1==0){
    turnon1 = 1;
    Serial.println("1번켜짐");
    if(turnon2==1){
      Serial.println("사람수1감소");
      numofpeople--;
      turnon1=0;
      turnon2=0;
    }
  }
  if(nowsensor2==1&&jeonsensor2==0){
    turnon2 = 1;
    Serial.println("2번켜짐");
    if(turnon1==1){
      Serial.println("사람수1증가");
      numofpeople++;
      turnon1=0;
      turnon2=0;
    }
  }

  Serial.print("사람수 : ");
  Serial.println(numofpeople);
  jeonsensor1 = nowsensor1;
  jeonsensor2 = nowsensor2;
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
    cmd+= flag;
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

void loop()
{
  countnumofpeople();
  printnumofpeople();
}
