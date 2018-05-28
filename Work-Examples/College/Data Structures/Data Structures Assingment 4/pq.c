/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Stephanie Babb
 * Email: babbst@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "pq.h"
#include "dynarray.h"

struct node{
	void* val;
	int pri;
};
/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */
struct pq{
	struct dynarray* dyn;
};


/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */
struct pq* pq_create() {
	struct pq* p= malloc(sizeof(struct pq));
	p->dyn=dynarray_create();
   return p;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */
void pq_free(struct pq* pq) {
	dynarray_free(pq->dyn);
	free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
int pq_isempty(struct pq* pq) {
   	if(dynarray_size(pq->dyn)!=0){
		return 0;
	}
  	return 1;
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */
void pq_insert(struct pq* pq, void* value, int priority) {
	assert(pq);
	struct node* temp=malloc(sizeof(struct node));
	temp->val=value;
	temp->pri=priority;
	dynarray_insert(pq->dyn,dynarray_size(pq->dyn),temp);
	if(dynarray_size(pq->dyn)>1){
		int index=dynarray_size(pq->dyn)-1;
		struct node* par=dynarray_get(pq->dyn,(index-1)/2);
		while(par->pri>temp->pri){
		   	dynarray_set(pq->dyn, index, par);
			dynarray_set(pq->dyn, (index-1)/2, temp);	
			index=(index-1)/2;
			par=dynarray_get(pq->dyn,(index-1)/2);
		}	
	}
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_first(struct pq* pq) {
   	assert(pq->dyn);
	struct node* t=dynarray_get(pq->dyn,0);
  return t->val;
}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
int pq_first_priority(struct pq* pq) {
   	assert(pq->dyn);
	struct node* t=dynarray_get(pq->dyn,0);
  return t->pri;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
void* pq_remove_first(struct pq* pq) {
   	assert(pq->dyn);
	struct node* t=dynarray_get(pq->dyn,0);
	struct node* end=dynarray_get(pq->dyn,dynarray_size(pq->dyn)-1);
	struct node* left;
	struct node* right;
	void* val=t->val;
	free(t);
	dynarray_set(pq->dyn,0,end);
	dynarray_remove(pq->dyn,dynarray_size(pq->dyn)-1);
	if(dynarray_size(pq->dyn)>1){
		int index;
		int ind2=0;
		struct node* min;
		if(dynarray_size(pq->dyn)<3){
			min=dynarray_get(pq->dyn,1);
			index=1;
		}else{ 
			left=dynarray_get(pq->dyn,1);
	       		right=dynarray_get(pq->dyn,2);
		   	
		   	if(left->pri>right->pri){
				min=right;
				index=2;
			}else{
				min=left;
				index=1;
			}
		}
		while(min->pri<end->pri){
			dynarray_set(pq->dyn,index,end);
			dynarray_set(pq->dyn,ind2,min);
			ind2=index;
			if(dynarray_size(pq->dyn)<(2*ind2+2)){
			   	return val;
			}else if(dynarray_size(pq->dyn)<(2*ind2+3)){
				min=dynarray_get(pq->dyn,2*ind2+1);
				index=2*ind2+1;
			}else{
				left=dynarray_get(pq->dyn,2*ind2+1);
	       			right=dynarray_get(pq->dyn,2*ind2+2);

			   	if(left->pri>right->pri){
					min=right;
					index=2*ind2+2;
				}else{
					min=left;
					index=2*ind2+1;
				}
			}
		}
	}
  return val;
}
