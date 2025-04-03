/* comands.c
*
*
*
*
*/

#include "tao.h"

// tao [Filename] 直接打开或创建文件
/*
int open_create(char *name, int *output) {

	FILE *file = fopen(name, "w+");
}*/

void open_file(const char *filname) {
	FILE *file = fopen(filname, "r");
	if(file == NULL) {
		printf("你没有权限！\n");

		exit(EXIT_FAILURE);
	} else {
		printf(GREEN "========================================================================" RESET "\n");
		printf(RED "%s" RESET "\n", filname);
		printf(GREEN "========================================================================" RESET "\n");
		char line[1024] = {0};
		while(fgets(line, sizeof(line), file) != NULL) {
			printf("%s", line);
		}
		printf("\n");

		fclose(file);
	}
}