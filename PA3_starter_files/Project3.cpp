/**
 * NAME: Weijen Kuo
 * EID: wk5444
 * Spring 2025
 * Speight
 */


 #include "UTQueue.h"
 #include <assert.h>
 #include <stdbool.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 
 /*
  * ALREADY DONE FOR YOU
  * Prints the passed in queue to make it easy to visualize.
  */
 void utqueueprint(UTQueue *src) {
   printf("[");
   for (int i = 0; i < src->size - 1; i++)
     printf("%d, ", src->data[i]);
   printf("%d]\n", src->data[src->size - 1]);
 }
 
 
 /*
  * Allocate a UTQueue on the heap.
  * The size of the input array is n.
  * Initialize the queue correctly by copying src
  * Return a pointer to the newly created UTQueue.
  */
 UTQueue *utqueuedup(const int *src, int n) {
   UTQueue* create = (UTQueue*)malloc(sizeof(UTQueue));
   if(create == NULL){
     printf("memory allocation failed");
   }
   int* newdata = (int*) malloc(n*sizeof(int));
   for(int i=0; i<n; i++){
     newdata[i] = src[i];
   }
   create->data = newdata;
   create-> size = n;
   return create;
 }
 
 
 /*
  * Free all memory associated with the given UTQueue.
  */
 void utqueuefree(UTQueue *self) {
   free(self->data);
   free(self);
 }
 /*
  * Push (enqueue) an integer "value" into the queue.
  */
 UTQueue *utqueuepush(UTQueue *src, int value) {
   src->size += 1;
   int* newdata = (int*) realloc((src->data), src->size*sizeof(int)); //realloc copies old data and frees new
   if(src->data == NULL){
     printf("memory allocation failed");
     return src;
   }
   src->data = newdata;
   src->data[src->size-1] = value;
   return src; }
 
 
 /*
  * Pop (dequeue) an element from the queue
  * should fail an assertion if the queue is empty
  */
 int utqueuepop(UTQueue *src) {
   assert(src->size > 0); // change false to make this assertion fail only if src has 0
                  // elements.    
   int value = src->data[0];
   src->size = src->size-1;
   int* newdata = (int*) malloc(src->size*sizeof(int));
   for(int i=0; i<src->size; i++){
     newdata[i] = src->data[i+1];
   }
   free (src->data);
   src->data = newdata;
   return value;
 }
 
 
 /*
  * Reverses the queue in src.
  */
 UTQueue *utqueuerev(UTQueue *src) {
   int j = (src->size)-1;
   for(int i=0; i<j; i++){
     int temp = src->data[i];
     src->data[i] = src->data[j];
     src->data[j] = temp;
     j--;
   }
   return src; }
 
 
 /*
  * combines the elements of UTQueues dst and src INTO dst.
  * src should be deleted after the combination
  */
 UTQueue *utqueuecombine(UTQueue *dst, UTQueue *src) {
   assert(dst->data != NULL);
   int oldsize = dst->size;
   dst->size += src->size;
   int* newdata = (int*) realloc((dst->data), dst->size * sizeof(int));// ERROR
   if(newdata == NULL){
     printf("memory allocation failed");
     return dst;
   }
   for(int i=oldsize; i<dst->size; i++){
     newdata[i] = src->data[i-oldsize];
   }
   dst->data = newdata;
   utqueuefree(src);
   return dst; }
 
 
 /*
  * Swap the two queues.
  * q1 should "have" the contents of q2 and vice verse.
  * There is more than one way to do this
  */
 void utqueueswap(UTQueue *q1, UTQueue *q2) {
   int tempsize = q1->size;
   q1->size = q2->size;
   q2->size = tempsize;
 
 
   int* tempdata = q1->data;
   q1->data = q2->data;
   q2->data = tempdata;
 }
 
 
 /*
  * Copy values from src array into dst.
  * Assume dst is a valid UTQueue.
  * src is an array of numbers.
  * Do not allocate any additional storage: only copy as many numbers
  * as will actually fit into the current UTQueue dst.
  * If all of src can fit into dst, leave the remaining ints in dst.
  * return the pointer to dst with the changes.
  */
 UTQueue *utqueuecpy(UTQueue *dst, const int *src, int n) {
   for(int i=0; i<n; i++){
     if(i>= dst->size){
       return dst;
     }
     dst->data[i] = src[i];
   }
    
     return dst; }
 
 
 
 