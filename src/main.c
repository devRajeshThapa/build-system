#include <stdio.h>
#include <string.h>
#include "setup.h"

int main(int argc, char *argv[]){
	if(strcmp(argv[1], "new") == 0){
		if(argv[2]){
     			setup_template(argv[2]);
		}
	}
	return 0;
}
