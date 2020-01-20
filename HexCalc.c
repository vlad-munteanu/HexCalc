#include <stdio.h> 
#include <stdlib.h> 

void usage() {
    printf("Usage: [-c] <num> <operator> <num>/n");
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
    if (strcmp(argv[1],"-c")) { 
        int numToConvert = strtol(argv[2], NULL, 16);
     //   printf("Num %d", numToConvert);
        printf(numToConvert);
    } else { 

    } 


    return 0;  
}


