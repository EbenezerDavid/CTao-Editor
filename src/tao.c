/*  main.c
*
* buiding ...
*
*
*/

#include "tao.h"


int main(int argc, char *argv[]) {

	struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

	if(argc > 2) {
		
		if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--than") == 0) && argc > 2) {
			for(int i = 2; i <= argc - 1; i++) {
				open_file(argv[i]);
			}
		}
		else if((strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--display") == 0) && argc > 2) {

			printf(CLEAR);
			//terminal();
			//printf(BEGIN_MOUSE);
			open_file(argv[2]);

		}
		else if((strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--gnome") == 0) && argc > 2) {
			printf("开发中\n");
		} else {
			printf("%s", error);
		}

	}

	else if(argc == 2) {

		if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			printf("%s", help);
		}
		else if(strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--than") == 0) {
			printf("%s", help);
		}
		else if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--display") == 0) {
			printf("%s", help);
		}
		else if(strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--gnome") == 0) {
			printf("%s", help);
		}
		else {

			newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
			open_file(argv[1]);
			control();
			printf(CLEAR);

		}

	} else {
		printf(BLUE "%s" RESET, distao);
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return EXIT_SUCCESS;
}