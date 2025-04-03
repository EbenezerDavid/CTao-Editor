/* utils.c
*
*
*
*/

#include "tao.h"

int terminal(void) {

    //Linux清理屏幕
    int i;
    i = write(STDOUT_FILENO, "\033[2J\033[1;1H", 8);

    return i;
}

int turn_up_down(int *input) {
    if(*input == 1) {
        struct termios old;
        struct termios new;
        new = old;
        new.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &new);

        return 0;
    }
    else if(input == 2) {
    } else {
        return 1;
    }
}

char *open_file(const char *filename) {
    int file = open(filename, O_RDONLY);
    if(file >= 0) {
        char buffer[] = (char)malloc(sizeof(char));
        read(file, buffer, strlen(buffer));
        close(file);

        return buffer;
    } else {
        write(STDOUT_FILENO, "", 0);
    }
}

int choice(char *key) {

    switch(key) {

        case 'w':
            //
        case 's':
            //
        case 'a':
            //
        case 'd':
            //
        case 'i':
            char string;
            read(STDIN_FILENO, &string, 1);
            write(STDOUT_FILENO, &string, 1);
        case 'w':
            int file = open(filename, O_RDONLY | O_CREAT | O_TRUNC, 0644);
            write(fd, buffer, strlen(buffer));
            close(file);
        case 'q':
            tcsetattr(STDIN_FILENO, TCSANOW, &)
    }
}