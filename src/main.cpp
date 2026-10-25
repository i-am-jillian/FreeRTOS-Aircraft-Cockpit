/*
 * main.cpp
 */
#include "aircraft.h"
#include "utils.h"

void setup() {
    Serial.begin(115200);

    /* TODO */
    /*set up leds*/
    pinMode(WING_LIGHT_LED, OUTPUT);
    pinMode(SEATBELT_LED, OUTPUT);
    pinMode(GEAR_DOWN_LED, OUTPUT);
    pinMode(GEAR_CHANGING_LED, OUTPUT);
    pinMode(SMOKE_LED, OUTPUT);
    
    /*set up buttons*/
    pinMode(SEATBELT_BUTTON, INPUT_PULLUP);
    pinMode(GEAR_BUTTON, INPUT_PULLUP);
    pinMode(SMOKE_BUTTON, INPUT_PULLUP);

    /*create tasks*/
    xTaskCreate(
        AirspeedTask,
        "Aircraft",
        TASK_STACK_SIZE,
        NULL,
        TASK_PRIORITY,
        NULL
    );

    xTaskCreate(
        WingLightTask,
        "Wing Light",
        TASK_STACK_SIZE,
        NULL,
        TASK_PRIORITY,
        NULL
    );

    xTaskCreate(
        SeatBeltTask,
        "Seat Belt",
        TASK_STACK_SIZE,
        NULL,
        TASK_PRIORITY,
        NULL
    );

    xTaskCreate(
        LandingGearTask,
        "Landing Gear",
        TASK_STACK_SIZE,
        NULL,
        TASK_PRIORITY,
        NULL
    );

    xTaskCreate(
        SmokeDetectionTask,
        "Smoke Detection",
        TASK_STACK_SIZE,
        NULL,
        SMOKE_PRIORITY,
        NULL
    );

    xTaskCreate(
        DisplayTask,
        "Display",
        DISPLAY_STACK_SIZE,
        NULL,
        DISPLAY_PRIORITY,
        NULL
    );
    
}

void loop() {
    /* Empty */
}
