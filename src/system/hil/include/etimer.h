#include "kernel.h"
#include "timer.h"

enum ETIMER_FUNCTION {
	ETIMER_FUNCTION_SET,
	ETIMER_FUNCTION_RESET,
	ETIMER_FUNCTION_RESTART,
	ETIMER_FUNCTION_ADJUST,
	ETIMER_FUNCTION_EXPIRATION_TIME,
	ETIMER_FUNCTION_START_TIME,
	ETIMER_FUNCTION_EXPIRED,
	ETIMER_FUNCTION_STOP,
	ETIMER_FUNCTION_LAST,
};

enum ETIMER_PROCESSES {
	ETIMER_PROCESS,
	ETIMER_PROCESS_LAST,
};

static component_id etimer_cmp_local_id;
static hil_component_t* etimer_cmp_ref;
static const component_info_t etimer_cmp_info = {ETIMER, 2,7, HIL_COMPONENT,7,"etimer"};


static void etimer_user_adapter_init(){
	etimer_cmp_local_id = kernel_search_hil_cmp(&etimer_cmp_info);
	etimer_cmp_ref = kernel_get_hil_cmp_ref(etimer_cmp_local_id);
}


/**
 * A timer.
 *
 * This structure is used for declaring a timer. The timer must be set
 * with etimer_set() before it can be used.
 *
 * \hideinitializer
 */
struct etimer {
  struct timer timer;
  struct etimer *next;
  struct process *p;
};

/**
 * \brief      Set an event timer.
 * \param et   A pointer to the event timer
 * \param interval The interval before the timer expires.
 *
 *             This function is used to set an event timer for a time
 *             sometime in the future. When the event timer expires,
 *             the event PROCESS_EVENT_TIMER will be posted to the
 *             process that called the etimer_set() function.
 *
 */
static void etimer_set(struct etimer *et, clock_time_t interval){
	( (void (*)(struct etimer*, clock_time_t)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_SET])(et,interval);
}

/**
 * \brief      Reset an event timer with the same interval as was
 *             previously set.
 * \param et   A pointer to the event timer.
 *
 *             This function resets the event timer with the same
 *             interval that was given to the event timer with the
 *             etimer_set() function. The start point of the interval
 *             is the exact time that the event timer last
 *             expired. Therefore, this function will cause the timer
 *             to be stable over time, unlike the etimer_restart()
 *             function.
 *
 * \sa etimer_restart()
 */
static void etimer_reset(struct etimer *et){
	( (void (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_RESET])(et);
}

/**
 * \brief      Restart an event timer from the current point in time
 * \param et   A pointer to the event timer.
 *
 *             This function restarts the event timer with the same
 *             interval that was given to the etimer_set()
 *             function. The event timer will start at the current
 *             time.
 *
 *             \note A periodic timer will drift if this function is
 *             used to reset it. For periodic timers, use the
 *             etimer_reset() function instead.
 *
 * \sa etimer_reset()
 */
static void etimer_restart(struct etimer *et){
	( (void (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_RESTART])(et);
}

/**
 * \brief      Adjust the expiration time for an event timer
 * \param et   A pointer to the event timer.
 * \param td   The time difference to adjust the expiration time with.
 *
 *             This function is used to adjust the time the event
 *             timer will expire. It can be used to synchronize
 *             periodic timers without the need to restart the timer
 *             or change the timer interval.
 *
 *             \note This function should only be used for small
 *             adjustments. For large adjustments use etimer_set()
 *             instead.
 *
 *             \note A periodic timer will drift unless the
 *             etimer_reset() function is used.
 *
 * \sa etimer_set()
 * \sa etimer_reset()
 */
static void etimer_adjust(struct etimer *et, int td){
	( (void (*)(struct etimer*,int)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_ADJUST])(et,td);
}

/**
 * \brief      Get the expiration time for the event timer.
 * \param et   A pointer to the event timer
 * \return     The expiration time for the event timer.
 *
 *             This function returns the expiration time for an event timer.
 */
static clock_time_t etimer_expiration_time(struct etimer *et){
	return ( (clock_time_t (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_EXPIRATION_TIME])(et);
}

/**
 * \brief      Get the start time for the event timer.
 * \param et   A pointer to the event timer
 * \return     The start time for the event timer.
 *
 *             This function returns the start time (when the timer
 *             was last set) for an event timer.
 */
static clock_time_t etimer_start_time(struct etimer *et){
	return ( (clock_time_t (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_START_TIME])(et);
}

/**
 * \brief      Check if an event timer has expired.
 * \param et   A pointer to the event timer
 * \return     Non-zero if the timer has expired, zero otherwise.
 *
 *             This function tests if an event timer has expired and
 *             returns true or false depending on its status.
 */
static int etimer_expired(struct etimer *et){
	return ( (int (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_EXPIRED])(et);
}

/**
 * \brief      Stop a pending event timer.
 * \param et   A pointer to the pending event timer.
 *
 *             This function stops an event timer that has previously
 *             been set with etimer_set() or etimer_reset(). After
 *             this function has been called, the event timer will not
 *             emit any event when it expires.
 *
 */
static void etimer_stop(struct etimer *et){
	( (void (*)(struct etimer*)) etimer_cmp_ref->interface.function_array[ETIMER_FUNCTION_STOP])(et);
}

