/*
 * seatbelt_task.cpp
 */
#include "aircraft.h"
#include "utils.h"

void SeatBeltTask(void *pvParameters) {
    /* TODO */
    bool last_pressed = false; /*released*/
    bool currentPressed;

    for(;;){
        currentPressed = (digitalRead(SEATBELT_BUTTON) == LOW);
        if (last_pressed == false && currentPressed == true){
            seatBeltOn = !seatBeltOn;
            digitalWrite(SEATBELT_LED, seatBeltOn);
        }
        last_pressed = currentPressed;
        vTaskDelay(pdMS_TO_TICKS(BUTTON_POLL_PERIOD));
    };
}
