/* 
* @author Tiffany Taghvaiee 
* @date February 2, 2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
//#include <sys/wait.h>
#include <unistd.h>   

int main(int argc, char *argv[]) {   
int n = atoi(argv[1]); 

//converts command line argument from string to an intenger   
if(fork() == 0) { //fork to create child processes           
printf("%d ", n); //print Collatz sequence in child process       

while(n != 1) {           
n = n%2 ? (3*n+1) : n/2;           
printf("%d ", n);       
}       
printf("\n");   
}   
return 0;
}
