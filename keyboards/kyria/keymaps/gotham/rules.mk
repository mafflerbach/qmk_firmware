CONSOLE_ENABLE     = no  # Console for debug
ENCODER_ENABLE     = no  # ENables the use of one or more encoders
RGBLIGHT_ENABLE    = yes  # Enable keyboard RGB underglow
MOUSEKEY_ENABLE    = yes   # Mouse keys
OLED_DRIVER_ENABLE = yes  # Enables the use of OLED displays
THUMBSTICK_ENABLE  = yes  # Enables analog thumbstick code
POINTING_DEVICE_ENABLE = yes
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_utils.c
endif

ifeq ($(strip $(THUMBSTICK_ENABLE)), yes)
    POINTING_DEVICE_ENABLE = yes
    OPT_DEFS += -DTHUMBSTICK_ENABLE
	SRC += analog.c
	SRC += thumbstick.c
endif
