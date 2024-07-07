// Cristian Molano - cmola002
// Section 21
// September 11, 2021

#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#define BLACK 0x0000
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define RED 0xF800
#define MAGENTA 0xF81F
#define WHITE 0xFFFF


MCUFRIEND_kbv tft;
int player_x;
int enemy_x;
int player_y = 300;
int enemy_y;

#define echoPin 53 
#define trigPin 52

#define life1 22
#define life2 24
#define life3 26

#define proton1 40
#define proton2 42
#define proton3 44
#define proton4 46

#define touch_button 28

int count = 0;
int lives = 3;
long duration; 
int distance,prev = 100,value;
int t = 0;
int proton = -20;
int proton_count = 0;
bool hit,start = false, gg = false, set = false, proton_hit;
int proton_x, proton_y = -20;
int rand_ten;
int time_start;
int proton_1_time, proton_2_time;
bool easier = false;

//////////////////////////////start game + reset//////////////////////////////
//touch button pin: 28
void start_game()
{
  int state = digitalRead(touch_button);
  if(start == false)
  {
    tft.setCursor(20,150);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.print("Press Button");
    tft.setCursor(40,200);
    tft.setTextSize(3);
    tft.setTextColor(WHITE);
    tft.print("To Start!");
  }
  
  
  if(state == HIGH)
  {
    start = true;
    tft.fillRect(0,50,400,200,BLACK);
    time_start = millis();
  }
}

void reset_game()
{
  start = false;
  easier = false;
  t = 0;
  lives = 3;
  proton_count = 0;
  digitalWrite(life1,HIGH);
  digitalWrite(life2,HIGH);
  digitalWrite(life3,HIGH);
  digitalWrite(proton1,LOW);
  digitalWrite(proton2,LOW);
  digitalWrite(proton3,LOW);
  digitalWrite(proton4,LOW);
}


//////////////////////////////lives counter////////////////////////////
//lives leds:
//first led 22
//second led 24
//third led 26

void subtract_life()
{
  --lives;
  if(lives == 2)
  {
    digitalWrite(life1,LOW);
  }
  else if(lives == 1)
  {
    digitalWrite(life2,LOW);
  }
  else if(lives == 0)
  {
    digitalWrite(life3,LOW);
    tft.setCursor(30,75);
    tft.setTextSize(4);
    tft.setTextColor(RED);
    tft.print("YOU LOSE");
    reset_game();
  }
}

///////////////////////////////protons leds/////////////////////////////
//led 1:40
//led 2: 42
//led 3: 44
//blue led: 46

void proton_led()
{
  proton_count++;
  if(proton_count == 1)
  {
    digitalWrite(proton1,HIGH);
    proton_1_time = millis() - time_start;
  }
  if(proton_count == 2)
  {
    digitalWrite(proton2,HIGH);
    proton_2_time = millis() - time_start;
  }
  if(proton_count == 3)
  {
    digitalWrite(proton3,HIGH);
  }
  if(proton_count == 4)
  {
    digitalWrite(proton4,HIGH);
    tft.setCursor(40,75);
    tft.setTextSize(4);
    tft.setTextColor(BLUE);
    tft.print("YOU WIN");
    reset_game();
  }
  
}

//////////////////////////////player movement//////////////////////////

void detect_collision()
{
  /*
  Serial.print("Player: ");
  Serial.print(player_x);
  Serial.print("  Enemy: ");
  Serial.println(enemy_x);
  */
  //between player_x and player_x + 20
  if(player_x <= enemy_x && player_x + 50 > enemy_x  && player_y <= enemy_y + 30 && player_y > enemy_y)
  {
    if(!hit)
    {
      //tft.fillRect(100,100,40,40,RED);
      Serial.println("aigaosjgpoasjgpoiejapogijdspigjrsipehgpihusgiphaorgihaipdhgp");
      subtract_life();
      hit = true;
    }
    
  }
  if(player_x <= proton_x +20 && player_x + 50 > proton_x  && player_y <= proton_y + 20)
  {
    if(!proton_hit)
    {
      Serial.println("aigaosjgpoasjgpoiejapogijdspigjrsipehgpihusgiphaorgihaipdhgp");
      proton_led();
      proton_hit = true;
    }
  }
}

void movePlayer()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = Pulse(echoPin, HIGH,37);
  distance = duration * 0.034 / 2;
  value = distance;
  value = round(value) * 3;
  if(value <= prev+50)
  {
    tft.fillRect(0,300,value,20,BLACK);
    tft.fillRect(value+50,300,240-value,20,BLACK);
    tft.fillRect(value,300,50,20,RED);
    player_x = value;
    prev = value;
  }
}


//////////////////////////////enemy movement////////////////////////////

class Enemy
{
  public:
  int num1 = random_number();
  int proton_xx = proton_random_number();
  void draw()
  {
      enemy_x = num1;
      tft.fillRect(num1,-20,20,20,DARKGREY);
      tft.fillRect(num1+20,-20,5,30,DARKGREY);
      tft.fillRect(num1-5,-20,5,30,DARKGREY);
      

  };
  void move()
  {
      for(int i = -20; i < 400; i=i+10)
      {
        movePlayer();
      tft.fillRect(num1,i-20,20,20,BLACK);
      tft.fillRect(num1+20,i-30,5,30,BLACK);
      tft.fillRect(num1-5,i-30,5,30,BLACK);
      tft.fillRect(num1,i,20,20,DARKGREY);
      tft.fillRect(num1+20,i,5,30,DARKGREY);
      tft.fillRect(num1-5,i,5,30,DARKGREY);

      //proton
      if(set)
      {
        if(rand_ten <= count)
        {
          tft.fillRect(proton_xx,proton_y-20,20,20,BLACK);
          tft.fillRect(proton_xx,proton_y,20,20,MAGENTA);
          proton_y = proton_y + 10;
          proton_x = proton_xx;
          if(proton_y > 320)
          {
            proton_y = -20;
            set = false;
            count = 0;
            //make easier
            if(easier)
            {
              rand_ten = one_to_five();
            }
            else
            {
              rand_ten = one_to_ten();
            }
            
          }
        }
      }
      
      detect_collision();
      enemy_y = i-20;
      }
      
      
  };
  void move_faster()
  {
      for(int i = -20; i < 400; i=i+15)
      {
        movePlayer();
        tft.fillRect(num1,i-20,20,20,BLACK);
        tft.fillRect(num1+20,i-30,5,30,BLACK);
        tft.fillRect(num1-5,i-30,5,30,BLACK);
        tft.fillRect(num1,i,20,20,DARKGREY);
        tft.fillRect(num1+20,i,5,30,DARKGREY);
        tft.fillRect(num1-5,i,5,30,DARKGREY);
        detect_collision();
        enemy_y = i-20;
      }
  };
};

void enemySpawn()
{
  Enemy tie_fighter;
  tie_fighter.draw();
}


Enemy tie_fighters[100];
////////////////////////////////////pulse/////////////////////////////
unsigned long Pulse(int pin, int value, int ping) 
{  
    unsigned long current_time = micros();
    while(digitalRead(pin) == value) 
    {
      if (micros() - current_time > (ping*1000)) 
      {
        return 0;
      }
    }
    current_time = micros(); 
    while (digitalRead(pin) != value) 
    {
      if (micros() - current_time > (ping*1000)) 
      { 
        return 0;
      }
    }
    current_time = micros();
    while (digitalRead(pin) == value) 
    { 
      if (micros() - current_time > (ping*1000))
      {
        return 0;
      }
    }
    return micros() - current_time;
}


///////////////////////random number generator//////////////////////////
static unsigned int random_number()
{
  static unsigned int random_num = 0xACE1U;
  unsigned int start_range = 0;
  unsigned int end_range = 240;
  random_num += 0x3AD;
  random_num %= end_range;

  while(random_num < start_range)
  {
      random_num = random_num + end_range - start_range;
  }

  return random_num;
}

static unsigned int proton_random_number()
{
  static unsigned int random_num = 0xAAAAA;
  unsigned int start_range = 0;
  unsigned int end_range = 240;
  random_num += 0x3AD;
  random_num %= end_range;

  while(random_num < start_range)
  {
      random_num = random_num + end_range - start_range;
  }

  return random_num;
}

static unsigned int one_to_ten()
{
  static unsigned int random_num = 0xAAAAA;
  unsigned int start_range = 1;
  unsigned int end_range = 10;
  random_num += 0x3AD;
  random_num %= end_range;

  while(random_num < start_range)
  {
      random_num = random_num + end_range - start_range;
  }

  return random_num;
}

static unsigned int one_to_five()
{
  static unsigned int random_num = 0xBBBBB;
  unsigned int start_range = 1;
  unsigned int end_range = 5;
  random_num += 0x3AD;
  random_num %= end_range;

  while(random_num < start_range)
  {
      random_num = random_num + end_range - start_range;
  }

  return random_num;
}
//////////////////////linear regression/////////////////////

void linear()
{
  //x = number of protons
  //y = time

  int slope = (proton_2_time - proton_1_time); //denominator would be 1 anyways =)
  int y_intercept = proton_2_time/2; //x = 2 protons, y = time to get second proton

  //estimate how long it'll take to get proton 4
  int proton_4_val = (slope * 4) + y_intercept;

  //over 10 games avergae time was about a minute, so if over that make easier
  if(proton_4_val >= 60000)
  {
    easier = true;
  }
  
  
}


//////////////////////states///////////////////////////
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);

} task;

int delay_gcd;
const unsigned short tasksNum = 6;
task tasks[tasksNum];

//////////////move character state//////////////////////
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
    if(start)
    {
      movePlayer();
    }
      
      break;
  }
  return state1;
}

/////////spawn enemy/////////////
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
    if(start)
    {
      tie_fighters[t].draw();
       tie_fighters[t].move();
       ++t;
       if(t == 100)
       {
        t = 0;
       }
       hit = false;
    }
       
    break;
  }

  return state2;
}

///////////////collision detection/////////////////
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
    if(start)
    {
      detect_collision();
    }
      
      
      break;
  }
  return state3;
}

////////////////////////////start game//////////////////////
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
       start_game();
      break;
  }
  return state4;
}

////////////////////////////proton////////////////////////
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
      if(start)
      {
        if(!set)
        {
          set = true;
          proton_hit = false;
          rand_ten = one_to_ten();
          //rand_ten = 1;
        }
        ++count;
        Serial.println(count);
      }
      break;
  }
  return state5;
}

/////////////////////////////linear regression//////////////////////
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
    
    if(start)
    {
      if(proton_count == 2 && easier == false)
      {
        linear();
      }
    }

      break;
  }
  
  return state6;
}

///////////////////setup///////////////////////////////
void setup() {

   unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 10; 
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 1000; 
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM2_Tick;
  i++;
  tasks[i].state = SM3_INIT;
  tasks[i].period = 10; 
  tasks[i].elapsedTime = 0; 
  tasks[i].TickFct = &SM3_Tick;
  i++;
  tasks[i].state = SM4_INIT;
  tasks[i].period = 10;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM4_Tick;
  i++;
  tasks[i].state = SM5_INIT;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM5_Tick;
  ++i;
  tasks[i].state = SM6_INIT;
  tasks[i].period = 300; 
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM6_Tick;
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  pinMode(life1, OUTPUT);
  pinMode(life2, OUTPUT);
  pinMode(life3, OUTPUT);

  digitalWrite(life1, HIGH);
  digitalWrite(life2,HIGH);
  digitalWrite(life3,HIGH);

  pinMode(proton1, OUTPUT);
  pinMode(proton2,OUTPUT);
  pinMode(proton3,OUTPUT);
  pinMode(proton4, OUTPUT);

  pinMode(touch_button, INPUT);
  
  tft.reset();
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(0);

  tft.fillScreen(BLACK);
  Serial.begin(9600);
}

//////////////////////////loop////////////////////////////

void loop() {
   unsigned char i;
  for (i = 0; i < tasksNum; ++i) 
  {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
}