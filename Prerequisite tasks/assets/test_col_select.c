// C program for the above approach
// #include <conio.h>
#include <stdio.h>
#include <string.h>

// Driver Code
int main()
{
	// Substitute the full file path
	// for the string file_path
	FILE* fp = fopen("./processed_data.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1200];

		int row = 0;
		int column = 0;

        FILE *final_score = fopen("marks.csv", "w+");

		while (fgets(buffer,
					1200, fp)) {
			column = 0;
			row++;

			// Splitting the data
			char* value = strtok(buffer, ", ");

			while (value) {

                if (column == 4) {
					fprintf(final_score, value);
				}

				// printf("%s", value);
				value = strtok(NULL, ", ");
				column++;
			}
		}

		// Close the file
		fclose(fp);
        fclose(final_score);
	}
	return 0;
}
