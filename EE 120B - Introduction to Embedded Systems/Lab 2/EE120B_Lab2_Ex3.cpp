// Cristian Molano - cmola002
// Section 21
// August 4, 2021

int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

float input = 0.0;

void setup() {

  // put your setup code here, to run once:

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  pinMode(PD, INPUT);
   pinMode(PU, INPUT_PULLUP);
  Serial.begin(9600);
}

void present_num(int num)
{
  if(num%2 > 0){digitalWrite(2,HIGH);}
  else{digitalWrite(2,LOW);}
  if(num%4 > 1){digitalWrite(3,HIGH);}
  else{digitalWrite(3,LOW);}
  if(num%8 > 3){digitalWrite(4,HIGH);}
  else{digitalWrite(4,LOW);}
  if(num%16 > 7){digitalWrite(5,HIGH);}
  else{digitalWrite(5,LOW);}
}

void loop() {

  // put your main code here, to run repeatedly:
  input = analogRead(A0);
  float value = input * (15.5/1024.0); //using 15.5 since that is the error margin my potentiometer has.
  present_num(round(value));
  Serial.println(round(value));
  
}
