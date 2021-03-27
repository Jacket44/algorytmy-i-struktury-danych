/*
*  Simple LIFO implementation 
*  (c) 2021 Mateusz Trzeciak
*
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *temp;


/*
*  Creates pointer node. If temp is null, copies pointer to temp node. If not,
*  links created pointer node with temp beforehand.
*/
void push (int pushed_data) {
    struct Node *pointer = (struct Node*)malloc(sizeof(struct Node));

    if(pointer == NULL) {
        printf("Stack overflow \n");
    }
    else {
        if(temp == NULL) {
            pointer -> data = pushed_data;
            printf("Pushed %d onto stack, first element \n", pushed_data);
            pointer -> next = NULL;
            temp = pointer;
        }
        else {
            pointer -> data = pushed_data;
            printf("Pushed %d onto stack \n", pushed_data);
            pointer -> next = temp;
            temp = pointer;
        }
    }
}

/*
*   Deletes first element on stack, if it's not empty. 
*   Takes data from temp node, then overwrites it with the notde that it is liknked with.
*/
void pop() {
    int item;
    struct Node *pointer;
    if (temp == NULL) {
        printf("Stack Underflow\n");
    }
    else {
        item = temp -> data;
        pointer = temp;
        temp = temp -> next;
        free(pointer);
        printf("The deleted item is %d\n",item);
    }
}

/*
*   Displays elements of the stack, from top to bottom obviously.
*   
*/
void display() {
    struct Node *pointer;
    pointer = temp;
    if(pointer == NULL) {
        printf("Stack underflow\n");
    }
    else {
        printf("The elements of the stack are:\n");
        while(pointer!= NULL) {
            printf("%d\n",pointer -> data);
            pointer = pointer -> next;
        }
    }
}

/*
* Inserts into stack random numbers, from 0 to 99.
* 
*/
void push_random_numbers(int count) {
    while(count) {
        int random_num = (rand() % 100);
        push(random_num);
        count--;
    }
}

int main() {
    puts("Dzień dobry!");
    push_random_numbers(10);
    puts("-------------------");
    display();
    return 0;
}