#include <stdio.h>

void open_and_print(int index, char **file_name);

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("Usage: cat <file1> (<other files>)\n");
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		open_and_print(i, argv);
	}

	return 0;
}

void open_and_print(int index, char **file_name) {
	FILE *fptr;

	fptr = fopen(file_name[index], "r");
	if (fptr == NULL) {
		printf("ERROR: file not opened");
		return;
	}

	while (!feof(fptr)) {
		char letter = fgetc(fptr);
		if (feof(fptr)) break;
		putchar(letter);
	}

	fclose(fptr);

	return;
}
