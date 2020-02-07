/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: smyousuf
 *
 * Created on February 3, 2020, 3:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <fcntl.h>
/*
 * 
 */
int main(int argc, char** argv) {

    int fd = open("temp.txt", O_WRONLY | O_APPEND);
    
    if(dup2(fd, 1) < 0)
    {
        //redirect the std output to the file
        close(fd);
        return 1;
    }
    
    printf("I will print in this file. \n");
    
    return (EXIT_SUCCESS);
}

