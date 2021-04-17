
/* This lab will involve writing a C program using the fork() system call that generates the Collatz sequence in the child process. 
 * The initial number will be provided in the command line.
 * @author Tiffany Taghvaiee 
 *@date February 2, 2021 
 */
 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {   
//converts command line argument fron string to integer   
int n = atoi(argv[1]);   

//prints Collatz sequence in child process.   
printf("%d ", n);   
while(n != 1) {       
n = n%2 ? (3*n+1) : n/2;       
printf("%d ", n);   
}   
printf("\n");   
return 0;
}
