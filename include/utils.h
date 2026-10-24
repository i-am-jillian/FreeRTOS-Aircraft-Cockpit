/*
 * utils.h
 * Provided Code. Do not change it.
 */
#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

/* Minimum and Maximum Speeds (in knots) */
#define AIRSPEED_MIN    150
#define AIRSPEED_MAX    250

/* Returns the airspeed between AIRSPEED_MIN and AIRSPEED_MAX */
uint8_t getAirspeedLevel(void);

/* Prints airspeed, seat belt, gear, smoke to Serial. */
void displayAircraftStatus(void);

#endif
