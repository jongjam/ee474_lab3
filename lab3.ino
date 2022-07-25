//James Jhong 1939553

void setup() {
  // put your setup code here, to run once:

}
//Use a .h folder for the different schedulers?
void loop() {
  //Demo Number 1: Round Robin scheduler
  while (1) {
    task1();
    task2();
  }
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

/** 
 * This function flashes an LED on for 250 ms every 1 second. 
 */
void task1() {
  
}

/** 
 *  This function plays the theme from "Close Encounters of the Third Kind"
 *  and then rests for 4 secfconds and restarts
 */
void task2() {
  
}

/**
 * This function is a counter that increments by every 100 ms and displays
 * the current number across a 7-Segment LED display
 */
void task3() {
  
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
