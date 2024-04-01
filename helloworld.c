#include <stdio.h>

int main(){

    char palavra[10] = ["a", "b", "a", "c", "a", "t", "e", "\0"];
    for(int i = 0 ; i < 10; i++){
        printf("%c", palavra[i]);
    }
    return 0;
}