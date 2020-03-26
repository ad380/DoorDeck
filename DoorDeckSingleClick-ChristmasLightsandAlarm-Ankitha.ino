//Ankitha Durvasula
//Tools Mastery #1
int RED = 11; //Red LED on pin 12
int GREEN = 10;//Green LED on pin 10
int BUTTON = 12;//Push button on pin 9
int buttonState = 0;//Initialize a variable to store button output value (HIGH or LOW) (whether clicked or unclicked)
int memory = false;//variable to check for previous status of button before click
boolean setting = false;//button setting to run
void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT); // initialize red led pin as an output
  pinMode(GREEN, OUTPUT); // initialize green led pin as an output
  pinMode(BUTTON, INPUT_PULLUP); // initialize button pin as an input
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(BUTTON); //store value of button state (determine whether pushed or not)
  if (buttonState == LOW && memory == HIGH){ //Check if button was clicked once
    setting = !setting; //if it was clicked set value to true
    delay(50); //wait for 500 milliseconds to make sure event is captured
  }
  memory = buttonState;
  
  if (setting){ //check if button was clicked
      digitalWrite(RED, HIGH); //turn on red LED
      digitalWrite(GREEN, HIGH); //turn on green LED 
      delay(1000); //wait 1000 milliseconds                       
      digitalWrite(RED, LOW); //turn off red LED
      digitalWrite(GREEN, LOW); //turn off green LED  
      delay(1000); // wait 1000 milliseconds
  }
  else{
      digitalWrite(RED, HIGH); //turn on red LED  
      delay(250); //wait 250 milliseconds                       
      digitalWrite(GREEN, HIGH); //turn on green LED   
      delay(250); //wait 250 milliseconds
      digitalWrite(RED, LOW);  //turn off red LED 
      delay(250); //wait 250 milliseconds                      
      digitalWrite(GREEN, LOW); //turn off green LED  
      delay(250); //wait 250 milliseconds
  }
  //if (setting){ //first light setting of christmas lights
    //digitalWrite(RED, HIGH); //turn on red LED
    //digitalWrite(GREEN, HIGH); //turn on green LED 
    //delay(1000); //wait 1000 milliseconds                       
    //digitalWrite(RED, LOW); //turn off red LED
    //digitalWrite(GREEN, LOW); //turn off green LED  
    //delay(1000); // wait 1000 milliseconds
  //}
  //if (!setting){ //second light setting of alarm lights
    //digitalWrite(RED, HIGH); //turn on red LED  
    //delay(250); //wait 250 milliseconds                       
    //digitalWrite(GREEN, HIGH); //turn on green LED   
    //delay(250); //wait 250 milliseconds
    //digitalWrite(RED, LOW);  //turn off red LED 
    //delay(250); //wait 250 milliseconds                      
    //digitalWrite(GREEN, LOW); //turn off green LED  
    //delay(250); //wait 250 milliseconds
  //}
}
