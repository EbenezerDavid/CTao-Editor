/* utils.c
*
*
*
*/

#include "tao.h"



void terminal(void) {

	struct termios old;
	struct termios new;
	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

void control(void) {

	struct termios oldt;
	struct termios newt;
	tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    printf(CLEAR);
    printf(BEGAIN_MOUSE);
    char key;
    int row = 1;
    int col = 1;
    
    while(1) {
    	read(STDIN_FILENO, &key, 1);

    	if(key == '\033') {
    		read(STDIN_FILENO, &key, 1);
    		if(key == '['){
    			read(STDIN_FILENO, &key, 1);
    			switch(key) {
    				case 'w':
    					if(row > 1) row--;
    					break;
    				case 's':
    					if(row < 24) row++;
    					break;
    				case 'a':
    					if(col > 1) col--;
    					break;
    				case 'd':
    					if(col < 80) col++;
    					break;
    			}

    			printf("\033[%d;%dH", row, col);
    			printf("X");
    			fflush(stdout);
    		}
    	}
    	else if(key == 'q') {
    		break;
    	}
    }

    printf("\033[2J\033[1;1H");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return;
}