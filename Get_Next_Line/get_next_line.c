#include "get_next_line.h"

int main(void)
{
	int		fd;

	fd = open("text", O_RDONLY);
	ft_printf("%s\n", get_next_line(fd));
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = NULL;
	buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE - 1);
	buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}
