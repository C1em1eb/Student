#include "get_next_line.h"

/* int main(void)
{
	int		fd;
	fd = open("text", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
} */

char	*get_next_line(int fd)
{
	char	*buffer;
	char 	*temp;
	static char 	*stash;
	char 	*line;
	char 	*pdollar;
	int		idollar;
	size_t 	bytes_read;

	buffer = NULL;
	buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	stash = malloc(sizeof(char)* (BUFFER_SIZE + 1) * 100);
	if (stash == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (buffer);
		free (stash);
		return (NULL);
	}
	stash[0] = '\0';
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strdup(buffer);
		stash = ft_strjoin(stash, temp);
		free (temp);
		pdollar = ft_strchr(stash, '\n');
		if (pdollar != NULL)
		{
			idollar = pdollar - stash;
			line = ft_substr(stash, 0, idollar + 1);
			stash = ft_substr(stash, idollar + 1, BUFFER_SIZE + 50);
			return (line);
			free(line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 1)
	{
		free (buffer);
		free (stash);
		return (NULL);
	}
	free (buffer);
	return (NULL);
}
