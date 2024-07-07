// Cristian Molano - cmola002
// Section 21
// August 4, 2021

const unsigned long period = 500; 
unsigned long lastRan;
int val = 1, 
bol = 1, t = 0, input;
const int b_size = 7;
const int b[b_size] = {2, 3, 4, 5, 9, 10, 11};

int rlp = 9;
int blp = 10;
int glp = 11;

int r = 0, g = 0, bb = 0;

void to_binary(int num){
  if(num%2 > 0){digitalWrite(2,HIGH);}
  else{digitalWrite(2,LOW);}
  if(num%4 > 1){digitalWrite(3,HIGH);}
  else{digitalWrite(3,LOW);}
  if(num%8 > 3){digitalWrite(4,HIGH);}
  else{digitalWrite(4,LOW);}
  if(num%16 > 7){digitalWrite(5,HIGH);}
  else{digitalWrite(5,LOW);}
}

void color_change(int val)
{
//We need some conditions here 
      if(val <= 255){r = val; g = 0;}
      if(val > 255 && val <= 510){g = val; bb = 0;}
      if(val > 510 && val <= 765){bb = val;}
        Serial.print(r);
        Serial.print(", ");
        Serial.print(g);
        Serial.print(", ");
        Serial.print(bb);

        analogWrite(rlp, r);
        analogWrite(glp, g);
        analogWrite(blp, bb);
}

void setup(){

    pinMode(A0, INPUT);
    pinMode(A1, INPUT);

    pinMode(rlp, OUTPUT);
    pinMode(glp, OUTPUT);
    pinMode(blp, OUTPUT);

    for(int i = 0; i < b_size; i++)
    {
        pinMode(b[i], OUTPUT);
    }
    Serial.begin(9600);
    lastRan = 0;
}

enum States{INIT, S0, S1} state = INIT;
void Tick(){

    int n;
    Serial.print("val: ");
    Serial.print(val);
    Serial.print(" n: ");
    Serial.print(n);
    Serial.print(" input: ");
    Serial.print(input);
    Serial.print(" bol: ");
    Serial.println(bol);
    float value, pot_input;
    
    switch(state){
      case INIT:    
            state = S0;
        break;
      case S0:
            input = analogRead(A1);
            pot_input = analogRead(A0);
            value = pot_input * (765.5/1024.0);
            n = round(value);
            state = S1;
        break;
      case S1:
            input = analogRead(A1);
            pot_input = analogRead(A0);
            value = pot_input * (765.5/1024.0);
            n = round(value);
            state = S0;
        break;
      default:
        break;
    }
    switch(state){ 
      case INIT:
        break;
      case S0:
        if(input > 100){val = 0;}
        if(input > 200){val = 1;}
        if(input > 300){val = 3;}
        if(input > 400){val = 7;}
        if(input > 500){val = 15;}
        to_binary(val);
        color_change(n);
        break;
      case S1:
        if(input > 100){val = 0;}
        if(input > 200){val = 1;}
        if(input > 300){val = 3;}
        if(input > 400){val = 7;}
        if(input > 500){val = 15;}
        to_binary(val);
        color_change(n);
        break;
     default:
        break;
    }
}

void loop(){ 
  if ((millis() - lastRan) > period - t) {
    Tick(); 
    lastRan = millis();
  }  
}
