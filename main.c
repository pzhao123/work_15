#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char ** parse_args( char * line ) {
    char ** values = calloc(5, sizeof(char *));
    char * curr = line;
    char * arg;
    int i = 0;
    while (curr) {
        arg = strsep(&curr, " ");
        values[i] = arg;
        i++;
    }
    return values;
}

int main( int argc, char *argv[] ) {
    char input[200];
    printf("Command Line Invocation: ");
    fgets(input, sizeof(input), stdin);
    *(strchr(input, '\n')) = 0;
    char ** args = parse_args(input);
    //printf("%s %s\n", args[0], args[1]);
    execvp(args[0], args);
    return 0;
}