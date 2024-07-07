// Cristian Molano - cmola002
// Section 21
// August 18, 2021

int jj = 0, 
int jjj = 0;

int i = 0;
int c = 0, b = 0;

int temp_right = 0, temp_left = 0, temp_up = 0, temp_down = 0, t = 0;
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
int password[4] = {1, 1, 3, 3};
int pass_input[4];

int counter = 0, pass_index = 0;

int verify = 0;
bool is_unlocked = false;
bool button_pressed = false;
bool unlock = false;

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

void input_led(int val)
{
    static unsigned long led_mills = millis();
    int i = 0;
    while(i != 2)
    {
        if (millis() - led_mills > 250) 
        {
          digitalWrite(val, !digitalRead(val));
          //Serial.println("led on!");
          ++i;
          led_mills = millis();
        }
    }
}

void wrong_password()
{
    static unsigned long led_mills = millis();
    int i = 0;
    while(i != 6)
    {
        if (millis() - led_mills > 250) 
        {
          digitalWrite(UP, !digitalRead(UP));
          digitalWrite(DOWN, !digitalRead(DOWN));
          digitalWrite(LEFT, !digitalRead(LEFT));
          digitalWrite(RIGHT, !digitalRead(RIGHT));
          //Serial.println("led on!");
          ++i;
          led_mills = millis();
        }
    }
}
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);

} task;

int delay_gcd;
const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum SM1_States { SM1_INIT, SM1_S0};
int SM1_Tick(int state1) {
  switch (state1) {
    case SM1_INIT:
      state1 = SM1_S0;
      break;
    case SM1_S0:
    /*
       if (c == 4) 
        {

        c = 0;

        if(b == 0)
        {
          i++;
        }
        else if(b == 1)
        {
          --i;
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
      */

        
        
      if(is_unlocked)
      {
        jjj = 0;
        if(jj != 2000)
        {
               if (c == 4) 
              {
                c = 0;
                i++;
               } 
                if (i == 8) 
                {
                  i = 0;
                }
                ++jj;
        }    
        unlock = true;
      }
      else if(!is_unlocked && unlock)
      {
        jj = 0;
        //unlock = false;
        if(jjj != 2000)
        {
               if (c == 4) 
              {
                c = 0;
                i--;
               } 
                if (i == 0) 
                {
                  i = 8;
                }
                ++jjj;
        }
        else if(jjj == 2000)
        {
          unlock = false;
        }
      }
      
      state1 = SM1_S0;
      break;

  }
  switch (state1) { // State Action
    case SM1_INIT:
      break;
    case SM1_S0:
      //if(is_unlocked)
      //{
          
         for (c; c < 4; c++) {
        //Serial.print("i: ");Serial.print(i);
        //Serial.print(" c: ");Serial.println(c);
        if (steps[i][c] == 1) {
          digitalWrite(sig[c], HIGH);

        }
        else {
          digitalWrite(sig[c], LOW);

        }

      }
      //}

      break;

  }

  return state1;
}

enum SM2_States { SM2_INIT, SM2_S0};
int SM2_Tick(int state2) {
  switch (state2) { // State transitions
    case SM2_INIT:
      //State Transition
      state2 = SM2_S0;
      break;
    case SM2_S0:
      state2 = SM2_S0;
      break;

  }
  switch (state2) { // State Action
    case SM2_INIT:
      break;
    case SM2_S0:
      if(is_unlocked && !button_pressed)
      {
              digitalWrite(UP, HIGH);
      digitalWrite(DOWN, HIGH);
      digitalWrite(LEFT, HIGH);
      digitalWrite(RIGHT, HIGH);
      }
      else if(!is_unlocked)
      {
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
      digitalWrite(LEFT, LOW);
      digitalWrite(RIGHT, LOW);
      }
      
      int j_x = analogRead(JS_X);
      int j_y = analogRead(JS_Y);
      int j_btn = digitalRead(JS_BTN);
      
      if(j_btn == 0)
      {
        if(is_unlocked)
        {
          button_pressed = true;
        }
      }
       
      if(button_pressed == true)
      {
        if(counter != 4)
      {
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
      digitalWrite(LEFT, LOW);
      digitalWrite(RIGHT, LOW);
      //for detecting input ONCE PER MOVE
      if(j_x > 800)
      {
         if(j_x > 1000)
         {
          if(temp_right == 0)
          {
            //left = 1, right = 2, up = 3, down = 4
            temp_right = 1;
            input_led(RIGHT);
            pass_input[pass_index] = 2;
            pass_index++;
            Serial.println("Right");
            ++counter;
          }
         }    
      }
      else if(j_x < 400)
      {
        if(j_x < 200)
        {
          if(temp_left == 0)
          {
            temp_left = 1;
            input_led(LEFT);
            Serial.println("Left");
            pass_input[pass_index] = 1;
            pass_index++;
            ++counter;
          }
        }
      }
      else if(j_x > 500 && j_x < 600)
      {
        temp_right = 0;
        temp_left = 0;
      }

      
      if(j_y < 300)
      {
        if(j_y < 150)
        {
          if(temp_up == 0)
          {
            temp_up = 1;
            input_led(UP);
            pass_input[pass_index] = 3;
            pass_index++;
            Serial.println("Up");
            ++counter;
          }
        }
      }
      else if(j_y > 800)
      {
        if(j_y > 950)
        {
          if(temp_down == 0)
          {
            temp_down = 1;
            input_led(DOWN);
            pass_input[pass_index] = 4;
            pass_index++;
            Serial.println("Down");
            ++counter;
          }
        }
      }
      else if(j_y > 500 && j_y < 600)
      {
        temp_up = 0;
        temp_down = 0;
      }
      //Serial.print("X: "); Serial.println(j_x);
      //Serial.print(" Y: " ); Serial.println(j_y);
      //Serial.print(" BTN: "); Serial.println(j_btn);

      }
      else if(counter == 4)
      {
      for(int j = 0; j < 4; ++j)
      {
        password[j] = pass_input[j];
      }

        counter = 0;
        pass_index = 0;
        Serial.println("password changed!");
        button_pressed = false;
      }
      }
      else
      {
        
      if(counter != 4)
      {
        
      //for detecting input ONCE PER MOVE
      if(j_x > 800)
      {
         if(j_x > 1000)
         {
          if(temp_right == 0)
          {
            //left = 1, right = 2, up = 3, down = 4
            temp_right = 1;
            if(!is_unlocked){input_led(RIGHT);}
            pass_input[pass_index] = 2;
            pass_index++;
            Serial.println("Right");
            ++counter;
          }
         }    
      }
      else if(j_x < 400)
      {
        if(j_x < 200)
        {
          if(temp_left == 0)
          {
            temp_left = 1;
            if(!is_unlocked){input_led(LEFT);}
            Serial.println("Left");
            pass_input[pass_index] = 1;
            pass_index++;
            ++counter;
          }
        }
      }
      else if(j_x > 500 && j_x < 600)
      {
        temp_right = 0;
        temp_left = 0;
      }

      
      if(j_y < 300)
      {
        if(j_y < 150)
        {
          if(temp_up == 0)
          {
            temp_up = 1;
            if(!is_unlocked){input_led(UP);}
            pass_input[pass_index] = 3;
            pass_index++;
            Serial.println("Up");
            ++counter;
          }
        }
      }
      else if(j_y > 800)
      {
        if(j_y > 950)
        {
          if(temp_down == 0)
          {
            temp_down = 1;
            if(!is_unlocked){input_led(DOWN);}
            pass_input[pass_index] = 4;
            pass_index++;
            Serial.println("Down");
            ++counter;
          }
        }
      }
      else if(j_y > 500 && j_y < 600)
      {
        temp_up = 0;
        temp_down = 0;
      }
      //Serial.print("X: "); Serial.println(j_x);
      //Serial.print(" Y: " ); Serial.println(j_y);
      //Serial.print(" BTN: "); Serial.println(j_btn);

      }
      else if(counter == 4)
      {
      for(int j = 0; j < 4; ++j)
      {
        if(password[j] == pass_input[j])
        {
          verify++;
        }
      }
      
      if(verify == 4)
      {
        if(!is_unlocked)
        {
          Serial.println("unlocked!");
          b = 0;
          is_unlocked = true;
        }
        else if(is_unlocked)
        {
          Serial.println("locked!");
          b = 1;
          is_unlocked = false;
        }
        counter = 0;
        pass_index = 0;
        verify = 0;
      }
      else if(verify != 4)
      {
        Serial.println("Wrong!");
        wrong_password();
        counter = 0;
        pass_index = 0;
        verify = 0;
      } 
      }
      }
      break;

  }

  return state2;
}

void setup() {
  // put your setup code here, to run once:
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


  unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 1;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 50;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM2_Tick;

  delay_gcd = 1; // GCD
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
