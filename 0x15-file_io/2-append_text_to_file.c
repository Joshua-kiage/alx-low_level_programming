#include "main.h"
#include <string.h>

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;

	if (filename == NULL)
	{
		return (-1);
	}

	file = fopen(filename, "a");

	if (file == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		size_t len = strlen(text_content);

		fwrite(text_content, sizeof(char), len, file);
	}
	fclose(file);
	return (1);
}
