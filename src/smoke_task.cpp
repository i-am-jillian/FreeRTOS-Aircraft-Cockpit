/*
 * smoke_task.cpp
 */
#include "aircraft.h"
#include "utils.h"

void SmokeDetectionTask(void *pvParameters) {
    /* TODO */
    bool currentPressed;

    for (;;) {
        currentPressed = (digitalRead(SMOKE_BUTTON) == LOW);

        if (currentPressed == true) {
            smokeDetected = true;

            TickType_t startTime = xTaskGetTickCount();
            TickType_t alarmTime = pdMS_TO_TICKS(SMOKE_ALARM_TIME);
            TickType_t flashTime = pdMS_TO_TICKS(SMOKE_FLASH_RATE);

            bool ledOn = true;
            digitalWrite(SMOKE_LED, HIGH);

            while ((xTaskGetTickCount() - startTime) < alarmTime) {
                TickType_t elapsed = xTaskGetTickCount() - startTime;
                TickType_t remaining = alarmTime - elapsed;
                TickType_t waitTime = (remaining < flashTime) ? remaining : flashTime;
                vTaskDelay(waitTime);

                if ((xTaskGetTickCount() - startTime) < alarmTime) {
                    ledOn = !ledOn;
                    digitalWrite(SMOKE_LED, ledOn);
                }
            }

            digitalWrite(SMOKE_LED, LOW);
            smokeDetected = false;
        }

    vTaskDelay(pdMS_TO_TICKS(SMOKE_POLL_PERIOD));
}
}
