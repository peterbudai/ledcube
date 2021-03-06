/**
 * @file timer.h
 * Millisecond resolution timer.
 * This library to be used in applications where precise timing is required.
 * It also drives other periodically refreshing output peripherials like the
 * LED cube and the status LED.
 *
 * @copyright (C) 2017 Peter Budai
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#ifndef NO_TIMER

#include <stdbool.h>
#include <stdint.h>

/**
 * Frequency of the timer in hertz.
 * 1000 Hz means 1 millisecond.
 */
#define TIMER_FREQ 1000

/**
 * Infitine waiting time value.
 * This value can be used in blocking wait functions to indicate that these
 * functions should not time out at all.
 */
#define TIMER_INFINITE UINT16_MAX

/// Initializes and starts the timer.
void timer_init(void);

/// Stops the timer.
void timer_stop(void);

/**
 * Returns the current value if the internal timer.
 *
 * @return Monotonically increasing value that starts at 0, incremented
 *     by 1 each millisecond and it overflows after UINT16_MAX.
 */
uint16_t timer_get_current(void);

/**
 * Returns the number of milliseconds that has elapsed since a given time.
 *
 * @param since A previous timer value obtained from timer_get_current().
 * @return Number of elapsed milliseconds.
 *     If more than UINT16_MAX milliseconds elapsed, the result is undefined.
 */
uint16_t timer_get_elapsed(uint16_t since);

/**
 * Tells whether a given amount of time has elapsed since a given point.
 *
 * @param since A previous timer value obtained from timer_get_current().
 * @param wait_ms How many milliseconds to wait for.
 * @return True if `wait_ms` milliseconds has elapsed since `since`.
 *     If more than UINT16_MAX milliseconds elapsed, the result is undefined.
 */
bool timer_has_elapsed(uint16_t since, uint16_t wait_ms);

/**
 * @name Faster, but thread unsafe versions.
 * Call these function only when interrupts are disabled.
 */
/// @{

/**
 * Returns the current value if the internal timer.
 * Thread unsafe version of timer_get_current().
 *
 * @return Monotonically increasing value that starts at 0, incremented
 *     by 1 each millisecond and it overflows after UINT16_MAX.
 */
uint16_t timer_get_current_unsafe(void);

/**
 * Returns the number of milliseconds that has elapsed since a given time.
 * Thread unsafe version of timer_get_elapsed().
 *
 * @param since A previous timer value obtained from timer_get_current().
 * @return Number of elapsed milliseconds.
 *     If more than UINT16_MAX milliseconds elapsed, the result is undefined.
 */
uint16_t timer_get_elapsed_unsafe(uint16_t since);

/**
 * Tells whether a given amount of time has elapsed since a given point.
 * Thread unsafe version of timer_has_elapsed().
 *
 * @param since A previous timer value obtained from timer_get_current().
 * @param wait_ms How many milliseconds to wait for.
 * @return True if `wait_ms` milliseconds has elapsed since `since`.
 *     If more than UINT16_MAX milliseconds elapsed, the result is undefined.
 */
bool timer_has_elapsed_unsafe(uint16_t since, uint16_t wait_ms);

/// @}

/**
 * Waits until a given amount of time has elapsed.
 * It does not return to the caller until the wait period ends. However,
 * system events are still handled in the meanwhile.
 *
 * @param wait_ms How many milliseconds to wait for.
 */
void timer_wait(uint16_t wait_ms);

#endif // NO_TIMER

#endif // _TIMER_H_
