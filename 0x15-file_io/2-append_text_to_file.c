#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a target file.
 * @target_filename: A pointer to the name of the target file.
 * @text_to_append: The string to add to the end of the target file.
 *
 * Return: If the function fails or target_filename is NULL - -1.
 *         If the target file does not exist or lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *target_filename, char *text_to_append)
{
    int file_descriptor, write_result, text_length = 0;

    if (target_filename == NULL)
        return (-1);

    if (text_to_append != NULL)
    {
        for (text_length = 0; text_to_append[text_length];)
            text_length++;
    }

    file_descriptor = open(target_filename, O_WRONLY | O_APPEND);
    write_result = write(file_descriptor, text_to_append, text_length);

    if (file_descriptor == -1 || write_result == -1)
        return (-1);

    close(file_descriptor);

    return (1);
}
