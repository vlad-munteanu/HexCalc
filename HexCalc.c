#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"

void handleFlags(int argc, char *argv[]);

void usage() {
    printf("Usage: [-c] [-s] <num> <operator> <num>/n");
    printf("-c: Convert\n");
    exit(1); 
}

/* Possible Usage 
 * HexCalc <arg> num <operator> 
 * HexCalc num  
 *
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
    }
    

    // Check Convert Flag 
    // Segmentation fault if argv[1] is a num 
    // Check if there is flags   
    if (argc >= 3) {
        handleFlags(argc, argv);
    }
    return 0;  
}

void handleFlags(int argc, char *argv[]) {
    if (!strcmp(argv[1],"-c")) { // To Decimal
        long convertedNumber = strtol(argv[2], NULL, 16);
        
        if (convertedNumber == -1) {
            printf("Something went wrong idk what\n");
        } else {
            printf("Converted Number: %d\n", convertedNumber);
        }
    } else if (strcmp(argv[1],"-s")) { // String

    }
}
