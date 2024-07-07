// Cristian Molano - cmola002
// Section 21
// August 18, 2021

int i = 0;
int c = 0;
int b = 0;

int t = 0;
int ti = 0;
unsigned long lastRan ;
unsigned long period = 1; 

int IN1 = 10;
int IN2 = 11;
int IN3 = 12;
int IN4 = 13;

int UP = 3;
int DOWN = 4;
int LEFT = 2;
int RIGHT = 5;

int JS_X = A0;
int JS_Y = A1;
int JS_BTN = 7;
int sig[4] = {IN1, IN2, IN3, IN4};

int steps[8][4] {
  
  {0, 0, 0, 1},
  {0, 0, 1, 1},
  {0, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 1},

};


enum SM1_States { SM1_INIT, SM1_S0};
int SM1_Tick(int state1) {
  switch (state1) { 
    case SM1_INIT:
      state1 = SM1_S0;
      break;
    case SM1_S0:
      if (c == 4) {
        c = 0;
        if(b == 0)
        {
          i++;
          digitalWrite(LEFT, LOW);
          digitalWrite(RIGHT, HIGH);
          digitalWrite(UP, LOW);
          digitalWrite(DOWN, LOW);
        }
        else
        {
          i--;
          digitalWrite(LEFT, HIGH);
          digitalWrite(RIGHT, LOW);
          digitalWrite(UP, LOW);
          digitalWrite(DOWN, LOW);
        }

      }
      if(b == 0)
      {
        if (i == 8) {
        i = 0;

      }
      }
      else
      {
        if(i == 0)
        {
          i = 8;
        }
      }

      state1 = SM1_S0;
      break;

  }
  switch (state1) {
    case SM1_INIT:
      break;
    case SM1_S0:

      if(t == 0)
      {

      for (c; c < 4; c++) {
        if (steps[i][c] == 1) {
          digitalWrite(sig[c], HIGH);
        }
        else {
          digitalWrite(sig[c], LOW);
        }
      }
      }
      else if (t == 1)
      {
        digitalWrite(LEFT, LOW);
        digitalWrite(RIGHT, LOW);
        digitalWrite(UP, LOW);
        digitalWrite(DOWN, LOW);
      }
      break;
  }
  return state1;
}

enum SM2_States { SM2_INIT, SM2_S0};
int SM2_Tick(int state2) {
  switch (state2) { 
    case SM2_INIT:
      state2 = SM2_S0;
      break;
    case SM2_S0:
      state2 = SM2_S0;
      break;

  }
  switch (state2) { 
    case SM2_INIT:
      //State Transition
      state2 = SM2_S0;
      break;
    case SM2_S0:
      state2 = SM2_S0;
      break;

  }
  switch (state2) {
    case SM2_INIT:
      break;
    case SM2_S0:
      //digitalWrite(UP, HIGH);
      //digitalWrite(DOWN, LOW);
      //digitalWrite(LEFT, LOW);

      //digitalWrite(RIGHT, LOW);

      int j_x = analogRead(JS_X);
      int j_y = analogRead(JS_Y);
      int j_btn = digitalRead(JS_BTN);

      if(j_y < 100)
      {
        b = 1;
      }
      else if(j_y > 1000)
      {
        b = 0;
      }
      else if(j_x < 100) // down
      {
        digitalWrite(DOWN, HIGH);
        ti++;
        //t = 1;
      }
      else if(j_x > 1000) // up
      {
        digitalWrite(UP, HIGH);\

         if(ti != 0)
         {
          ti--;
         }
         
         
        //t = 0;
      }
      else if(j_btn == 0)
      {
        
        t = 1;
      }
      else if(j_btn == 1)
      {    
        t= 0;
      } 
      break;
  }

  return state2;
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);

  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);

  pinMode(JS_BTN, INPUT_PULLUP);
  Serial.begin(9600);
  lastRan = 0;
  
}
void loop(){ 
  for(int i = 0; i < 8; ++i)
  {
    if ((millis() - lastRan) > period + ti) {
      Serial.println(ti);
      SM2_Tick(i);
      SM1_Tick(i); 
      lastRan = millis();
  }
    if(i == 1)
    {
      i = 0;  
    }
  }

}
