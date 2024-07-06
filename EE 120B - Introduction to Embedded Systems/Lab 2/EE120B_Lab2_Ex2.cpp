// Cristian Molano - cmola002
// Section 21
// January 28, 2021

int B[4] = {2, 3, 4, 5};
int PD = 6;
int PU = 7;

int delay_num = 250;

void setup() {

  // put your setup code here, to run once:

  for (int i = 0; i < 4; i++) {
    pinMode(B[i], OUTPUT);
  }
  pinMode(PD, INPUT);
   pinMode(PU, INPUT_PULLUP);
  Serial.begin(9600);
}

void check_delay()
{
  byte X, Y;
  Y = digitalRead(PU);
  X = digitalRead(PD);

  //lights();
  
  if(Y == LOW)
  {
    if(delay_num != 1250)
    {
      delay_num = delay_num + 500;
    }
  }
  if(X == HIGH)
  {
    if(delay_num != 250)
    {
      delay_num = delay_num - 500;
    }
  }
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.println(delay_num);
  
  for (int i = 0; i < 4; i++) {
      check_delay();
      delay(delay_num);
      digitalWrite(B[i], HIGH);
    }
   check_delay();
    for (int i = 5; i > -1; i--) {
      check_delay();
      delay(delay_num);
      digitalWrite(B[i], LOW);
    }
    
  
}
