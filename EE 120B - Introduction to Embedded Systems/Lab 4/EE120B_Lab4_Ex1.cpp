// Cristian Molano - cmola002
// Section 21
// August 18, 2021

// Teacher's note: The following global variables are used to implement SynchSM
// functionality using the Arduino API. In contrast the zyBook,
// the Arduino API does not provide the programmer with direct
// access to Timer Interrupt functions. 

const unsigned long period = 900; 
unsigned long lastRan;

int val = 1,
bol = 1;
const int b_size = 7;
const int b[b_size] = {2, 3, 4, 5, 9, 10, 11};

void to_binary(int num)//converts from decimal to binary
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
    Serial.print(" bol: ");
    Serial.println(bol);
    switch(state){
      case INIT:    
            state = S0;
        break;
      case S0:
            state = S1;
        break;
      case S1:
            state = S0;
        break;
      default:
        break;
    }

    // State Actions
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
//ta note:  
  // We track time explicitly in the loop() function,which is different that the Timer Interrupt mechanism 
// introduced in the zyBook
  if ((millis() - lastRan) > period) {
    Tick(); 
    lastRan = millis();
  }  
}
