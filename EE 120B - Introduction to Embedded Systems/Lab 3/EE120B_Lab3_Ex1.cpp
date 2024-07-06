// Cristian Molano - cmola002
// Section 21
// August 11, 2021

// Initialization
int l1 = 5;
int l2 = 4;
int l3 = 3;
int l4 = 2;

int rlp = 9;
int blp = 10;
int glp = 11;

float value, pot_input;
int val;


void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void present_num(int num)
{
  if(num >= 1)
  {
    digitalWrite(l1, HIGH);
  }
  else
  {
    digitalWrite(l1, LOW);
  }
  if(num >= 2)
  {
    digitalWrite(l2, HIGH);
  }
  else
  {
    digitalWrite(l2, LOW);
  }
  if(num >=3)
  {
    digitalWrite(l3, HIGH);
  }
  else
  {
    digitalWrite(l3, LOW);
  }
  
  if(num >= 4)
  {
    digitalWrite(l4, HIGH);
  }
  else
  {
    digitalWrite(l4, LOW);
  }
   
   
}

enum States {INIT, S0, S1} state = INIT;

// This function takes in the state as an argument & returns the current state
void Tick() {

  switch (state) { // State transitions
    int input;
    
    case INIT:
      //State Transition
      state = S0;
      break;


    case S0:
    input = analogRead(A1);
    //Serial.println(input);
    pot_input = analogRead(A0);
    value = pot_input * (4.5/1024.0);
    val = round(value);
      if (input > 400) {
        Serial.println("S1");
        Serial.println(input);
        state = S1;
      }
      else {
        state = S0;
      }
      break;

    case S1:
      input = analogRead(A1);
      pot_input = analogRead(A0);
      value = pot_input * (4.5/1024.0);
      Serial.println(input);
      val = round(value);
      if (input < 400) {
        Serial.println("S0");
        Serial.println(input);
        state = S0;
      }
      else {
        state = S1;
      }
      //State Transition
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;

    case S0:
      //State Action
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(l3, LOW);
      digitalWrite(l4, LOW);
      analogWrite(rlp, 0);
      analogWrite(glp, 0);
      analogWrite(blp, 0);
      
      break;

    case S1:
      //State Action
      present_num(val);
      analogWrite(rlp, 0);
      analogWrite(glp, 0);
      analogWrite(blp, 0);
      break;
  }
}

void loop() {

  ///Default arduino function

  Tick();
}
