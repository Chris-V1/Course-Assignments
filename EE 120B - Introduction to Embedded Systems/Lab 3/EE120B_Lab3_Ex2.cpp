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

enum States {INIT, S0} state = INIT;

void Tick() {
  switch (state) { // State transitions
    case INIT:
      //our first state transition!
      state = S0;
      break;

    case S0:
      if (millis() > last_update) {
        last_update = millis();
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
        state = S0;
      }
      break;

  }

  switch (state) {
    case INIT:
      //State Action
      break;

    case S0:
      //State Action
      Serial.print(r);
        Serial.print(", ");
        Serial.print(g);
        Serial.print(", ");
        Serial.print(b);
        Serial.print(", counter:");

        Serial.print(counter);
        Serial.println("");

      analogWrite(rlp, r);
      analogWrite(glp, g);
      analogWrite(blp, b);
      break;
  }
}

void loop() { //no changes here
  Tick();
}
