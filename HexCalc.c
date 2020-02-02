#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"

void handleFlags(int argc, char *argv[]);
int hex_to_int(char c);
int hex_to_ascii(char c, char d);

void usage() {
    printf("Usage:\n");
    printf("-c: Convert Hex to Decimal \n");
    printf("-cd: Convert Decimal to Hex \n");
    printf("-s: Convert Hex to String \n");
    printf("-sh: Convert String to Hex \n");
    
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
    } else {
       usage();
    }
    return 0;
}

void handleFlags(int argc, char *argv[]) {
    if (!strcmp(argv[1],"-c")) { // To Decimal
        long convertedNumber = strtol(argv[2], NULL, 16);
        
        if (convertedNumber == -1) {
            printf("Something went wrong idk what\n");
        } else {
            printf("Decimal: %d\n", convertedNumber);
        }
    } else if (!strcmp(argv[1],"-cd")) { // To Hex
        int temp = atoi(argv[2]);
        printf("Hex: 0x%04x\n", temp);
    } else if (!strcmp(argv[1],"-s")) { // To String
        const char* st = argv[2];
        int length = strlen(st);
        int i;
        char buf = 0;
        for(i = 0; i < length; i++){
            if(i % 2 != 0){
                printf("%c", hex_to_ascii(buf, st[i]));
            }else{
                buf = st[i];
            }
        }
        printf("\n");
    } else if (!strcmp(argv[1], "-sh")) { // String to Hex
        char *str = argv[2];
        while (*str) {
            printf("%c %u %x\n", *str, *str, *str);
            str++;
        }
    }
}

int hex_to_int(char c){
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first*10 + second;
    if(result > 9) result--;
    return result;
}

int hex_to_ascii(char c, char d){
    int high = hex_to_int(c) * 16;
    int low = hex_to_int(d);
    return high+low;
}
