#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int create_file(const char *filename, char *text_content) {
    int file_descriptor, write_status;
    
    if (filename == NULL)
        return (-1);
    
    file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (file_descriptor == -1)
        return (-1);
    
    if (text_content != NULL) {
        write_status = write(file_descriptor, text_content, strlen(text_content));
        if (write_status == -1) {
            close(file_descriptor);
            return (-1);
        }
    }
    
    close(file_descriptor);
    return (1);
}

int main(int ac, char **av) {
    int res;

    if (ac != 3) {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }

    res = create_file(av[1], av[2]);

    if (res == -1) {
        dprintf(2, "Failed to create or write to the file.\n");
        exit(1);
    }

    printf("-> %i\n", res);
    return 0;
}
