#include<stdio.h>

int main (int argc, char *argv[]) {
		if (argc < 2) {
			printf("Usage: ./ccwc <filename>\n");
			return 1;
		}
		FILE *file = fopen(argv[1], "r");

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

		printf("Lines: %d\n", line);
		printf("words: %d\n", words);
		printf("Characters: %d\n", characters);

		return 0;
}

