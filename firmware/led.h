#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT PORTD
#define LED_BIT (1 << PORTD2)

#define led_on() LED_PORT |= LED_BIT
#define led_off() LED_PORT &= ~LED_BIT
#define led_toggle() LED_PORT ^= LED_BIT
#define led_blink(ms) \
	led_on(); \
	_delay_ms(ms); \
	led_off()

#endif /* LED_H_ */
