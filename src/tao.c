/*  main.c
*
* buiding ...
*
*
*/

#include "tao.h"


int main(int argc, char *argv[]) {


	if(argc > 2) {
		
		if((strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--than") == 0) && argc > 2) {
			for(int i = 2; i <= argc - 1; i++) {
				//
			}
		}
		else if((strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--display") == 0) && argc > 2) {
			//

		}
		else if((strcmp(argv[1], "-g") == 0 || strcmp(argv[1], "--gnome") == 0) && argc > 2) {
			DEBUG;
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
			//
			int iclear;
			iclear = terminal();
			if(iclear == 1) {
				turn_up_down(iclear);
				open_file(argv[1]);
			}
		}

	} else {
		printf(BLUE "%s" RESET, distao);
	}

	return EXIT_SUCCESS;
}
