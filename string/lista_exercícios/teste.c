#include <stdio.h>
#include <string.h>

int main(){

    char* str = "abacate";
    char buffer[strlen(str)];
    
    strcpy(buffer, str);

    int i = strcspn(buffer, "aeoiu");
    while(i < strlen(str)){
        buffer[i] = '*';
        i = strcspn(buffer, "aeoiu");
    }
    printf("%s", buffer);

    return 0;
}