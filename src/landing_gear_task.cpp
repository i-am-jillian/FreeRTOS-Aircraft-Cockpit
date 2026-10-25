/*
 * landing_gear_task.cpp
 */
#include "aircraft.h"
#include "utils.h"

void LandingGearTask(void *pvParameters) {
    /* TODO */
    bool last_pressed = false; /*released*/
    bool currentPressed;

    gearState = GEAR_DOWN;
    digitalWrite(GEAR_DOWN_LED, HIGH);
    digitalWrite(GEAR_CHANGING_LED, LOW);

    for (;;) {
        currentPressed = (digitalRead(GEAR_BUTTON) == LOW);

        if (!last_pressed && currentPressed) {

            bool lastDown = (gearState == GEAR_DOWN);

            gearState = GEAR_CHANGING;
            digitalWrite(GEAR_DOWN_LED, LOW);
            digitalWrite(GEAR_CHANGING_LED, HIGH);

            vTaskDelay(pdMS_TO_TICKS(GEAR_CHANGE_TIME));

            if (lastDown) {
                gearState = GEAR_UP;
            } else {
                gearState = GEAR_DOWN;
            }

            digitalWrite(GEAR_CHANGING_LED, LOW);
            digitalWrite(GEAR_DOWN_LED,
                         gearState == GEAR_DOWN ? HIGH : LOW);
        }

        last_pressed = currentPressed;

        vTaskDelay(pdMS_TO_TICKS(BUTTON_POLL_PERIOD));
    }
}
