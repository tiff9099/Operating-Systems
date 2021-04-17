/** 
* A multithreaded program that has a child thread and populates a list using the Col latz sequence. 
* When the child thread terminates, the parent outputs Collatz by traversing the linked list. 
* 
* @author Tiffany Taghvaiee 
* @date March 24, 2021  
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* Node structure*/
struct element{   
int sum;   
struct element *next;
}
*head = NULL;
void *runner(void *param); 

/* thread */
void insert(struct element **head, int val); 

/*add value to linked list*/
void printlist(struct element *node); 

/*print linked list*/
int main(int argc, char *argv[]){
pthread_t tid; 

/* the thread identifier */
pthread_attr_t attr; 

/* set of attributes for the thread */
if (argc != 2) {
fprintf(stderr,"usage: a.out <integer value>\n");

/*exit(1);*/
return -1;
}

if (atoi(argv[1]) < 0) {
fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));

/*exit(1);*/
return -1;
}

/* get the default attributes */
pthread_attr_init(&attr);

/* create the thread */
pthread_create(&tid, &attr, runner, argv[1]);

/* now wait for the thread to exit */
pthread_join(tid,NULL);

/*output linked list*/
printlist(head);
}

/**  * Collatz sequence of a # */
void *runner(void *param) {
int upper = atoi(param);

while (upper != 1) {
insert(&head, upper);

if (upper%2 != 0) {
upper = 3*upper+1;
}

else upper = upper /2; 
}

insert(&head, upper);
pthread_exit(0);
}

void insert(struct element **head, int val) {
struct element *new = (struct element *)malloc(sizeof(struct element));

/*create new node and allocate memory */
struct element *last = *head; 

/* copy head element address */
new->sum = val; 

/* move val to new element */
new->next = NULL; 

/* set new element to null */
if (*head == NULL) {
*head = new;return; 
}

while (last->next != NULL) 

/* traverse until last element */
last = last->next; last->next = new; 
return;
}

void printlist(struct element *node) {
while (node != NULL) { 

/* traverse until empty */
printf(" %d", node->sum); 

/* print sum of linked list */
node = node->next; 

/* move to next node */
}
printf("\n"); 
}
