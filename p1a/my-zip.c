#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	}
	else {
		char curr;
		char pre;
		int count = 0;
		for (int i = 1; i < argc; i++) {
			count ++;
			FILE *fp = fopen (argv[i], "r");
			if (fp == NULL) {
				printf("my-zip: cannot open file\n");
				exit(1);
			}
			pre = fgetc(fp);
			while (!feof(fp)) { 
				curr = fgetc(fp);				
				if (curr== pre) { 
					count++; 
				}
				else if (curr != pre && (!feof(fp))){
					fwrite(&count, sizeof(int), 1, stdout);
					printf("%c", pre); 
					pre = curr;
					count = 1;
				}	
			}
			if (curr == EOF && i == argc -1) {
				fwrite(&count, sizeof(int), 1, stdout);
                                printf("%c", pre);					
			}
			fclose(fp);	
		}
	}
	return 0;
}
