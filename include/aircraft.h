/*
 * aircraft.h
 * Provided Code. Do not change it.
 */
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

/* Buttons */
#define SEATBELT_BUTTON     2
#define GEAR_BUTTON         3
#define SMOKE_BUTTON        4

/* LEDs */
#define WING_LIGHT_LED      5
#define SEATBELT_LED        6
#define GEAR_DOWN_LED       7
#define GEAR_CHANGING_LED   8
#define SMOKE_LED           9

/* Times (in milliseconds) */
#define WING_LIGHT_BLINK_RATE   500
#define AIRSPEED_PERIOD         250
#define BUTTON_POLL_PERIOD      50
#define GEAR_CHANGE_TIME        3000
#define SMOKE_POLL_PERIOD       20
#define SMOKE_FLASH_RATE        100
#define SMOKE_ALARM_TIME        5000
#define DISPLAY_PERIOD          500

/* Priorities */
#define SMOKE_PRIORITY      3
#define DISPLAY_PRIORITY    2
#define TASK_PRIORITY       1

/* Stack sizes (in bytes) */
#define TASK_STACK_SIZE     80
#define DISPLAY_STACK_SIZE  144 // DisplayTask needs more for Serial.print()

/* Landing gear states */
#define GEAR_UP         0
#define GEAR_CHANGING   1
#define GEAR_DOWN       2

/* Shared states
 * Each variable can be written by 1 task only
 * Any tasks may read it. 
 */
extern volatile uint8_t airspeed;
extern volatile bool    seatBeltOn;
extern volatile uint8_t gearState;
extern volatile bool    smokeDetected;

/* Tasks */
void AirspeedTask(void *pvParameters);
void WingLightTask(void *pvParameters);
void SeatBeltTask(void *pvParameters);
void LandingGearTask(void *pvParameters);
void SmokeDetectionTask(void *pvParameters);
void DisplayTask(void *pvParameters);

#endif
