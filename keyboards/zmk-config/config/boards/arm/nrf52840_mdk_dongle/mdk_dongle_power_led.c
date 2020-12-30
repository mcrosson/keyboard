/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define POWER_LED_NODE DT_ALIAS(led1_red)

#if DT_NODE_HAS_STATUS(POWER_LED_NODE, okay)
#define POWER_LED DT_GPIO_LABEL(POWER_LED_NODE, gpios)
#define PIN DT_GPIO_PIN(POWER_LED_NODE, gpios)
#define FLAGS DT_GPIO_FLAGS(POWER_LED_NODE, gpios)
#else
#error "Unsupported board: power led devicetree alias is not defined"
#define POWER_LED ""
#define PIN 0
#define FLAGS 0
#endif

static int pwr_led_init(const struct device *dev) {
	dev = device_get_binding(POWER_LED);
	if (dev == NULL) {
		return -EIO;
	}

	int ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return -EIO;
	}

	return gpio_pin_set(dev, PIN, true);
}

SYS_INIT(pwr_led_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
