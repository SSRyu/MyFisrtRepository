#pragma once
#include <stdio.h>
#include <stdlib.h>

int scanInt(char* txt);

// scan just int type variable
#define bufSize 512
int scanInt(char* txt) {
    char str[bufSize];
    int num, error = 0;

    while(1) {
        printf("%s", txt);
        fgets(str, bufSize, stdin);
        if(str[0] == '\n') {
            continue;
        }
        for(int i = 0; str[i] != '\n'; ++i) {
            if(str[i] - '0' < 0 || str[i] - '0' > 9) {
                ++error;
                break;
            }
        }
        if(error > 0) {
            printf("整数ではありません。\n");
            error = 0;
            continue;
        }
        num = atoi(str);
        break;
    }
    return num;
}