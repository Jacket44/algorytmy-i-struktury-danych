/*
*  Simple doubly circular linked list implementation, with merge function
*  (c) 2021 Mateusz Trzeciak
*/
#include<stdio.h>  
#include<stdlib.h>  
struct node {  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
  
void insertion(struct node *head, int item) { 
    struct node *ptr,*temp;  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL) {  
        printf("\nOVERFLOW");  
    }  
    else {   
        ptr->data=item;

        if(head==NULL) {  
            head = ptr;  
            ptr -> next = head;   
            ptr -> prev = head;   
        }  
        else {  
            temp = head;   
            while(temp -> next != head) {  
                temp = temp -> next;   
            }  
            temp -> next = ptr;  
            ptr -> prev = temp;  
            head -> prev = ptr;  
            ptr -> next = head;  
            head = ptr;  
        }
    }  
         
}  
      
void display(struct node *head) {  
    struct node *ptr;
    int count = 0;  
    ptr=head;  
    if(head == NULL) {  
        printf("\nnothing to print");  
    }     
    else {  
        printf("\n printing values ... \n");  
              
        while(ptr -> next != head) {  
              printf("Element %d - %d\n", count, ptr -> data);
              count++;  
            ptr = ptr -> next;  
        }

        printf("Element %d - %d\n", count, ptr -> data);  
    }  
}  
      
void search(struct node *head, int item) {  
    struct node *ptr; 
    int count = 0; 
    int i=0;
    int flag=1;  
    ptr = head;   
    if(ptr == NULL) {  
        printf("\nEmpty List\n");  
    }  
    else {   
        if(head ->data == item) {  
            printf("item found at location %d",i+1);  
            flag=0;  
        }  
        else {  
            while (ptr->next != head) {  
                if(ptr->data == item) {  
                    printf("item found at location %d ",i+1);  
                    flag=0;  
                    break;  
                }   
                else {  
                    flag=1;  
                }  
                i++;  
                ptr = ptr -> next;  
            }  
        }  
        if(flag != 0) {  
                printf("Item not found\n");  
        }  
    }     
}

void insert_random_elements(struct node *head, int count) {
    int random_num = 0;
    while(count) {
        random_num = (rand() % 1000);
        insertion(head, random_num);
        count--;
    }
}

int count_travelsal_length(struct node* head, int index) {
    int count = 0;
    struct node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
            count++;

        }
    return count;
}

void merge(struct node* head_a, struct node* head_b) {
    struct node *temp;
    temp = head_a;
    while(temp -> next != head_a) {  
        temp = temp -> next;   
    }  
    temp -> next = head_b;  
    head_b -> prev = temp;
    temp = head_b;

    while(temp -> next != head_b) {  
        temp = temp -> next;   
    }
    temp -> next = head_a;

         
}


int main() {

    struct node *first;
    first = (struct node*)malloc(sizeof(struct node)); 
    first->data = 1; 
    first->next = first;
    first->prev = first;

    struct node *second;
    second = (struct node*)malloc(sizeof(struct node)); 
    second->data = 2; 
    second->next = second;
    second->prev = second;

    insert_random_elements(first, 9);
    insert_random_elements(second, 9);
    display(first);
    display(second);
    merge(first, second);
    puts("Lists merged: \n");
    display(first);

    insert_random_elements(first, 980);

    int travelsal1 = count_travelsal_length(first, 50);
    int travelsal2 = count_travelsal_length(first, 444);
    int travelsal3 = count_travelsal_length(first, 820);
    int random = rand() % 1000;
    int travelsal_random = count_travelsal_length(first, random);

    printf("\n ------- \n");
    printf("Travelsal 1 to element 50 - %d \n", travelsal1);
    printf("Travelsal 2 to element 444 - %d \n", travelsal2);
    printf("Travelsal 3 to element 820 - %d \n", travelsal3);
    printf("Travelsal to element %d - %d \n",random, travelsal_random);

    return 0;
}