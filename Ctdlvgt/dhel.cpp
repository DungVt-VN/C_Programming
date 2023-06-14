
#include <stdio.h>
#include <stdlib.h>
int main(){
char c;
FILE *f;
if ((f = fopen("program.txt", "r")) == NULL)
{
printf("Error! opening file");
return 0;
}
while ((c=fgetc(f)) != EOF){
if('a' <= c && c <= 'x'){
c = c+2;
}
if(c == 'y'){
c = 'a';
}
if(c == 'z'){
c = 'b';
}
if('A' <= c && c <= 'X'){
c = c+2;
}
if(c == 'Y'){
c = 'A';
}
if(c == 'Z'){
c = 'B';
}
printf("%c",c);
}
return 0;
}
