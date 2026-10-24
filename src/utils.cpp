/*
 * utils.cpp
 * Provided File. Do not change it.
 */
#include "aircraft.h"
#include "utils.h"

/* Shared states */
volatile uint8_t airspeed      = 0;
volatile bool    seatBeltOn    = false;
volatile uint8_t gearState     = GEAR_DOWN;
volatile bool    smokeDetected = false;

uint8_t getAirspeedLevel(void) {
    return (uint8_t)random(AIRSPEED_MIN, AIRSPEED_MAX + 1);
}

void displayAircraftStatus(void) {
    static const char *const gearNames[] = { "UP", "CHANGING", "DOWN" };

    Serial.print(F("Airspeed: "));
    Serial.print(airspeed);
    Serial.print(F(" kt | Seat Belt: "));
    Serial.print(seatBeltOn ? F("ON") : F("OFF"));
    Serial.print(F(" | Gear: "));
    Serial.print(gearNames[gearState]);
    Serial.print(F(" | Smoke: "));
    Serial.println(smokeDetected ? F("ALARM") : F("clear"));
}

/* Prints the status every DISPLAY_PERIOD ms. */
void DisplayTask(void *pvParameters) {
    for (;;) {
        displayAircraftStatus();
        vTaskDelay(pdMS_TO_TICKS(DISPLAY_PERIOD));
    }
}
