/*
Write a C program on Linux, which does the following:
Reads a CSV file with columns Name, MISID, Marks; then calculates the average, total, and median marks, and saves all the result in another CSV file with columns statistics, number. The filenames should be accepted as command-line arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define PATH_LIMIT 40


int file_exists(const char *filename) { 
    // returns 0 if file exists, -1 if it doesn't.
    return access(filename, F_OK==0); 
}


void read_file(FILE *file_name){
    char line[1000];

    while(fgets(line, sizeof(line), file_name)) {
        char *token;
        token = strtok(line, ",");

        while(token != NULL) {
            printf("%s", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    
    return;
}

int main(void){
    printf("Enter the path to .csv file that is to be read\n");
    const char str[PATH_LIMIT];
    scanf("%[^\n]s",str);

    if(file_exists(str) == 0) {
        FILE *fptr = fopen(str, "r");
        read_file(fptr);
        fclose(fptr);
    }
    else{
        perror("Error finding file");
        exit(1);
    }
    

    return 0;   
}