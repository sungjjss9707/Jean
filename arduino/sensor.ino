//int a = 0;
int flag = 1;
int pir_first = 2;
int pir_second = 3;
int nowsensor1=0;
int nowsensor2=0;
int jeonsensor1=0;
int jeonsensor2=0;
int turnon1;
int turnon2;
int jeonnumofpeople=0;
int numofpeople=0;
int creaseflag=-1;
void setup() {
  // put your setup code here, to run once:
  pinMode(pir_first, INPUT);
  pinMode(pir_second, INPUT);
  Serial.begin(9600);
  Serial3.begin(9600);
}


void countnumofpeople(){
  nowsensor1 = digitalRead(pir_first);
  nowsensor2 = digitalRead(pir_second);
  if(nowsensor1==1&&jeonsensor1==0){
    turnon1 = 1;
    Serial.println("1번켜짐");
    if(turnon2==1){
      Serial.println("사람수1감소");
      creaseflag = 0;
      numofpeople--;
      turnon1=0;
      turnon2=0;
    }
  }
  if(nowsensor2==1&&jeonsensor2==0){
    turnon2 = 1;
    Serial.println("2번켜짐");
    if(turnon1==1){
      creaseflag= 1;
      Serial.println("사람수1증가");
      numofpeople++;
      turnon1=0;
      turnon2=0;
    }
  }
  //Serial.write(numofpeople);
  //Serial.print("사람수 : ");
  //Serial.println(numofpeople);
  jeonsensor1 = nowsensor1;
  jeonsensor2 = nowsensor2;
}


void loop() {
  // put your main code here, to run repeatedly:
  countnumofpeople();
  if(jeonnumofpeople!=numofpeople){
    Serial3.write(numofpeople);
    Serial3.write(creaseflag);
    Serial.println(numofpeople);
  }
  
  //a=a+1;
  
  jeonnumofpeople=numofpeople;
}
