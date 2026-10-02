// Standard Library Imports
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

// Macro definitions
#define USER_LED GPIO_NUM_21

void app_main() 
{
    // Blinky LED config (GPIO21)
	gpio_config_t led_config = {
		.pin_bit_mask = 1ULL << USER_LED,
		.mode = GPIO_MODE_OUTPUT,
		.pull_up_en = GPIO_PULLUP_DISABLE,
		.pull_down_en = GPIO_PULLDOWN_DISABLE,
		.intr_type = GPIO_INTR_DISABLE,
	};
	gpio_config(&led_config);

    // Polling Loop
    while(1) {
        // Blinky
		gpio_set_level(USER_LED, 0);
		vTaskDelay(pdMS_TO_TICKS(250));
		gpio_set_level(USER_LED, 1);
		vTaskDelay(pdMS_TO_TICKS(250));
    }
}