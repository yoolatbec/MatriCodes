#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
 int value;
 struct node* next;
} node ;

int size; // the size of linked list
node* head; // the head of linkedlist

//insert the value to the right position
//if the position is not valid, return false
//if insert successfully, return true
bool insert(int position, int value);

// return the value in the given position
int get(int position);

//clear the linkedlist, remember to free the memory you allocated
void clear();

void print() {
	int i;
	for (i = 0; i < size; ++i) {
		printf("%d ", get(i));
	}
	printf("\n");
}


int main() {
	head = NULL;
	size = 0;
	int n, i, position, value;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &position, &value);
		if (insert(position, value)) {
			print();
		} else {
			printf("position is not valid\n");
		}
	}
	clear();
	return 0;
}

bool insert(int position, int value){
    if(position < 0 || position > size){
        return false;
    }
    node * new = (node * ) malloc(sizeof(node));
    new -> value = value;
    new -> next = NULL;
    if(size == 0){
        head = new;
    } else {
        if(position != 0){
            node * current = head;
            for(int count = 0; count < position - 1; count++){
                if(current -> next == 0){
                    return false;
                }
                current = current -> next;
            }
            node * next = current -> next;
            current -> next = new;
            new -> next = next;
        } else {
            new -> next = head;
            head = new;
        }
    }
    size++;
    return true;
}

void clear(){
    node * current;
    node * next;
    current = head;
    next = current -> next;
    while(current != NULL){
        free(current);
        current = next;
        next = (current == NULL) ? 0 : current -> next;
    }
}

int get(int position){
    node * current = head;
    for(int count = 0; count < position; count++){
        current = current -> next;
    }
    return current -> value;
}