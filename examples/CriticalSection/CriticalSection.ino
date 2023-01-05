/*
 * Basic example to demonstrate the usage of this library.
 */

#include <107-Arduino-CriticalSection.h>

volatile int button_evt_counter = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial) { }

  attachInterrupt(0, onButton_1_Pressed, RISING);
  attachInterrupt(1, onButton_2_Pressed, RISING);
}

void loop()
{
  int copy_button_evt_counter;
  {
    /* Prevent change of button_evt_counter during readout. */
    CriticalSection crit_sec;
    copy_button_evt_counter = button_evt_counter;
  }
  Serial.println(copy_button_evt_counter);
}

void onButton_1_Pressed()
{
  CriticalSection crit_sec;
  button_evt_counter++;
}

void onButton_2_Pressed()
{
  CriticalSection crit_sec;
  button_evt_counter++;
}
