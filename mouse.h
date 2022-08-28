#pragma once
#include <stdint.h>

enum mouse_command : uint8_t
{
  RESET = 0xFF,
  ACK = 0xFA,
  BAT_OK = 0xAA,
  BAT_FAIL = 0xFC,
  MOUSE_ID = 0x00,
  SET_SAMPLE_RATE = 0xF3,
  READ_DEVICE_TYPE = 0xF2,
  SET_RESOLUTION = 0xE8,
  SET_SCALING = 0xE6,
  SET_STATUS_INDICATORS = 0xED,
  ENABLE = 0xF4
};

typedef enum MOUSE_INIT_STATE : uint8_t {
  OFF = 0,
  POWERUP_BAT_WAIT,
  POWERUP_ID_WAIT,
  PRE_RESET,
  START_RESET,
  RESET_ACK_WAIT,
  RESET_BAT_WAIT,
  RESET_ID_WAIT,
  
  SAMPLERATECMD_ACK_WAIT,
  SAMPLERATE_ACK_WAIT,

  ENABLE_ACK_WAIT,
  MOUSE_INIT_DONE,
  MOUSE_READY,

  KBD_SET_LEDS1,
  SET_LEDS1_ACK_WAIT,
  KBD_SET_LEDS2,
  SET_LEDS2_ACK_WAIT,
  KBD_READY,
  
  FAILED = 255
} MOUSE_INIT_STATE_T;

extern MOUSE_INIT_STATE_T mouse_init_state;
extern uint8_t kbd_init_state;

#define MOUSE_REARM_WATCHDOG() \
      watchdog_armed = true; \
      watchdog_timer = 255; \
      watchdog_expire_state = (MOUSE_INIT_STATE::START_RESET)

#define MOUSE_WATCHDOG(x) \
      watchdog_armed = true; \
      watchdog_timer = 255; \
      watchdog_expire_state = (x)

#define MOUSE_DISARM_WATCHDOG() watchdog_armed = false
  
void MouseTick();
void KeyboardTick();