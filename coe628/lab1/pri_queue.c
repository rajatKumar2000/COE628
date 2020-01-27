#include <stdlib.h>
#include <stdio.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author Syed Yousuf
 */
void PQ_insert(int priority, char * data) {
    
    Node_t*temp = (Node_t*)malloc(sizeof(struct node));
    
    // Assign proper values to this new node,
    temp ->data = data;
    temp ->priority = priority;
    temp->next = NULL;
    
    
    // Now add this node to the queue.
    // Check the head to see if it exists or not.
    if(head == NULL)
    {
        head = temp;
    }
    else
    {

        Node_t*counter = (Node_t*)malloc(sizeof(struct node));

        counter = head;
        
        
        do
        {
            if(temp->priority >= counter->priority && counter == head)
            {
                // Adding to the head.
                temp->next = counter;
                head = temp;
                
                return;
            }
            else
            if(counter->next == NULL)
            {
                // Value is added at the end.
                counter->next = temp;
                
                return;
            }
            else
            if(temp->priority >= counter->next->priority)
            {
                // Value is between the previous value and the next value
                temp->next = counter->next;
                counter->next = temp;
                
                return;
            }
            
            counter = counter->next;
            
            
        }while(counter != NULL);
        
    }
    
    
    
}
/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
    Node_t*temp = (Node_t*)malloc(sizeof(struct node));
    head = temp;
    head = head->next;
    return temp;
    

}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++);
    return size;
}


