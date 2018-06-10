#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE (512)

int main(int argc, char * argv[]) {

	if(argc == 0) {
		exit(0);
	}
	else if (argc == 1) {
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}
	else if (argc == 2) {
		char buffer[BUFFER_SIZE];
		while(fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
			if(strstr(buffer, argv[1]) != NULL) { 
				printf("%s", buffer);
			}
		}			
	}
	else {
		for (int i  = 2; i <argc; i++) {
			FILE *fp = fopen(argv[i], "r");
			if (fp == NULL) {
				printf("my-grep: cannot open file\n");
				exit(1);
			}
			char *line = NULL;
			size_t len = 0;
			ssize_t nread;
                	while ((nread = getline(&line, &len, fp)) != -1) {
                        	if (strstr(line, argv[1]) != NULL) {
                                	printf("%s", line);
                        	}
                        	else {
                                	continue;
                        	}  
                	} 	
			
		fclose(fp);
		}
	}
	return 0;

}
