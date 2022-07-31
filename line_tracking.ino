int PinMa=4;
int PWMa=5;
int PinMb=7;
int PWMb=6;

const int ldr1 = A0;
const int ldr2 = A1;
const int ldr3 = A2;
const int ldr4 = A3;
const int ldr5 = A4;

int DS_1=0;
int DS_2=0;
int DS_3=0;
int DS_4=0;
int DS_5=0;

void move (int x, int y){
  digitalWrite (PinMa,HIGH);
  analogWrite(PWMa,y);
  digitalWrite (PinMb,HIGH);
  analogWrite(PWMb,x);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

pinMode(PinMa, OUTPUT);
pinMode(PWMa, OUTPUT);
pinMode(PinMb, OUTPUT);
pinMode(PWMb, OUTPUT);

pinMode(ldr1, INPUT);
pinMode(ldr2, INPUT);
pinMode(ldr3, INPUT);
pinMode(ldr4, INPUT);
pinMode(ldr5, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

DS_1 = digitalRead(ldr1);
DS_2 = digitalRead(ldr2);
DS_3 = digitalRead(ldr3);
DS_4 = digitalRead(ldr4);
DS_5 = digitalRead(ldr5);

if (DS_1 == 0 &&DS_2 == 1 && DS_3 == 1 && DS_4 == 1 && DS_5 == 0||DS_1 == 0 &&DS_2 == 0 && DS_3 == 1 && DS_4 == 0 && DS_5 == 0){
  move(120,120);
}

else if (DS_2 == 0 && DS_3 == 0 && DS_4 == 0 && DS_1 == 0 && DS_5 == 0) { // semicircule

  while(DS_3==0){  
  move(80,80);
  DS_3 = digitalRead(ldr3);
}


}

else if (DS_2 == 1 && DS_3 == 1 && DS_4 == 1 && DS_1 == 1 && DS_5 == 1) { // semicircule

  while(DS_1==1 && DS_5==1){  
  move(80,80);
  DS_1 = digitalRead(ldr1);
  DS_5 = digitalRead(ldr5);
} 
if (DS_1==0 &&DS_5==1){
  move(100,50);
  }
  else if (DS_1==1 &&DS_5==0){
  move(50,100);
  }
  else {
  move(120,120);
  }
}

else if (DS_2 == 1 && DS_3 == 1 && DS_4 == 0){
  move(115,120);
}

else if (DS_2 == 0 && DS_3 == 1 && DS_4 == 1){
  move (120,115);
}

else if (DS_2 == 0 && DS_3 == 0 && DS_4 == 1) { // elf 4mal
while(DS_3==0){
  move(100,15);
  DS_3 = digitalRead(ldr3);
  if(DS_4==0){
    break;
  }
} 
}
else if (DS_2 == 1 && DS_3 == 0 && DS_4 == 0) { // elf emen
while(DS_3==0){
  move(15,100);
  DS_3 = digitalRead(ldr3);
  if(DS_2==0){
    break;
  }
}
}

}
