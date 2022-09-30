#include <stdio.h>
#include <stdlib.h>
#include "../libcompact.h"

// (a)
typedef struct Node {
	U32 val;
	struct Node* next;
} Node;

// (b)
typedef struct {
	Node* first;
	U16 size;
} LinkedList;

// (c)
Node* get_index(LinkedList* ll, U16 index) {
	Node* node = ll->first;
	DO(index, node=node->next); // macro for a for loop where i is from 0 to index
	return node;
}

void add_val(LinkedList* ll, U32 val) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->val = val;
	get_index(ll,ll->size - 1)->next = node;
	ll->size++;
}

// (d)
LinkedList* repeat(U32 val, U16 size) {
	LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
	ll->size = size;
	Node* last = NULL;
	for(U16 i = 0; i < size; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = val;
		if(last == NULL) {
			ll->first = node;
		} else {
			last->next = node;
		}
		last = node;
	}
	return ll;
}

// (e)
U16 remove_insts(LinkedList* ll, U32 val) {
	Node* last = NULL;
	Node* cur = ll->first;
	U16 removed = 0;
	while(last == NULL || cur != NULL) {
		if(cur->val == val) {
			if(last == NULL) {
				if(cur->next != NULL) ll->first = cur->next;
				else ll->first = NULL;
			} else {
				last->next = cur->next;
			}
			free(cur);
			ll->size--;
			removed++;
		} else last = cur;
		if(last == NULL) {
			cur = ll->first;
		} else {
			cur = last->next;
		}
	}
	return removed;
}

// (f)
void free_ll(LinkedList* ll) {
	Node* node = ll->first;
	while(node != NULL) {
		Node* temp = node;
		node = node->next;
		free(temp);
	}
	free(ll);
}

// Test

V print_ll(LinkedList* ll) {
	P("{");
	Node* node = ll->first;
	while(node != NULL) {
		P("%d",node->val);
		if(node->next != NULL) {
			P(",");
		}
		node = node->next;
	}
	P("} (s=%d)\n", ll->size);
}


int main() {
	LinkedList* ll = repeat(5,7);
	print_ll(ll);
	ll->first->next->val = 2;
	print_ll(ll);
	Pd(get_index(ll, 1)->val);
	add_val(ll, 6);
	print_ll(ll);
	remove_insts(ll, 5);
	print_ll(ll);
	free_ll(ll);
}
