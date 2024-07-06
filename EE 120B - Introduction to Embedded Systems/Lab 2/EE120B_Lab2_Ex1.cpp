// Cristian Molano - cmola002
// Section 021
// January 21, 2021

int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

void setup() {

  // put your setup code here, to run once:

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  pinMode(PD, INPUT);
   pinMode(PU, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  byte X, Y;
  Y = digitalRead(PU);
  X = digitalRead(PD);

  if(Y == LOW)
  {
    for (int i = 0; i < 4; i++) 
    {
      digitalWrite(B[i], HIGH);
    }
  }
  if(X == HIGH)
  {
    for (int i = 0; i < 4; i++) 
    {
      digitalWrite(B[i], LOW);
    }
  }
}