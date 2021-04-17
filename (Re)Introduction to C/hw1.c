/** * A program that reads in a line of text and generates a histogram of vowels 
* (a,e,i,o,u) that occur in the text entered.  * * @author Tiffany Taghvaiee 
* @date January 26, 2021 * */

#include<stdio.h>
#include<string.h>
#define LEN 256

int isAVowel(char str);
void vowelCount(char str[]);

int isAVowel(char phrase) {
char array[]= {'a','e','i','o','u','A','E','I','O','U'};

int size = 6;for(int i = 0; i < 10; i++) {
if(phrase == array[i])return 1;
}
return 0;
}

//ensures output is case-insensitive and increase count
//for each vowel given the text entered
void vowelCount(char str[]) {
int aCount = 0,eCount = 0,iCount = 0,oCount = 0,uCount = 0,i;

for(i=0; i<strlen(str); i++) {
if(str[i]=='a' || str[i]=='A')aCount++;

else if(str[i]=='e' || str[i]=='E') {
eCount++;}else if(str[i]=='i' || str[i]=='I') {
iCount++;}else if(str[i]=='o' || str[i]=='O') {
oCount++;}else if(str[i]=='u' || str[i]=='U') {
uCount++;
}
}
printf("a: ");

for(int i = 0; i < aCount; i++) {
printf("* ");
}
printf("\ne: ");

for(int i = 0; i < eCount; i++) {
printf("* ");}printf("\ni: ");
for(int i = 0; i < iCount; i++) {
printf("* ");
}
printf("\no: ");

for(int i = 0; i < oCount; i++) {
printf("* ");
}
printf("\nu: ");

for(int i = 0; i < uCount; i++) {
printf("* ");
}
printf("\n");
}

int main () {
char str[127];
char phrase;
printf("Enter a phrase: ");
scanf("%s",str);
vowelCount(str);

for (int i = 0; i < strlen(str); i++) {
if(isAVowel(str[i]) == 0)
printf("%c", str[i]); 
}
printf("\n"); 
return 0;
}
