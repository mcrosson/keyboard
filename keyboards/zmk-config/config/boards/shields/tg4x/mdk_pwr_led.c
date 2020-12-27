/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define PWR_LED_NODE DT_ALIAS(led1-blue)

#if DT_NODE_HAS_STATUS(PWR_LED_NODE, okay)
#define PWR_LED DT_GPIO_LABEL(PWR_LED_NODE, gpios)
#define PWR_LED_PIN DT_GPIO_PIN(PWR_LED_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: pwr_led devicetree alias is not defined"
#define PWR_LED ""
#define PIN	0
#define FLAGS 0
#endif

static int pwr_led_init(const struct device *_arg) {
	ARG_UNUSED(_arg);    

	const struct device *dev;
	int ret;

	dev = device_get_binding(PWR_LED);
	if (dev == NULL) {
		return;
	}

	ret = gpio_pin_configure(dev, PWR_LED_PIN, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return;
	}

	gpio_pin_set(dev, PIN, (int)true);

	return 0;
}

SYS_INIT(pwr_led_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
