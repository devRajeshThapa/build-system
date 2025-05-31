#include <stdio.h>
#include <string.h>
#include "setup.h"
#include "package.h"

int main(int argc, char *argv[]){
	if(strcmp(argv[1], "new") == 0){
		if(argv[2]){
     			setup_template(argv[2]);
		}
	}else if(strcmp(argv[1], "install") == 0){
		if(!argv[2]){
			install_packages();
		}
	}
	return 0;
}
