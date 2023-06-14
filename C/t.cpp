#include <stdio.h>
#include <string.h>
 
enum { max = 127 };
static char str[max + 1] = "";
 
int main(void){
    fgets(str, max, stdin);
    int n = atoi(str);
    printf("%d", n + 25);
 
    return 0;
}