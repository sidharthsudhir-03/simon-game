/*
Name : Sidharth Sudhir
Student Number : 11255635
CWL : sidsud03
email : sidharth.sudhir2003@gmail.com
*/

//defining function prototypes

void start_game();//all the LED lights glow for 2 seconds
void sequence(int stage);//generates sequence and displays lights subsequently
void user_input(int stage);//registers user input and checks if it is on a par with system generated sequence
void fail();//red light blinks for 5 seconds indicating that the user lost
void pass();//green light blinks for 5 seconds indicating that the user won

//defining variable

int level = 0;//different stages of difficulty during the game

//messages to be printed in the serial monitor

char const test[] = "Game Starting\n";
char const lose[] = "You have lost this round\n";
char const win[] = "You have won this round\n";

//defining lists

int LED_sequence[5];//stores integer values for the system generated sequence
int user_sequence[5];//stores integer values for the user's sequence

//defining variables for LED lights

int const RED = 12;
int const YELLOW = 11;
int const BLUE = 10;
int const GREEN = 9;

//defining variables for the LED lights indicating whether the user has won or lost 

int const PASS = 8;
int const FAIL = 13;

//defining variables for the buttons that respond to the LED lights

int const REDB = 7;
int const YELLOWB = 6;
int const BLUEB = 5;
int const GREENB = 4;


//initialization

void setup()
{
  //to initialize the LED lights
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  //to initialize the LED lights indicating whether the user won or lost
  pinMode(PASS, OUTPUT);
  pinMode(FAIL, OUTPUT); 
  
  //to initialize the press-down buttons for respective LED lights
  pinMode(REDB, INPUT);
  pinMode(YELLOWB, INPUT);
  pinMode(BLUEB, INPUT);
  pinMode(GREENB, INPUT);
  
  Serial.begin(9600); //to initialize the serial monitor

  randomSeed(analogRead(1)); //to generate a truly random sequence
  
}


//main program loop

void loop()  
{

  start_game();
  
  level = 0; //to reset the value of the variable after passing through the do-while loop
  
  int stage = 1; //represents the different stages during the game
  
  
  //loops the different stages until the game reaches the end of stage 5 or when the user gives a wrong input
  
  do{
    
    sequence(stage);
    
    user_input(stage);
    
    delay(500);
    
    stage++;
    
  }while(stage <= 5 && level + 1 == stage);
  
  
  //the user wins when he/she reaches level 5
  
  if(level == 5){
      
    pass();
      
  }
  
}


//user defined functions


void start_game()
{
 
  Serial.print(test);
  
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, HIGH); 
  delay(2000);  
  
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW); 
  delay(2000);
  
}


void sequence(int stage)
{
  
  LED_sequence[stage - 1] = random(9, 13);//generates a random element during the given stage of the game and is stored accordingly in the list
  
  
  //displays the sequence during that stage
  
  for(int x = 0; x < stage; x++){
    
    digitalWrite(LED_sequence[x], HIGH);
    delay(500);
  
    digitalWrite(LED_sequence[x], LOW);
    delay(500);
    
  }    
  
}


void user_input(int stage)
{
    
  int check = 0;//turns 1 if user has pressed down on a button
  int count = 0;//counts how many times the user has clicked the right button
  
  /*
  the variable i passes through this loop for the user's input
  the number of times it passes through depends on the stage of the game
  */
  
  for(int i = 0; i < stage; i++){
    
    check = 0;//this resets the value of the variable after passing through the while loop
    
    //the while loop checks whether the user has pressed down on a button
  
    while(check == 0){
      

      if(digitalRead(REDB) == HIGH){

        user_sequence[i] = 12;//the system registers the user's input into a list
        
        //the inner while loop allows the LED light to glow as long as the user is pressing down on the button

        while(digitalRead(REDB) == HIGH){

		digitalWrite(RED, HIGH);

	    }

	    digitalWrite(RED, LOW);//the light stops glowing after the user releases the button
	    delay(500);
        
        //this conditional statement checks if the respective element of the two lists are on a par
        
        if(user_sequence[i] == LED_sequence[i]){
          
          count++;//adds up to the number of correct buttons the user has pressed
          
        }
        
        check = 1;//the variable changes value to 1 only when the user has clicked the button

      }


      if(digitalRead(YELLOWB) == HIGH){

        user_sequence[i] = 11;//the system registers the user's input into a list
        
        //the inner while loop allows the LED light to glow as long as the user is pressing down on the button

        while(digitalRead(YELLOWB) == HIGH){

		digitalWrite(YELLOW, HIGH);

	    }

	    digitalWrite(YELLOW, LOW);//the light stops glowing after the user releases the button
	    delay(500);
        
        //this conditional statement checks if the respective element of the two lists are on a par
        
        if(user_sequence[i] == LED_sequence[i]){
          
          count++;//adds up to the number of correct buttons the user has pressed
          
        }
        
        check = 1;//the variable changes value to 1 only when the user has clicked the button

      }


      if(digitalRead(BLUEB) == HIGH){

        user_sequence[i] = 10;//the system registers the user's input into a list
        
        //the inner while loop allows the LED light to glow as long as the user is pressing down on the button

        while(digitalRead(BLUEB) == HIGH){

		digitalWrite(BLUE, HIGH);

	    }

	    digitalWrite(BLUE, LOW);//the light stops glowing after the user releases the button
	    delay(500);
        
        //this conditional statement checks if the respective element of the two lists are on a par
        
        if(user_sequence[i] == LED_sequence[i]){
          
          count++;//adds up to the number of correct buttons the user has pressed
          
        }
              
        check = 1;//the variable changes value to 1 only when the user has clicked the button

      }


      if(digitalRead(GREENB) == HIGH){

        user_sequence[i] = 9;//the system registers the user's input into a list
        
        //the inner while loop allows the LED light to glow as long as the user is pressing down on the button

        while(digitalRead(GREENB) == HIGH){

		digitalWrite(GREEN, HIGH);

	    }

	    digitalWrite(GREEN, LOW);//the light stops glowing after the user releases the button
	    delay(500);
        
        //this conditional statement checks if the respective element of the two lists are on a par
        
        if(user_sequence[i] == LED_sequence[i]){
          
          count++;//adds up to the number of correct buttons the user has pressed
          
        }
        
        check = 1;//the variable changes value to 1 only when the user has clicked the button

      }
      
      
    }
    
    
  }
      
  if(count == stage){
        
    level++;//increments the level if user has clicked the buttons in the right sequence
        
  }
      
  else{
        
    fail();//blinks red light for 5 seconds indicating that the user lost
    return;
        
  }

}
    
  
void fail() 
{
  
  Serial.print(lose);
  
  //loop to blink the red light for 5 seconds
  
  for(int i = 1; i<= 5; i++){
  
    digitalWrite(FAIL, HIGH);
    delay(500);
    
    digitalWrite(FAIL, LOW);
    delay(500);
    
  }
    
}
    

void pass()
{
  
  Serial.print(win);
  
  //loop to blink the green light for 5 seconds
  
  for(int j = 1; j <= 5; j++){
  
    digitalWrite(PASS, HIGH);
    delay(500);
    
    digitalWrite(PASS, LOW);
    delay(500);
    
  }
    
}
  
