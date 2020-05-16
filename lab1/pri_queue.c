/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include  <stdlib.h>
#include  <stdio.h>
#include <stdbool.h>
#include  "pri_queque.h"
/** 
@file  pri_queue.c  */
static  Node_ptr_t  head  =  NULL; 
/**
*   Insert  a  Node  into  a  priority  queue.
*
@param  priority
*
@param  data
*
@author  Syed Yousuf
*/
void  PQ_Insert(int  priority,   char  *  data) 
{
    // Create a new node.
    Node_t*temp = (Node_t*)malloc(sizeof(struct node));
    
    // Set the values of the specified priority to this node.
    temp -> priority = priority;
    temp -> data = data;
    temp ->next = NULL;
    
    // Check if there the initial node node 
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        Node_t*counter = (Node_t*)malloc(sizeof(struct node));
        
        counter = head;
        
        // Iterate through the linked list.
        while(counter->next !=NULL)
        {
            counter = counter->next;
        }
        
        // Set the value 
        counter->next = temp;
    }
    
}

/**
*  Delete  and return the node with the  highest  priority.
* 
@return The highest priority Node.
*/
Node_ptr_t  PQ_delete()  
{
    //Local Variables
    int highestPriority = 0;
    
    Node_t*counter = (Node_t*)malloc(sizeof(struct node));
    
    counter = head;
    
    // Iterate through the linked list
    do
    {
        // Is this the highest priority?
        if(counter->priority > highestPriority)
        {
            highestPriority = counter->priority;
        }
        
        // Cycle to the next node
        counter = counter->next;
    }
    while(counter!= NULL);
    
    // Now find this highest priority queuqe and delete it
    counter = head;
    
    // Iterate through the linked list
    do
    {
        // Is this the highest priority?
        if(counter->priority == highestPriority)
        {
            // Delete this node if it is the head node.
            // This is a head node only situation.
            
            // First check if it is a head or not.
            if(counter == head)
            {
                
                head = counter->next;
                return counter;
            }
            
        }
        else
        if(counter->next->priority == highestPriority)
        {
            
            // Remove the next node by changing the linked of this node and skipping it.
            Node_t*temp = (Node_t*)malloc(sizeof(struct node));
            temp = counter->next;
            counter->next = counter->next->next;
           
            
            // return the next node.
            return temp;
        }
        else
        {
            // Cycle to the next node
            counter = counter->next;
        }
        
    }
    while(counter!= NULL);
    
    
    
    return 
    NULL;
}

/**
*  Do NOT  modify  this  function.
* 
@return  A  pointer  to  the  head  of  the  list. 
(NULL
if list  is  empty.)
*/
Node_ptr_t PQ_get_head()
{
    return  head;
}

/**
*  Do NOT  modify  this  function.
* 
@return  the  number  of  items   in  the  queue
*/
int PQ_get_size()
{
    int  size  =  0;
    for(Node_ptr_t  tmp  =  head; tmp !=  NULL;tmp  =  tmp->next,   size++);
    return   size;
}

void test()
{
    printf("\n%d", PQ_get_size());
}
