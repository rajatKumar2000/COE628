/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: smyousuf
 *
 * Created on January 27, 2020, 3:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    // Local Variable list
    char command[100];
    char executingCommand[100];
    int indexNumber = 0;
    bool ampersandFlag; // Flag is set if
    
    char *argPointer[100];
    int argPointerIndexNumber = 0;
    int argPointerNumber = 0; // Stores the total number of argument pointers
    
    
    printf("Your command> \n");
    argPointer[argPointerIndexNumber] = &command[0];
    argPointerNumber++;
    
    while((command[indexNumber] = getchar()) != '\n')
    {
        // Check to see if this character location is an empty space
        if(command[indexNumber] == ' ')
       {
          // make this character a null character. 
          command[indexNumber] = NULL; 
          
          // Set the next character as the pointer address.
          argPointerIndexNumber++;
          argPointerNumber++; 
          argPointer[argPointerIndexNumber] = &command[indexNumber + 1];
       }
        
        // Increment to the next position of the array of characters.
        indexNumber++;
        
    }
    
    // Check the last character to see if it is an ampersand
    if(command[indexNumber - 1] == '&' && command[indexNumber - 2] != ' ')
    {
        ampersandFlag  = true;
    }
    
    // Create a new processes.
    pid_t cpid;
    
    if(fork()==0)
    {
        printf("Child process created\n");


        // Execute the commands.
        indexNumber = 0;
        
        argPointerIndexNumber = 0;
        for(argPointerIndexNumber = 0; argPointerIndexNumber < argPointerNumber;  argPointerIndexNumber++)
        {
            indexNumber = 0;
            
            while(command[indexNumber] != NULL)
            {
                argPointer[argPointerIndexNumber] = argPointer[argPointerIndexNumber] + indexNumber;
                executingCommand[indexNumber] = *argPointer[argPointerIndexNumber];
                //printf("%c\n", executingCommand[indexNumber]);
                indexNumber++;
            }
            
            system(executingCommand);
        }
        
        
        //printf("%s\n", executingCommand);
       //printf("%d\n", argPointerNumber);
        exit(0);
    }
    else
    {
        printf("Parent process is waiting \n");
        
        // Wait for the child process to terminate unless the line ended with an ampersand character.
        if(ampersandFlag == false)
        {
            cpid = wait(NULL);
        }
       
        printf("Parent process ends.\n");
    }
    
    return (EXIT_SUCCESS);
}

