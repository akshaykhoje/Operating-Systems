/*
Write a C program on Linux, which does the following:
Reads a CSV file with columns Name, MISID, Marks; then calculates the average, total, and median marks, and saves all the result in another CSV file with columns statistics, number. The filenames should be accepted as command-line arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PATH_LIMIT 40
#define BUFFER_SIZE 100


int file_exists(const char *filename) { 
    // returns 0 if file exists, -1 if it doesn't.
    return access(filename, F_OK==0); 
}


void read_file(const char *str){
    FILE *fptr = fopen(str, "r");

    char line[1000];

    while(fgets(line, sizeof(line), fptr)) {
        char *token;
        token = strtok(line, ",");

        while(token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(fptr);
    return;
}

double *getSum(const char *str, double A[])   // total and average yet to be fixed
{
    double average, sum = 0;
    int total = 0;
    char buffer[BUFFER_SIZE];
    FILE *fptr = fopen(str, "r");
    
    while(fgets(buffer, BUFFER_SIZE, fptr) != NULL) {
        sum += atof(buffer);         //sum of scores
        total++;
    }

    average = sum/total;     //avg value

    A[0] = sum;
    A[1] = average;

    fclose(fptr);
    return A;
}


// double *median(const char *str, int size, double *median_val) {
//     double median_pos=0, read_val=0, count=0;
//     median_pos = size/2;

//     FILE *fptr = fopen(str, "r");
//     while(fscanf(fptr, "%d", &read_val) == 1) {
//         if(median_pos == count){
//             *median_val = read_val;
//         }
//         if((median_pos += 1) == count) {
//             if(size %2){
//                 *median_val /= 2;
//             }
//             else{
//                 *median_val += read_val;
//                 *median_val /= 2;
//             }
//         }
//         count++;
//     }
//     return median_val;
// }


int result(const char *str){
    //calculate the result
    FILE *fptr = fopen(str, "r");
    char buffer[BUFFER_SIZE];

	int row = 0;
	int column = 0;

    FILE *final_score = fopen("marks.csv", "w+");

	while (fgets(buffer, BUFFER_SIZE, fptr)) {
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
    fclose(final_score);
    fclose(fptr);

    double arr[2];
    double *sum_avg = getSum("marks.csv", &arr[0]);
    printf("sum : %lf\n", sum_avg[0]);
    printf("average : %lf\n", sum_avg[1]);

    // double med_value; 
    // median("marks.csv", 86, &med_value);         // 86 is the number of entries
    // printf("median : %lf\n", med_value);
    

    //write the result
    FILE *res = fopen("results.csv", "w+");
    fprintf(res, "Average, Total, Median\n");
    fclose(res);
    return 0;
}


int main(void){
    printf("Enter the path to .csv file that is to be read\n");
    const char str[PATH_LIMIT];
    scanf("%[^\n]s",str);

    if(file_exists(str) == 0) {
        // FILE *fptr = fopen(str, "r");
        read_file(str);
        result(str);
        // fclose(fptr);
    }
    else{
        perror("Error finding file");
        exit(1);
    }
    
    return 0;   
}
