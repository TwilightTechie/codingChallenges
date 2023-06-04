#include<stdio.h>
#include<string.h>

int main (int argc, char *argv[]) {
		if (argc < 2) {
			printf("Usage: ./ccwc <filename>\n");
			printf("Usage: ./ccwc [-c] <filename>\n");
			printf("Usage: ./ccwc [-l] <filename>\n");
			return 1;
		}
		
		int countByte = 0; 
		int linesOnly = 0;
		char *filename = argv[2];
		
		if(strcmp(argv[1], "-c") == 0) {
			countByte = 1;
		} 
		else if (strcmp(argv[1], "-l") == 0) {
				linesOnly = 1;
		}
		else {
			filename = argv[1];
		}

		FILE *file = fopen(filename, "r");

		if (file == NULL) {
			printf("Error opening the file");
			return 1; 
		}

		int line = 0; 
		int words = 0; 
		int characters = 0; 
		int inWord = 0; 
		char c;

		while ((c = fgetc(file)) != EOF) {
			characters ++;
			if (c == '\n') {
				line++;
			}

			if (c == ' ' || c == '\t' || c == '\n') {
				inWord = 1;
				words ++;
			}
		}
		fclose(file);
		if (countByte) {
			printf("Bytes: %d\n", characters);
		}
		else if (linesOnly){
		printf("Lines: %d\n", line);
		}
		else{
		printf("words: %d\n", words);
		printf("Characters: %d\n", characters);
		return 0;
}
}

