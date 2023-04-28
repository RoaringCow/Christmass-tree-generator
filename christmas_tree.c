#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* print_line(int spaces, int stars){
    char* string = malloc(spaces + stars + 1); // add 1 for the null terminator
    string[0] = '\0'; // initialize the string with a null terminator
    for(int i = 0; i < spaces; i++){
        strncat(string, " ", spaces+1); // ensure that the string is long enough
    }
    for(int i = 0; i < stars; i++){
        strncat(string, "*", stars+1); // ensure that the string is long enough
    }
    return string;
}


int main(int argc, char *argv[]) {

    // Check if the required number of arguments has been provided
    if (argc < 4) {
        printf("Insufficient arguments. Inputs are (height, root_height, root_width)\n");
        return 1;
    }

    // Convert command-line arguments to integers
    int height = atoi(argv[1]);
    int root_height = atoi(argv[2]);
    int root_width = atoi(argv[3]);

    // Check if the values are valid
    if (height <= 0) {
        printf("Invalid height value\n");
        return 1;
    } else if (root_height <= 0) {
        printf("Invalid root height value\n");
        return 1;
    } else if (root_width <= 0) {
        printf("Invalid root width value\n");
        return 1;
    }
    if (root_width % 3 != 0 && root_width != 1) {
        printf("The root width is not appropriate! Must be divisible by 3 or be 1.\n");
        return 1;
    } else if (height * 2 - 1 <= root_width) {
        printf("The root can't be thicker than the body itself!, body width: %i, root width: %i\n", height * 2 - 1, root_width);
        return 1;
    }

    for(int i = 0; i < height; i++){
        char* line = print_line(height - i - 1, i * 2 + 1);
        printf("%s\n", line);
        free(line);
    }
    int space = height - 1 - ((root_width - 1) / 2);
    for(int i = 0; i < root_height; i++){
        char* line = print_line(space, root_width);
        printf("%s\n", line);
        free(line);
    }

    return 0;
}