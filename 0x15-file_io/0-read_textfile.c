#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read a text file and print its contents to STDOUT.
 * @file_path: The path to the text file to be read.
 * @num_chars: The number of characters to read and print.
 * Return: The actual number of bytes read and printed on success,
 *         0 when the function fails or file_path is NULL.
 */
ssize_t read_textfile(const char *file_path, size_t num_chars)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_read;
    ssize_t bytes_written;

    file_descriptor = open(file_path, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * num_chars);
    if (!buffer)
    {
        close(file_descriptor);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, num_chars);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);
    
    return (bytes_written);
}
