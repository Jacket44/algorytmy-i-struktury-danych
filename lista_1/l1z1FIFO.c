/*
*  Simple FIFO implementation 
*   (c) 2021 Mateusz Trzeciak
*/

#include <stdio.h>
#include <stdlib.h>

// Basic linked list.
struct Node
{
    int data;
    struct Node *link;    
};

struct Node *front, *rear;


/*
* Creates temporary Node with NULL link.
* Then, if queue is empty, makes temp both rear and front element.
* Else, links current rear element with temp and makes temp a current rear element.
*/
void insert(int inserted_data) {
    struct Node *temp;

    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = inserted_data;
    printf("Inserted number %d into queue. \n", inserted_data);
    temp->link = NULL;
    if (rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->link = temp;
        rear = temp;
    }
}

/*
* Using temp Node, passes front element of the queue to temp and prints it.
* Then, makes temp and makes it rear, linked element.
*/
void display() {
    struct Node *temp;
    temp = front;
    int count = 0;
    if (front == NULL) {
        puts("Queue is empty.");
    }
    else {
        while (temp) {
        printf("%d\n", temp->data);
        temp = temp->link;
        count++;
        }
    }
    printf("Displayed %d elements of queue.", count); 
}

/*
* Inserts into queue random numbers, from 0 to 99.
* 
*/
void insert_random_numbers(int count) {
    while(count) {
        int random_num = (rand() % 100);
        insert(random_num);
        count--;
    }
}

int main() {
    puts("Dzień dobry!");
    insert_random_numbers(10);
    puts("-------------------");
    display();
    return 0;
}