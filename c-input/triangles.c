#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]){
    if (argc == 1){
        printf("please enter user or horizontal after ./a.out to determine your input type.\n");
        exit(1);
    }
    if (strcmp(argv[1], "user") == 0){
        printf("enter 3 numbers in the following format\n num1 num2 num3\nto determine the validity of triangle\n");
        char buffer[256];
        fgets(buffer, 255, stdin);
        int a, b, c;
        sscanf(buffer, "%d %d %d", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a){
            printf("valid\n");
        }
        else printf("invalid\n");
    }
    if (strcmp(argv[1], "horizontal") == 0){
        FILE * file = fopen("input.txt", "r");
        int pass = 0;
        int fail = 0;
        char buffer[256];
        int a, b, c;
        while(fgets(buffer, 256, file)){
            sscanf(buffer, "%d %d %d", &a, &b, &c);
            if (a + b > c && a + c > b && b + c > a){
                pass ++;
            }
            else fail ++;
        }
        printf("Amount passed: %d\n", pass);
        printf("Amount failed: %d\n", fail);
    }
    if (strcmp(argv[1], "vertical") == 0){
        FILE * file = fopen("input.txt", "r");
        int pass = 0;
        int fail = 0;
        char buffer[256];
        int a, b, c;
        int one, two, three;
        int alpha, beta, gamma;
        while(fgets(buffer, 256, file)){
            sscanf(buffer, "%d %d %d", &a, &b, &c);
            fgets(buffer, 256, file);
            sscanf(buffer, "%d %d %d", &one, &two, &three);
            fgets(buffer, 256, file);
            sscanf(buffer, "%d %d %d", &alpha, &beta, &gamma);
            if (a + one > alpha && a + alpha > one && one + alpha > a){
                pass ++;
            }
            else fail ++;
            if (b + two > beta && b + beta > two && two + beta > b){
                pass ++;
            }
            else fail ++;
            if (c + three > gamma && c + gamma > three && three + gamma > c){
                pass ++;
            }
            else fail ++;
        }
        printf("Amount passed: %d\n", pass);
        printf("Amount failed: %d\n", fail);
    }
    return 0;
}