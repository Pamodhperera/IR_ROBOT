int LeftMotorBackward=11;
int LeftMotorForward=08;
int RightMotorForward=8;
int RightMotorBackward=9;

int msh=200; //Motor Speed High
int msl=100;
//Motor Speed Low
int sm=0;

int delayturn=150;

void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);//LeftMotorBackward
  pinMode(9,OUTPUT);//LeftMotorBack
  pinMode(10,OUTPUT);//RightMotorForward
  pinMode(11,OUTPUT);//RightMotorBackward


  pinMode(22, INPUT);   
  pinMode(24,INPUT);  
  pinMode(26, INPUT); 
  pinMode(28,INPUT);  
  pinMode(30, INPUT); 
  pinMode(32,INPUT);

  moveForward();
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int s1;
  int s2;
  int s3;
  int s4;
  int s5;
  int s6;
s1=digitalRead(22);
s2=digitalRead(24);
s3=digitalRead(26);
s4=digitalRead(28);
s5=digitalRead(30);
s6=digitalRead(32);

//001100
if (s1 == LOW && s2==LOW && s3 ==HIGH && s4 == HIGH && s5 == LOW && s6 == LOW){
moveForward();
}
//001000
else if (s1 == LOW && s2==LOW && s3 ==HIGH && s4 == LOW && s5 == LOW && s6 == LOW){
moveLeft();
}

//010000
else if (s1 == LOW && s2==HIGH && s3 ==LOW && s4 == LOW && s5 == LOW && s6 == LOW){
moveLeft ();
}

//100000
else if (s1 == HIGH && s2==LOW && s3 ==LOW && s4 == LOW && s5 == LOW && s6 == LOW){
moveLeft();
}

//110000
else if (s1 == HIGH && s2==HIGH && s3 ==LOW && s4 == LOW && s5 == LOW && s6 == LOW){
moveLeft();
}

//011000
else if (s1 == LOW && s2==HIGH && s3 ==HIGH && s4 == LOW && s5 == LOW && s6 == LOW){
moveLeft();
}

//111000
else if (s1 == HIGH && s2==HIGH && s3 ==HIGH && s4 == LOW && s5 == LOW && s6 == LOW){
moveForward();
delay(200); 
moveLeftl();
delay(300);
}

//111100
else if (s1 == HIGH && s2==HIGH && s3 ==HIGH && s4 == HIGH && s5 == LOW && s6 == LOW){
moveForward();
delay(10);  
moveLeftl();
delay(100);
}
//000100
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == HIGH && s5 == LOW && s6 == LOW){
moveRight();
} 
//000010
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == LOW && s5 == HIGH && s6 == LOW){
moveRight();
} 
//000001
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == LOW && s5 == LOW && s6 == HIGH){
moveRight();
} 
//000110
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == HIGH && s5 == HIGH && s6 == LOW){
moveRight();
} 
//000011
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == LOW && s5 == HIGH && s6 == HIGH){
moveRight();
} 




//000111
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == HIGH && s5 == HIGH && s6 == HIGH){
moveForward();
delay(200);  
moveRightl();
delay(300);
} 
//001111
else if (s1 == LOW && s2==LOW && s3 ==HIGH && s4 == HIGH && s5 == HIGH && s6 == HIGH){
moveForward();
delay(200);  
moveRightl();
delay(300);
}

//111111
else if (s1 == HIGH && s2==HIGH && s3 ==HIGH && s4 == HIGH && s5 == HIGH && s6 == HIGH){
moveForward();
delay(200);
} 
//000000
else if (s1 == LOW && s2==LOW && s3 ==LOW && s4 == LOW && s5 == LOW && s6 == LOW){
moveRightl();
}

//011110
else if(s1 == LOW && s2==HIGH && s3 ==HIGH && s4 == HIGH && s5 == HIGH && s6 == LOW){
  moveForward();

  delay(200);
  
  moveRight();
  delay(400);
}
else{
  moveForward();
}
}





void moveForward(){
analogWrite(LeftMotorForward,sm);
analogWrite(RightMotorForward,sm);
analogWrite(LeftMotorBackward,msm);
analogWrite(RightMotorBackward,msm);

}
void moveRight(){
analogWrite(LeftMotorForward,msl);
analogWrite(RightMotorForward,sm);
analogWrite(LeftMotorBackward,sm);
analogWrite(RightMotorBackward,sm);

}
void moveLeft(){
analogWrite(LeftMotorForward,sm);
analogWrite(RightMotorForward,msl);
analogWrite(LeftMotorBackward,sm);
analogWrite(RightMotorBackward,sm);
}

void moveRightl(){
  digitalWrite(53,HIGH);
analogWrite(LeftMotorForward,msl);
analogWrite(RightMotorForward,sm);
analogWrite(LeftMotorBackward,sm);
analogWrite(RightMotorBackward,msl);
}

void moveLeftl(){
analogWrite(LeftMotorForward,sm);
analogWrite(RightMotorForward,msl);
analogWrite(LeftMotorBackward,msl);
analogWrite(RightMotorBackward,sm);

}

void stopMotors(){
analogWrite(LeftMotorForward,sm);
analogWrite(RightMotorForward,sm);
analogWrite(LeftMotorBackward,sm);
analogWrite(RightMotorBackward,sm);
}

void moveBack(){
analogWrite(LeftMotorForward,sm);
analogWrite(RightMotorForward,sm);
analogWrite(LeftMotorBackward,100);
analogWrite(RightMotorBackward,100);
}
