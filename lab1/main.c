/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Syed Yousuf
 *
 * Created on January 6, 2020, 8:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pri_queque.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    Node_ptr_t  head;
    assert(PQ_get_size() == 0);
    fprintf(stderr,   "First  assert  worked!\n"); 
    PQ_Insert(40,   "first  node");
    PQ_Insert(20, "second node");
    PQ_Insert(10, "third node");
    test();
    head = PQ_delete();
    printf("\n%d",head ->priority);
    test();
    printf("\n%d", PQ_get_head()->next->priority);
    
    
    
    return (EXIT_SUCCESS);
}

