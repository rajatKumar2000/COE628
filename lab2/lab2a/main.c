#include <stdio.h>  //printf, fprintf
#include <stdlib.h> //EXIT_SUCCESS
#include <string.h> //strlen, strcmp
#define TOO_MANY_ARGS 2
#define TOO_FEW_ARGS 1

int main(int argc, char* argv[]) {
    //Default values:
    int exit_code = EXIT_SUCCESS;
    char * greeting = "Hello";
    char * person = "UNKNOWN";
    //Add code to change the exit_code depending on argc
    if(argc == 2)
    {
        exit_code = 0;
    }
    else
    if(argc > 2)
    {
        exit_code = 2;
    }
    else
    if(argc == 1)    
    {
        exit_code = 1;
    }
    
    //Add code to change 'person' if one is given on command line
    if(argv[2] != NULL)
    {
        person = argv[2];
    }
    
    int len = strlen(argv[0]);
    char * last3 = argv[0] + len - 3; //last3 points to last 3 chars
    //fprintf(stderr, "%s\n", argv[1]);
    //fprintf(stderr, "%s\n", last3);
    
    //Add code to change 'greeting' if last 3 chars of command are 'bye'
    if(strcmp(argv[1], "bye") == 0)
    {
        greeting = "bye";
    }
    
   printf("%s %s\n", greeting, person);
   
   // now check for the and argument which must be the third argument
   if(strcmp(argv[3],"&&") == 0)
   {
       // Check for name.
       if(argv[5] != NULL)
       {
            person = argv[5];
       }
    
       //Add code to change 'greeting' if last 3 chars of command are 'bye'
        if(strcmp(argv[4], "bye") == 0)
        {
            greeting = "bye";
        }
       
       printf("%s %s\n", greeting, person);
   }
    
    fprintf(stderr, "exit_code: %d\n", exit_code);
    
    return exit_code; //Could also say exit(exit_code)
}