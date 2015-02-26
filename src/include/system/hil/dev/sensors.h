/*
 * Copyright (c) 2009, Swedish Institute of Computer Science
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 */

#ifndef __SENSORS_H__
#define __SENSORS_H__
#include "kernel.h"
#include "sensors-constdef.h"

static const hil_component_t* sensors_cmpobj_ref;


//#include "contiki.h"
#include "src/system/hil/sys/process/process.h"

/* some constants for the configure API */
#define SENSORS_HW_INIT 128 /* internal - used only for initialization */
#define SENSORS_ACTIVE 129 /* ACTIVE => 0 -> turn off, 1 -> turn on */
#define SENSORS_READY 130 /* read only */

#define SENSORS_ACTIVATE(sensor) (sensor).configure(SENSORS_ACTIVE, 1)
#define SENSORS_DEACTIVATE(sensor) (sensor).configure(SENSORS_ACTIVE, 0)

#define SENSORS_SENSOR(name, type, value, configure, status)        \
const struct sensors_sensor name = { type, value, configure, status }

#define SENSORS_NUM (sizeof(sensors) / sizeof(struct sensors_sensor *))

#define SENSORS(...) \
const struct sensors_sensor *sensors[] = {__VA_ARGS__, NULL};       \
unsigned char sensors_flags[SENSORS_NUM]

struct sensors_sensor {
  char *       type;
  int          (* value)     (int type);
  int          (* configure) (int type, int value);
  int          (* status)    (int type);
};


/* Stub function declaration for sensors_find(const char *) */
static inline const struct sensors_sensor *sensors_find(const char *type){
	return ( (const struct sensors_sensor* (*)(const char *)) sensors_cmpobj_ref->interface.function_array[FUNCTION_SENSORS_FIND])(type);
}

/* Stub function declaration for sensors_next(const struct sensors_sensor *) */
static inline const struct sensors_sensor *sensors_next(const struct sensors_sensor *s){
	return ( (const struct sensors_sensor* (*)(const struct sensors_sensor *)) sensors_cmpobj_ref->interface.function_array[FUNCTION_SENSORS_NEXT])(s);
}

/* Stub function declaration for sensors_first(void) */
static inline const struct sensors_sensor *sensors_first(void){
	return ( (const struct sensors_sensor* (*)(void)) sensors_cmpobj_ref->interface.function_array[FUNCTION_SENSORS_FIRST])();
}


/* Stub function declaration for sensors_changed(const struct sensors_sensor *) */
static inline void sensors_changed(const struct sensors_sensor *s){
	( (void (*)(const struct sensors_sensor *)) sensors_cmpobj_ref->interface.function_array[FUNCTION_SENSORS_CHANGED])(s);
}


/* Stub function declaration for sensors_get_sensors_event() */
static inline process_event_t sensors_get_sensors_event(){
	return ( (process_event_t (*)()) sensors_cmpobj_ref->interface.function_array[FUNCTION_SENSORS_GET_SENSORS_EVENT])();
}

extern process_event_t sensors_event;

PROCESS_NAME(sensors_process);

#endif /* __SENSORS_H__ */
