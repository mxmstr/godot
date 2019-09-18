
#include "mouse_mapping_windows.h"
//#include "core/os/input_event.h"

#include <stdio.h>

enum ButtonList {
	BUTTON_LEFT = 1,
	BUTTON_RIGHT = 2,
	BUTTON_MIDDLE = 3,
	BUTTON_WHEEL_UP = 4,
	BUTTON_WHEEL_DOWN = 5,
	BUTTON_WHEEL_LEFT = 6,
	BUTTON_WHEEL_RIGHT = 7,
	BUTTON_XBUTTON1 = 8,
	BUTTON_XBUTTON2 = 9,
	BUTTON_MASK_LEFT = (1 << (BUTTON_LEFT - 1)),
	BUTTON_MASK_RIGHT = (1 << (BUTTON_RIGHT - 1)),
	BUTTON_MASK_MIDDLE = (1 << (BUTTON_MIDDLE - 1)),
	BUTTON_MASK_XBUTTON1 = (1 << (BUTTON_XBUTTON1 - 1)),
	BUTTON_MASK_XBUTTON2 = (1 << (BUTTON_XBUTTON2 - 1))
};

struct _WinTranslatePair {

	unsigned int keysym;
	unsigned int keycode;
};

static _WinTranslatePair _vb_to_buttoncode[] = {

	{ BUTTON_LEFT, VK_LBUTTON },
	{ BUTTON_RIGHT, VK_RBUTTON },
	{ BUTTON_MIDDLE, VK_MBUTTON },
	{ BUTTON_WHEEL_UP,  0x0A},
	{ BUTTON_WHEEL_DOWN, 0x0B},
	{ BUTTON_WHEEL_LEFT, 0x0F},
	{ BUTTON_WHEEL_RIGHT, 0x0E},
	{ BUTTON_XBUTTON1, VK_XBUTTON1 },
	{ BUTTON_XBUTTON2, VK_XBUTTON2 },

	{ KEY_UNKNOWN, 0 }
};

unsigned int MouseMappingWindows::get_buttonsym(unsigned int p_code) {

	for (int i = 0; _vb_to_buttoncode[i].keysym != KEY_UNKNOWN; i++) {

		if (_vb_to_buttoncode[i].keycode == p_code)
			return _vb_to_buttoncode[i].keysym;
	}

	return KEY_UNKNOWN;
}


unsigned int MouseMappingWindows::get_buttoncode(unsigned int p_code) {

	for (int i = 0; _vb_to_buttoncode[i].keysym != KEY_UNKNOWN; i++) {

		if (_vb_to_buttoncode[i].keysym == p_code)
			return _vb_to_buttoncode[i].keycode;
	}

	return KEY_UNKNOWN;
}