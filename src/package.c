#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void install_packages(){
	char content[1024];

	FILE *fp = fopen("package.toml", "r");
	if(!fp){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fgets(content, sizeof(content), fp);
	printf("%s", content);
}
