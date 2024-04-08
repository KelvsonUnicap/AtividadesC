#include <stdio.h>
#include <string.h>
#include "login.h"

#define MAX 10

// int check_password(char *pass){
//     if(strcmp(pass, k) == 0){
//         return 0;
//     }
//     return -1;
// }

// void count_characters(char *pass){
//     int count = 0;
//     while(pass[count] != 0){
//         count++;
//    }
// }

int main(){

    char fpass[MAX];
    fgets(fpass, MAX-1, stdin);

    printf(strcmp(fpass, "12345") == 0 ? "Iguais" : "Diferentes");

    // count_characters(fpass);

    return 0;
}