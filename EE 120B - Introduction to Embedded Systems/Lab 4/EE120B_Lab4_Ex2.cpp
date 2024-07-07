// Cristian Molano - cmola002
// Section 21
// August 18, 2021

const unsigned long period = 500; 
unsigned long lastRan;

int val = 1, 
bol = 1, t = 0;
const int b_size = 7;
const int b[b_size] = {2, 3, 4, 5, 9, 10, 11};

void to_binary(int num)         // we need to convert the decimal to binary!
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

void setup(){
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);

    for(int i = 0; i < b_size; i++)
    {
        pinMode(b[i], OUTPUT);
    }
    Serial.begin(9600);
    lastRan = 0;
}

enum States{INIT, S0, S1} state = INIT; 
void Tick(){

    Serial.print("val: ");
    Serial.print(val);
    Serial.print(" t: ");
    Serial.print(t);
    Serial.print(" bol: ");
    Serial.println(bol);
    float value, 
    pot_input;
    int n;
    switch(state){
      case INIT:    
            state = S0;
        break;
      case S0:
            pot_input = analogRead(A0);
            value = pot_input * (4.5/1024.0);
            n = round(value);
            t = n * 100;
            state = S1;
        break;
      case S1:
            pot_input = analogRead(A0);
            value = pot_input * (4.5/1024.0);
            n = round(value);
            t = n * 100;
            state = S0;
        break;
      default:
        break;
    }

    switch(state){ 
      case INIT:
        break;
      case S0:
        if(bol == 1)
        {
          if(val == 8){bol=0;val = val/2;}
          else{val = val * 2;}
        }
        else if(bol == 0) 
        {
          if(val == 1){bol=1;val = val * 2;}
          else{val = val/2;}
        }
        to_binary(val);;
        break;
      case S1:
        if(bol == 1)
        {
          if(val == 8){bol=0;val = val/2;}
          else{val = val * 2;}
        }
        else if(bol == 0) 
        {
          if(val == 1){bol=1;val = val * 2;}
          else{val = val/2;}
        }
        to_binary(val);
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
