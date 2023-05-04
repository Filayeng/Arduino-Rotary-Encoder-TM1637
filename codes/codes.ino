// https://github.com/Filayeng

#include <TM1637Display.h>  // Include the library

// Define the connections pins
#define CLK 4
#define DIO 5

TM1637Display display = TM1637Display(CLK, DIO);  // Create a display object of type TM1637Display

long temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder

void setup() {
  
  display.setBrightness(5);   //Set the display Brightness

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(3, INPUT_PULLUP); // internal pullup input pin 3
   
   //Setting up interrupt
  //A rising pulse from Rotary Encoder activated forward(). AttachInterrupt 0 is DigitalPin 2 on most Arduino.
  attachInterrupt(0, forward, RISING);
   
  //B rising pulse from Rotary Encoder activated backward(). AttachInterrupt 1 is DigitalPin 3 on most Arduino.
  attachInterrupt(1, backward, RISING);

}
   
void loop() {
    
  // Send the value of counter
  if(counter != temp){
   display.showNumberDec(counter);  // Sending the counter data to Display to show
   temp = counter;
  }
  
}
   
void forward() {

  // forward is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  
  if(digitalRead(3)==LOW){
    counter++;
  }
  else{
    counter--;
  }
  
}
   
  
void backward() {

  // backward is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  
  if(digitalRead(2)==LOW) {
    counter--;
  }
  else{
    counter++;
  }
  
}
