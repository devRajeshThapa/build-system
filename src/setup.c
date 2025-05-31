#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include "setup.h"

void create_folder(char *path){
	if(mkdir(path, 0755) == -1){
		perror("mkdir");
		exit(EXIT_FAILURE);
	}
}

void create_file(char *filepath, char *content){
	FILE *fp = fopen(filepath, "w");
	if(!fp){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fputs(content, fp);
	fclose(fp);
}

void setup_template(char *project_name){
	char path[256];
	char buffer[256];

	create_folder(project_name);

	snprintf(path, sizeof(path), "%s/include", project_name);	
	create_folder(path);

	snprintf(path, sizeof(path), "%s/src", project_name);	
	create_folder(path);

	snprintf(path, sizeof(path), "%s/src/main.c", project_name);	
	create_file(path,
	     "#include <stdio.h>\n\n"
	     "int main(int argc, char *argv[]){\n"
	     "\tprintf(\"Hello, World!\");\n"
	     "\treturn 0;\n"
	     "}"
	     );

	snprintf(path, sizeof(path), "%s/package.toml", project_name);	
	snprintf(buffer, sizeof(buffer),
	  "[package]\n"
	  "name = \"%s\"\n"
	  "version = \"0.1.0\"\n"
	  "authors = []\n"
	  "description = \"\"\n"
	  "license = \"\"\n\n"
	  "[dependencies]\n"
	  "devrajeshthapa/dotenv",
	  project_name);	
	create_file(path, buffer);

	snprintf(path, sizeof(path), "%s/.env", project_name);	
	create_file(path,"");

	snprintf(path, sizeof(path), "%s/README.md", project_name);	
	snprintf(buffer, sizeof(buffer),
	  "# %s",
	  project_name);
	create_file(path, buffer);


	snprintf(path, sizeof(path), "%s/.gitignore", project_name);	
	create_file(path,
	     "# Ignore dependencies\n"
	     "dependencies/\n\n"
	     "# Ignore compiled binaries and build artifacts\n"
	     "dist/\n\n"
	     "# Ignore environment variables\n"
	     ".env\n"
	     );
}
