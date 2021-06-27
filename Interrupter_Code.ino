/*
  Course: VANT151
  Description: This code demonstrates the interrupt method. 
               This will make the program update information every 0.2 seconds.
  Programmer: Visal Saosuo
  Date: 5/26/2021
 */
#include <MsTimer2.h>
// https://playground.arduino.cc/Main/MsTimer2

int ms200 = 0, seconds = 0, minutes = 0;
// to store the time

void timebase() {
  // this function is called the Interrupt Service Routine (ISR)
  // It executes every 0.2 seconds, triggered by Timer2 interrupt
  ms200++;
  if (ms200 > 4){
    seconds++;
    ms200 = 0;
    if (seconds > 59){
      minutes++;
      seconds = 0;
    }
  } // increments the time in minutes, seconds and 0.2 seconds

  // put code to read buttons and sensors here,
  // be sure to debounce, cater for press and hold,
  // press and repeat, etc.
  // put code to refresh the LCD or indicator lights here, e.g.:
  digitalWrite(13, seconds%2);
  // Switch on LED when odd numbered seconds
  
}

void setup() {
  // put the various setup code here
  pinMode(13, OUTPUT);

  // Timer2 interrupt every 0.2 seconds
  MsTimer2::set(200, timebase);
  // run the interrupt service routine (ISR) timebase()
  // every 200 milliseconds
  MsTimer2::start(); // start the ISR
}

void loop() {

  // Put the main code here.
  // To wait for input use while() statement.
  // When an input is received, do the appropriate operation
  // such as start/stop motor/fan, heater, 
  // change things to display, etc.

}
