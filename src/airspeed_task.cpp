/*
 * airspeed_task.cpp
 */
#include "aircraft.h"
#include "utils.h"

void AirspeedTask(void *pvParameters) {
    /* TODO */
    for (;;){
        airspeed = getAirspeedLevel();
        vTaskDelay(pdMS_TO_TICKS(AIRSPEED_PERIOD));
    } 
}
