// Cristian Molano - cmola002
// Section 21
// September 5, 2021

//We now need libraries for the LCD. Please include the required libraries mentioned in the report.

#include <LiquidCrystal.h>
#include <DHT.h>
#define DHTPIN A0     
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int red = 11, white = 10, yellow = 9, blue = 8;
int JS_X = A1, JS_Y = A2, JS_BTN = 12;
int sethumidity = 30, settemp = 75;
bool on_off = false, temp_select = true;
int hif, hic, h, t, f;
bool led_red = false, led_white = false, led_blue = false, led_yellow = false;

//Functions, feel free to rewrite to your own accord
void turn_on()
{
  static unsigned long OnMillis = millis();

  //if(millis() - OnMillis > 300) //sample every 300ms for joystick
  //{
    //Serial.println("hey");
    int j_btn = digitalRead(JS_BTN);
    Serial.println(j_btn);
    if(j_btn == 0)
    {
      if(on_off == false)
      {
        on_off = true;
      }
      else if(on_off == true)
      {
        on_off = false;
      }
      
    }
    //OnMillis = millis();
  //}
}

//LED Control
void control()
{
  if(hif > settemp)
  {
    //turn on cooler
    led_white = true;
    led_red = false;
    //cooler();
  }
  else if(hif < settemp)
  {
    //turn on heater
    led_red = true;
    led_white = false;
    //heater();
  }
  else if(hif == settemp)
  {
    led_white = false;
    led_red = false;
    digitalWrite(white,LOW);
    digitalWrite(red,LOW);
  }

  if(h > sethumidity)
  {
    //dehumidify
    led_yellow = true;
    led_blue = false;
    //dehumidify();
  }
  else if(h < sethumidity)
  {
    //humidify
    led_blue = true;
    led_yellow = false;
    //humidify();
  }
  else if(h == sethumidity)
  {
    led_yellow = false;
    led_blue = false;
    digitalWrite(yellow,LOW);
    digitalWrite(blue,LOW);
  }
}

void cooler()
{
  digitalWrite(red,LOW);
  static unsigned long WMillis = millis();
  if(digitalRead(white) == HIGH)
  {
    if(millis()- WMillis > 120) //off for 40% of 300
    {   
      digitalWrite(white, LOW);
      WMillis = millis();
    }
  }
  else
  {   
    if(millis()- WMillis > 180) //on for 60% of 300
    {     
      digitalWrite(white, HIGH);
      WMillis = millis();
    }
  }
}

void heater()//red 95% for 100ms
{
  digitalWrite(white,LOW);
  static unsigned long WMillis = millis();
  if(digitalRead(red) == HIGH)
  {
    if(millis()- WMillis > 5) //5% low
    {   
      digitalWrite(red, LOW);
      WMillis = millis();
    }
  }
  else
  {   
    if(millis()- WMillis > 95) //95% of 100
    {     
      digitalWrite(red, HIGH);
      WMillis = millis();
    }
  }  
}

void dehumidify()//yellow 25% and a period of 400 ms
{
  digitalWrite(blue,LOW);
  static unsigned long WMillis = millis();
  if(digitalRead(yellow) == HIGH)
  {
    if(millis()- WMillis > 300) //75% low
    {   
      digitalWrite(yellow, LOW);
      WMillis = millis();
    }
  }
  else
  {   
    if(millis()- WMillis > 100) //25% of 400
    {     
      digitalWrite(yellow, HIGH);
      WMillis = millis();
    }
  }  
}

void humidify()//blue 20% and a period of 200 ms
{
  digitalWrite(yellow,LOW);
  static unsigned long WMillis = millis();
  if(digitalRead(blue) == HIGH)
  {
    if(millis()- WMillis > 160) //80% low
    {   
      digitalWrite(blue, LOW);
      WMillis = millis();
    }
  }
  else
  {   
    if(millis()- WMillis > 40) //20% of 200
    {     
      digitalWrite(blue, HIGH);
      WMillis = millis();
    }
  }
}

///////////////temp///////////////////
void check_temp()
{
  //static unsigned long OnMillis = millis();

  //if(millis() - OnMillis > 500) //sample every 500ms for temp reading
  //{
     //Serial.print("temp");
     h = dht.readHumidity();
     t = dht.readTemperature();
     f = dht.readTemperature(true);
     hif = dht.computeHeatIndex(f, h);
     hic = dht.computeHeatIndex(t, h, false);
     //OnMillis = millis();
  //}
  /*
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  */
}

//////////joystick input/////////////////

void check_input()
{
   static unsigned long OnMillis = millis();

  //if(millis() - OnMillis > 300) //sample every 300ms for joystick
  //{
    int j_x = analogRead(JS_X);
    int j_y = analogRead(JS_Y);
    Serial.print("x: "); Serial.print(j_x); Serial.print(" y: "); Serial.println(j_y);
    if(j_x > 950)//right
    {
      if(temp_select == true)
      {
        settemp++;
      }
      else
      {
        sethumidity++;
      }
    }
    if(j_x < 150)//left
    {
      if(temp_select == true)
      {
        settemp--;
      }
      else
      {
        sethumidity--;
      }
    }
    if(j_y < 100)//up
    {
      temp_select = true;
    }
    else if(j_y > 950)//down
    {
      temp_select = false;
    }
    
    //OnMillis = millis();
  //}
}

///////////////////////lcd////////////////
void show_lcd()
{
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(hif);
    lcd.print(" STemp:");
    lcd.print(settemp);
    lcd.setCursor(0, 1);
    lcd.print("Hum:");
    lcd.print(h);
    lcd.print(" SHum:");
    lcd.print(sethumidity);
  
  
}
//////////////////////states///////////////////////////
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);

} task;

int delay_gcd;
const unsigned short tasksNum = 9;
task tasks[tasksNum];


//////////////check input//////////////////////

enum SM1_States { SM1_INIT, on, off};
int SM1_Tick(int state1) {
  switch (state1) { // State transitions
    case SM1_INIT:
      state1 = on;
      break;
    case on:
      state1 = on;
      break;
  }
  switch (state1) { // State Action
    case SM1_INIT:
      break;
    case on:
      //Serial.println("hey");
      if(on_off == true)
      {
        check_input();
      }
      
      break;
  }
  return state1;
}

/////////check on and off functions/////////////

enum SM2_States { SM2_INIT, on2};
int SM2_Tick(int state2) {
  switch (state2) { // State transitions
    case SM2_INIT:
      state2 = on2;
      break;
    case on2:
      state2 = on2;
      break;

  }
  switch (state2) { // State Action
    case SM2_INIT:
      state2 = on2;
      break;
    case on2:
       //Serial.println("attempting to turn on");
       turn_on();
       if(on_off == false)
       {
          lcd.clear();
          digitalWrite(red,LOW);
          digitalWrite(white,LOW);
          digitalWrite(yellow,LOW);
          digitalWrite(blue,LOW);
       }
    break;
  }

  return state2;
}

///////////////check temp/////////////////

enum SM3_States { SM3_INIT, on3, off3};
int SM3_Tick(int state3) {
  switch (state3) { // State transitions
    case SM3_INIT:
      state3 = on3;
      break;
    case on:
      state3 = on3;
      break;
  }
  switch (state3) { // State Action
    case SM3_INIT:
      break;
    case on:
      if(on_off == true)
      {
        check_temp();
      }
      
      break;
  }
  return state3;
}

///////////////showing lcd////////////////
enum SM4_States { SM4_INIT, on4, off4};
int SM4_Tick(int state4) {
  switch (state4) { // State transitions
    case SM4_INIT:
      state4 = on4;
      break;
    case on:
      state4 = on4;
      break;
  }
  switch (state4) { // State Action
    case SM4_INIT:
      break;
    case on:
      if(on_off == true)
      {
        show_lcd();
      }
      
      break;
  }
  return state4;
}

///////////////// controlling leds //////////////////////////
enum SM5_States { SM5_INIT, on5, off5};
int SM5_Tick(int state5) {
  switch (state5) { // State transitions
    case SM5_INIT:
      state5 = on5;
      break;
    case on:
      state5 = on5;
      break;
  }
  switch (state5) { // State Action
    case SM5_INIT:
      break;
    case on:
      if(on_off == true)
      {
        control();
      }
      
      break;
  }
  return state5;
}

///cooler

enum SM6_States { SM6_INIT, on6, off6};
int SM6_Tick(int state6) {
  switch (state6) { // State transitions
    case SM6_INIT:
      state6 = on6;
      break;
    case on:
      state6 = on6;
      break;
  }
  switch (state6) { // State Action
    case SM6_INIT:
      break;
    case on:
      if(on_off == true && led_white == true)
      {
        cooler();
      }
      
      break;
  }
  return state6;
}

///red

enum SM7_States { SM7_INIT, on7, off7};
int SM7_Tick(int state7) {
  switch (state7) { // State transitions
    case SM7_INIT:
      state7 = on7;
      break;
    case on:
      state7 = on7;
      break;
  }
  switch (state7) { // State Action
    case SM7_INIT:
      break;
    case on:
      if(on_off == true && led_red == true)
      {
        heater();
      }
      
      break;
  }
  return state7;
}

///yellow dehumidifier

enum SM8_States { SM8_INIT, on8, off8};
int SM8_Tick(int state8) {
  switch (state8) { // State transitions
    case SM8_INIT:
      state8 = on8;
      break;
    case on:
      state8 = on8;
      break;
  }
  switch (state8) { // State Action
    case SM8_INIT:
      break;
    case on:
      if(on_off == true && led_yellow == true)
      {
        dehumidify();
      }
      
      break;
  }
  return state8;
}

//humidifier

enum SM9_States { SM9_INIT, on9, off9};
int SM9_Tick(int state9) {
  switch (state9) { // State transitions
    case SM9_INIT:
      state9 = on9;
      break;
    case on:
      state9 = on9;
      break;
  }
  switch (state9) { // State Action
    case SM9_INIT:
      break;
    case on:
      if(on_off == true && led_blue == true)
      {
        humidify();
      }
      
      break;
  }
  return state9;
}
///////////////////////////setup/////////////////////////////

void setup() {
  unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 300; //checking js input every 300ms
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 300; //checking js input every 300ms (for on off)
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM2_Tick;
  i++;
  tasks[i].state = SM3_INIT;
  tasks[i].period = 500; //checking temp every 500ms
  tasks[i].elapsedTime = 0; 
  tasks[i].TickFct = &SM3_Tick;
  i++;
  tasks[i].state = SM4_INIT;
  tasks[i].period = 0; //lcd always on
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM4_Tick;
  i++;
  tasks[i].state = SM5_INIT;
  tasks[i].period = 0; //constantly checking temp
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM5_Tick;
  i++;
  tasks[i].state = SM6_INIT;
  tasks[i].period = 300; //white led
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM6_Tick;
  i++;
  tasks[i].state = SM7_INIT;
  tasks[i].period = 100; //red led
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM7_Tick;
  i++;
  tasks[i].state = SM8_INIT;
  tasks[i].period = 400; //yellow led
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM8_Tick;
  i++;
  tasks[i].state = SM9_INIT;
  tasks[i].period = 100; //red led
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM9_Tick;
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(JS_BTN, INPUT_PULLUP);
  Serial.begin(9600);
  dht.begin();
}

////////////////////////////////loop/////////////////////////

void loop() {
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  
}
