// Cristian Molano - cmola002
// Section 21
// August 27, 2021

int red = 2, 
int blue = 3, 
int yellow = 4, 
int white = 5, 
int green = 6;

int overall = 0, 
int water, 
int ice, 
int min_light_level = 100;

bool is_on = false, is_paused = false;

void pause()
{
  if(ice < min_light_level)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    is_paused = true;
  }
  else if(water < min_light_level)
  {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(white, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    is_paused = true;   
  }
  else
  {
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    is_paused = false;
  }
}

// This is our cycle

void cycle()
{
  static unsigned long WMillis = millis(), Millis = millis();
  //Serial.println("made it here!");
    water = analogRead(A0);
    ice = analogRead(A1);
    Serial.print("water: "); Serial.print(water); Serial.print(" Ice: "); Serial.println(ice);
    pause();

    if(!is_paused)
    {
      if(overall == 0) //water
      {
        digitalWrite(white, LOW);
        digitalWrite(green, LOW);
        if(digitalRead(blue) == LOW)
        {
            if(millis()- WMillis > 60)
            {   
              digitalWrite(blue, HIGH);
              WMillis = millis();
            }
         }
         else
         {   
            if(millis()- WMillis > 240)
            {     
            digitalWrite(blue, LOW);
            WMillis = millis();
            }
         }
         if(millis() - Millis > 3000)
         {
          overall++;
          Millis = millis();
         }
       }
       else if (overall == 1) //ice
       {
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        if(digitalRead(white) == HIGH)
      {
          if(millis()- WMillis > 350)
          {   
            digitalWrite(white, LOW);
            WMillis = millis();
          }
       }
       else
       {   
          if(millis()- WMillis > 150)
          {     
          digitalWrite(white, HIGH);
          WMillis = millis();
          }
       }
       if(millis() - Millis > 5000)
       {
        overall++;
        Millis = millis();
       }
       }
       else if(overall == 2) //dispenser
       {
        digitalWrite(blue, LOW);
        digitalWrite(white, LOW);
        if(digitalRead(green) == HIGH)
      {
          if(millis()- WMillis > 10)
          {   
            digitalWrite(green, LOW);
            WMillis = millis();
          }
       }
       else
       {   
          if(millis()- WMillis > 90)
          {     
          digitalWrite(green, HIGH);
          WMillis = millis();
          }
       }
       if(millis() - Millis > 2000)
       {
        overall = 0;
        Millis = millis();
       }
       }
    }
}
void turn_on()
{
  static unsigned long OnMillis = millis();

  if(millis() - OnMillis > 1000)
  {
    
    water = analogRead(A0);
    ice = analogRead(A1);
    Serial.print("Water: "); Serial.print(water); Serial.print("  Ice: "); Serial.println(ice);
    if(water < min_light_level && ice < min_light_level && !is_on)
    {
      is_on = true;
      Serial.println("WE ARE ON");
    }
    else if(water < min_light_level && ice < min_light_level && is_on)
    {
      is_on = false;
      Serial.println("WE ARE OFF");
      digitalWrite(red,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(white, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);   
    }
    OnMillis = millis();
  }
}

//Write your states here 
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);

} task;

int delay_gcd;
const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum SM1_States { SM1_INIT, on, off};
int SM1_Tick(int state1) {
  switch (state1) {
    case SM1_INIT:
      state1 = on;
      break;
    case on:
      state1 = on;
      break;
  }
  switch (state1) {
    case SM1_INIT:
      break;
    case on:
      //Serial.println(analogRead(A0));
      if(is_on)
      {
        cycle();
      }
      
      break;
  }
  return state1;
}

enum SM2_States { SM2_INIT, on2};
int SM2_Tick(int state2) {
  switch (state2) {
    case SM2_INIT:
      state2 = on2;
      break;
    case on2:
      state2 = on2;
      break;

  }
  switch (state2) {
    case SM2_INIT:
      state2 = on2;
      break;
    case on2:
       turn_on();
    break;
  }

  return state2;
}

void setup() {
  unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM2_Tick;

  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(white,OUTPUT);
  
  delay_gcd = 1000; // GCD
  Serial.begin(9600);
}

void loop() {
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
}
