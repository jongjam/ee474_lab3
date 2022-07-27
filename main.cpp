//James Jhong 1939553
//EE 474 Lab 3
//July 25 2022
#include "defines.h"
#include <Arduino.h>



//use a .h for pins 
void setup() {
  //Setting up LED bit
  
  DDRL |= led_bit;
  //Setting up Speaker output
  DDRH |= speaker_bit;
  //Setting up 7 Segment Bit

  //Setting up Timer 4 for use in demo 1
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4 = 0;
  

  TCCR4A |= (1 << COM4A0); //Toggling on compare match
  TCCR4B |= (1 << WGM42); //CTC MODE
  TCCR4B |= (1 << CS40); //Prescalar 1

}


/**
 * @brief This function calculates the OCR4A value, based on a value 1 prescalar and the desired frequency.
 * 
 * @param freq 
 */
void ocr_calc(int freq) {
  
  if (freq == 0) {
    OCR4A = 0;
  } else {
    OCR4A = (16000000 / 2 * freq) - 1 ;
  }
}



/** 
 * This function flashes an LED on for 250 ms every 1 second. 
 */
void task1() {
  static int time;
  time++;
  if (time == 249) {
    PORTL &= (1 << PORTL2);
  } if (time == 749) {
    PORTL |= (1 << PORTL2);
  }
  if (time >= 999) {
    time = -1;
  }
  return;
}

//Use a .h folder for the different schedulers?
void loop() {
  //Demo Number 1: Round Robin scheduler
  // while (1) {
  //   task1();
  //   task2();
  // }
  task1();
  
  //  PORTL &= ~(1 << PORTL2);
  //  delay(2000);
  //  PORTL |= (1 << PORTL2);
  //  delay(3050);
  //delay(1);
  /**Demo Two : Sychronized Round Robin with ISR (interrups, srri)
   * 
   */
  
  /** Demo Three : Tasks 1 and 2, DDS
   *  
   */
  /** Demo 4 : T1, t2, t3. SRRI
   *  
   */
   /** Demo 5: T4, DDS
    *  
    */
    /** Demo t5, dds
     * 
     */
}

void speaker() {

}

/** 
 *  This function plays the theme from "Close Encounters of the Third Kind"
 *  and then rests for 4 secfconds and restarts
 */
void task2() {
  PORTH |= (PH3);
  int note;
  static int counter;
  counter++;
  note = melody[counter / note_duration]; //Playing each note of the song
  if (counter == melody_length) { //Once song complete, 4 second wait
  //Once complete, 4 seconds silence and restart
  
    if (counter >= 4000) { //Resetting time, counter and port after 4 seconds
      counter = 0;
          //lamb_flag = 0; 
    }
  }
  OCR4A = note; //Setting the OCR4A of the timer to the desired note. 
   
  return;
}

/**
 * This function is a counter that increments by every 100 ms and displays
 * the current number across a 7-Segment LED display
 */
void task3() {
  return;
}

/**
 * This task combines tasks 2 and 3. It plays the theme from "Close Encounters of the Third Kind" and
 * when the theme is done, it displays the time across the 7-Segment LED, in tenths of a second, until
 * the next time it plays. It also displays the frequency of every note while the song is playing across the 7-segment LED.
 */
void task4() {
  
}

/**
 * This function is comprised of pieces from the other tasks. 
 * Task 1 runs at all times. 
 * Task 2 plays the theme twice before shutting off.
 * Task 3 starts a 3 second countdown and then restarts task 2 for one more playthrough.
 * A smile is then displayed on the LED segment for two seconds after task 2 is complete
 * Only task 1 will run after the final task is complete
 */ 
void task5() {
  
}

