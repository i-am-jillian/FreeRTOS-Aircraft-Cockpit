/*
 * wing_light_task.cpp
 */
#include "aircraft.h"
#include "utils.h"

void WingLightTask(void *pvParameters) {
    /* TODO */
    for(;;){
        digitalWrite(WING_LIGHT_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(WING_LIGHT_BLINK_RATE));

        digitalWrite(WING_LIGHT_LED, LOW);
        vTaskDelay(pdMS_TO_TICKS(WING_LIGHT_BLINK_RATE));
    }
}
