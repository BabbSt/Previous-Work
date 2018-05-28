/*
 * This is the file in which you'll write a function to reverse a linked list.
 * Make sure to add your name and @oregonstate.edu email address below:
 *
 * Name:Stephanie Babb
 * Email:babbst@oregonstate.edu
 */

#include <stdio.h>

#include "list_reverse.h"

/*
 * In this function, you will be passed the head of a singly-linked list, and
 * you should reverse the linked list and return the new head.  The reversal
 * must be done in place, and you may not allocate any new memory in this
 * function.
 *
 * Params:
 *   head - the head of a singly-linked list to be reversed
 *
 * Return:
 *   Should return the new head of the reversed list.  If head is NULL, this
 *   function should return NULL.
 */
struct link* list_reverse(struct link* head) {
	struct link* curr=head;
	struct link* curr2;
	int i=0;
	while(curr!=NULL&&curr->next!=NULL){
		curr=curr->next;
		i++;
	}
	for(int j=0;j<i;j++){
		curr=head;
		curr2=head;
		for(int k=i;k>j;k--){
			curr2=curr2->next;
		}
		head=head->next;
		curr->next=curr2->next;
		curr2->next=curr;
	}
   return head;
}
