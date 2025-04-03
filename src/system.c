/* system.c
*
*
*/

#include "tao.h"

#if defined (_WIN32)
#include <windows.h>
#endif

#if defined (_WIN32) && !defined (__CYGWIN__)
	void set_color(int color) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}
#else
	void set_color(int color) {	
	}
#endif

int sys_type(void) {
    #if defined(__linux__) || defined(__unix__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
    const char *display = getenv("DISPLAY");
    const char *wayland = getenv("WAYLAND_DISPLAY");
    return (display != NULL && strlen(display) > 0) || 
           (wayland != NULL && strlen(wayland) > 0);
    #elif defined(_WIN32)
    return GetSystemMetrics(SM_CMONITORS) > 0;
    #elif defined(__APPLE__)
    return 1;
    #else
    return 0;
    #endif
}
