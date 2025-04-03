/*  tao.h  
*
*Building ...
*
*
*/

#ifndef TAO_H
# define TAO_H

# ifdef __cplusplus
   extern "C" {
# endif

# include   <stdio.h>
# include   <stdlib.h>
# include   <string.h>

# ifdef BY_SDL
   #include <SDL2/SDL.h>
# endif
# ifdef BY_GTK
   #include <gtk/gtk.h>
# endif
# ifdef BY_FL
   #include <FL/Fl.H>
   #include <FL/Fl_Window.H>
# endif

# if defined (_WIN32)
   #include <windows.h>
   #include <windowsx.h>
   #include <commctrl.h>
   #include <gdiplus.h>
# endif

# if defined (__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
   #include <termios.h>
   #include <unistd.h>
   #include <X11/Xlib.h>
   #include <X11/Xutil.h>
   #include <X11/keysym.h>
   #include <wayland-client.h>
   #include <xkbcommon/xkbcommon.h>
# endif

# if defined (__APPLE__)
   #include <Carbon/Carbon.h>
   #include <ApplicationServices/ApplicationServices.h>
# endif

//bool value
# define TRUE     1
# define FALSE    0

# define DEBUG    printf("Debug\n")

//OS-type
# if defined   (__linux__)
   #define OS_NAME         "Linux"
   #define OS_TYPE         1
# elif defined (_WIN32)
   #define OS_NAME         "Windows"
   #define OS_TYPE         2
   #if defined (_WIN64)
      #define OS_BITS      "64-BIT"
   #else
      #define OS_BITS      "32-BIT"
   #endif
# elif defined (__CYGWIN__)
   #define OS_NAME         "Cygwin"
   #define OS_TYPE         3
# elif defined (__MINGW32__)
   #define OS_NAME         "MinGW 32-bit"
   #define OS_TYPE         4
# elif defined (__MINGW64__)
   #define OS_NAME         "MinGW 64-bit"
   #define OS_TYPE         5
# elif defined (__APPLE__) && defined (__MACH__)
   #define OS_NAME         "macOS"
   #define OS_TYPE         6
# elif defined (__FreeBSD__)
   #define OS_NAME         "FreeBSD"
   #define OS_TYPE         7
# elif defined (__NetBSD__)
   #define OS_NAME         "NetBSD"
   #define OS_TYPE         8
# elif defined (__OpenBSD__)
   #define OS_NAME         "OpenBSD"
   #define OS_TYPE         9
# elif defined (__sun)
   #define OS_NAME         "Solaris"
   #define OS_TYPE         10
# elif defined (__unix__)
   #define OS_NAME         "Unix"
   #define OS_TYPE         11
# else
   #define OS_NAME         "Unknown"
   #define OS_TYPE         0
# endif

//All system color
#if defined (_WIN32) && !defined (__CYGWIN__)
   #define RED     set_color(FOREGROUND_RED)
   #define GREEN   set_color(FOREGROUND_GREEN)
   #define BLUE    set_color(FOREGROUND_BLUE)
   #define YELLOW  set_color(FOREGROUND_RED | FOREGROUND_GREEN)
   #define PURPLE  set_color(FOREGROUND_RED | FOREGROUND_BLUE)
   #define CYAN    set_color(FOREGROUND_GREEN | FOREGROUND_BLUE)
   #define WHITE   set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
   #define RESET   set_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
# else
   #define RED             "\033[31m"
   #define GREEN           "\033[32m"
   #define YELLOW          "\033[33m"
   #define BLUE            "\033[34m"
   #define PURPLE          "\033[35m"
   #define CYAN            "\033[36m"
   #define WHITE           "\033[37m"
   #define RESET           "\033[0m"  //去除颜色
   #define CLEAR             "\033[2J"
   #define BEGIN_MOUSE       "\033[1;1H"
# endif

//这里是一些文档说明的声明地
extern const char distao[];
extern const char help[];
extern const char error[];

//这里是本程序所有函数声明的地方
char *open_file(const char *filename);
//int open_create(char *name, int *output);
int sys_type(void);
void set_color(int color);
int terminal(void);
int turn_up_down(int *input);

# ifdef __cplusplus
}
# endif

#endif