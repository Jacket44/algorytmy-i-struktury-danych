/*
*  Simple Linked list implementation, with merge function
*  (c) 2021 Mateusz Trzeciak
*/

#include<stdio.h> 
#include<stdlib.h> 

struct Node { 
    int data; 
    struct Node *next; 
}; 

/*
* Displays list values in terminal, one at the time.
*/
void display(struct Node *node) { 
    while (node != NULL) { 
        printf("%d\n", node->data); 
        node = node->next; 
    } 
}

/*
* Takes an existing node and creates a new one at the end.
*/
void insert_at_end(struct Node* head, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = head;

  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

/*
* Takes existing node and appends it with *count* random elements.
*/
void create_random_nodes(struct Node* head, int count) {
    while(count) {
        int random_num = (rand() % 100);
        insert_at_end(head, random_num);
        count--;
    }

}

/*
* For given list head and index, counts how many "jumps" it take to get to element under given index.
*/
int count_travelsal_length(struct Node* head, int index) {
    int count = 0;
    struct Node* temp = head;
        for (int i = 0; i < index; i++){
            temp = temp->next;
            count++;

        }
    return count;
}

/*
* For two given list heads, merges them into one.
*/

void merge(struct Node* head_a, struct Node* head_b) {
    if (head_a->next == NULL)
        head_a->next = head_b;
    else
        merge(head_a->next, head_b);
}

/*
* Robert C. Martin please don't kill me.
*/
int main() {
struct Node *first;
first = (struct Node*)malloc(sizeof(struct Node)); 
first->data = 1; 
first->next = NULL;

struct Node *second; 
second = (struct Node*)malloc(sizeof(struct Node)); 
second->data = 2; 
second->next = NULL; 

struct Node *third;
third = (struct Node*)malloc(sizeof(struct Node)); 
third->data = 3; 
third->next = NULL; 

create_random_nodes(first, 1000);
create_random_nodes(second, 1000);
create_random_nodes(third, 1000);

puts("Counting travelsal steps to get to 420th element of three, random arrays.");

int count_first = count_travelsal_length(first, 420);
int count_second = count_travelsal_length(second, 420);
int count_third = count_travelsal_length(third, 420);

printf("%d == %d == %d \n", count_first, count_second, count_third);
puts("If numbers above are equal, it took the same amount of steps to reach 420 element of three random arrays.");
    
puts("---");
puts("Generating three random indexes and counting travelsal steps to reach them.");

int rand_num = (rand() % 1000);
count_first = count_travelsal_length(first, rand_num);
rand_num = (rand() % 1000);
count_second = count_travelsal_length(first, rand_num);
rand_num = (rand() % 1000);
count_third = count_travelsal_length(first, rand_num);

printf("%d -- %d -- %d \n", count_first, count_second, count_third);

// Merge test 
struct Node *list_a;
list_a = (struct Node*)malloc(sizeof(struct Node)); 
list_a->data = 1; 
list_a->next = NULL;

struct Node *list_b; 
list_b = (struct Node*)malloc(sizeof(struct Node)); 
list_b->data = 2; 
list_b->next = NULL;

create_random_nodes(list_a, 5);
create_random_nodes(list_b, 5);

puts("---------");
puts("Merge test");
puts("list_a");
display(list_a);
puts("list_b");
display(list_b);
puts("Lists merged:");
merge(list_a, list_b);
display(list_a);

return 0; 
}