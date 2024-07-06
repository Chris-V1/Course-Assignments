// Cristian Molano - cmola002
// Section 21
// August 11, 2021

int l1 = 5;
int l2 = 4;
int l3 = 3;
int l4 = 2;

int rlp = 9;
int blp = 10;
int glp = 11;

unsigned long last_update = 0;

int r = 245;
int g = 66;
int b = 66;

int counter = 1;
float value, 
pot_input;
int val;
int input;

void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);

  Serial.begin(9600);
}

enum States {INIT, S0, S1} state = INIT;
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
void cycle()
{
  if(counter == 1)
        {
          if(g < 245)
          {
            g = g + 10;
          }
          else{counter = 2;}
        }
        else if(counter == 2)
        {
          if(r > 66)
          {
            r = r - 10;
          }
          else
          {
            counter = 3;
          }
        }
        else if(counter == 3)
        {
          if(b < 245)
          {
            b = b + 10;
          }
          else
          {
            counter = 4;
          }
        }
        else if(counter == 4)
        {
          if(g > 66)
          {
            g = g - 10;
          }
          else
          {
            counter = 5;
          }
        }
        else if(counter == 5)
        {
          if(r < 245)
          {
            r = r + 10;
          }
          else
          {
            counter = 6;
          }
        }
        else if(counter == 6)
        {
          if(b > 66)
          {
            b = b - 10;
          }
          else
          {
            counter = 1;
          }
        }
}


void Tick() {
  switch (state) {
    case INIT:
      //State Transition
      state = S1;
      break;

    case S0:
      input = analogRead(A1);
      Serial.println(input);
      if (input < 300) 
      {
        if (millis() > last_update) {
          last_update = millis();
          cycle();
          state = S0;
        }
      }
      else
      {
        state = S1;
      }
      break;
      
    case S1:
      input = analogRead(A1);
      pot_input = analogRead(A0);
      value = pot_input * (4.5/1024.0);
      Serial.println(input);
      val = round(value);
      if (input > 300) 
      {
        //Serial.println("S0");
        Serial.println(input);
        state = S1;
      }
      else {
        state = S0;
      }
      //State Transition
      break;

  }

  switch (state) {
    case INIT:
      //State Action
      break;

    case S0:
      //State Action
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(l3, LOW);
      digitalWrite(l4, LOW);
      analogWrite(rlp, r);
      analogWrite(glp, g);
      analogWrite(blp, b);
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
  Tick();
}
