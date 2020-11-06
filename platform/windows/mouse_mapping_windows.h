
#ifndef MOUSE_MAPPING_WINDOWS_H
#define MOUSE_MAPPING_WINDOWS_H

#include "core/os/keyboard.h"

#include <windows.h>

#include <winuser.h>

class MouseMappingWindows {

	MouseMappingWindows(){};

public:
	static unsigned int get_buttonsym(unsigned int p_code);
	static unsigned int get_buttoncode(unsigned int p_code);
};

#endif // MOUSE_MAPPING_WINDOWS_H
