#include <stdio.h> 
#include <stdlib.h> 

void usage() {
    printf("Usage: [-c] <num> <operator> <num>/n");
    exit(1); 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage();
    }

    // Check Convert Flag 
    if (strcmp(argv[1],"-c")) { 
        int numToConvert = strtol(argv[], NULL, 16);
    }  


    return 0;  
}


