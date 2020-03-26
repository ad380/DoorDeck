// Ankitha Durvasula, Partner: Yasa Baig 
// This arduino script interfaces with our dorm room sign circuit, allowing it toggle between turning on a red light or turning on a green light at
// the click of a button. 

int pbuttonPin = 12;// Connect the input from the pushbutton to 12
int greenLight = 11;// connect the yellow LED powersource to 11
int redLight = 10; // connect the red LED powersource to 10

int pushEvent; // digital input value from pin 13. Due to the Pull up resistor maintaing a constant 5 V in the pin , a value of LOW means 
               // the button is currently being pushed as the button's closing offers a path to ground where as HIGH means the button has offered no additional path for the voltage and
               // the reading is stuck at 5V. 
int statusMemory; // This integer stores the value of the pin 100 seconds after the pushEvent. 
int mode = 1; // This integer corresponds to the mode of the system. If the mode reads 1, then that means that the green Light is no and red light is off and if the mode reads 0, that means 
              // the green light is off and the red light is on. 

// This code runs before the arduino actually starts to operate. It sets up the digital inputs and outputs which will be used by the loop() code which actually controls controller behavior.
void setup() {
  pinMode(pbuttonPin, INPUT_PULLUP); // Initialize pin 12 as a pullup resistor input. By default, the pull up resistor will configure this pin to hold 5v, meaning it will be constantly reading HIGH unless
                                     // a separate connection allows the internal current to have a path to ground. For our circuit,this path to ground is created when the user pushes on the button. 
                                    //  If it goes to ground, then the reading will be LOW. This allows us to get boolean logic out of the circuit and avoid the issue of the floating "button" which 
                                    // naturally oscilates between 1 and 0 states due to ambient electromagnetic radiation. 
  pinMode(greenLight, OUTPUT);      // Configure pin 11 to be the output for the greenlight. When this reads HIGH, the green light is being supplied with voltage. 
  pinMode(redLight, OUTPUT);        // Configure pin 10 to be the output for the red Light. When this reads HIGH, the green light is being supplied with voltage. 

}

// This code will run continously every few milliseconds, checking for changes in input values as well as altering output pin values dynamically. 
void loop() {

  // We start by reading the pushEvent on every loop. If the user does not push the button, the pin will read HIGH, and if the user pushes the button, then the pin will read LOW 
  pushEvent = digitalRead(pbuttonPin);// read the push button value

  // Here we check if the user pushed the pin (pushEvent == Low) and also that if the user is not holding down the pin via the statusMemory. As the statusMemory will hold information on the
  // state of the digital input from the last loop iteration, if it reads HIGH, then that means that a few seconds ago the pin was not being pushed and therefore this change to the state is novel and should
  // be recorded. 
  if(pushEvent == LOW && statusMemory == HIGH){
    mode = 1 - mode; // Flip the value of the mode from 1 to 0 if it was 1 before and from 0 to 1 if it was 0 before. This toggles whether the red or green light is on. 
    delay(100); // Delay the loop for 100 ms. This gives time for the user to lift their finger from the button. 
  }    

  // Store the value of the digitalInput pushEvent 100 seconds after the pushing. If this reads 1, this indicates the user has succesfully let go of the button. 
  statusMemory = pushEvent;

  // If the circuit is in mode 1, the greenLight should be turne don and the red light will be turned off. 
  if(mode == 1){
    digitalWrite(greenLight, HIGH); // Turn on green light
    digitalWrite(redLight, LOW);  // Dim red light
  
  }else{
    // If the circuit is is not in mode 1, meaning it is in mode 0, then turn off the green light and turn on the re light instead. 
    digitalWrite(greenLight, LOW);  // Turn off green light
    digitalWrite(redLight, HIGH); // Turn on red light. 

  }     

  // Add an additional 100 second delay between each loop. This stops the arduino from checking the value of the digital input pin every couple of milliseconds, helping
  // protect the desired boolean logic from minor and transient changes in the signal read from 12 which may still persist. 
  delay(100);
}
