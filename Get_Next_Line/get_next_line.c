#include "get_next_line.h"

int main(void)
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
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char 	*temp;
	static char 	*stash;
	char 	*line;
	char 	*p_separator;
	int		len_to_separator;
	size_t 	bytes_read;

	buffer = NULL;
	stash = NULL;
	buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	stash = malloc(sizeof(char)* (BUFFER_SIZE + 1));
	if (stash == NULL)
		return (NULL);
	temp = malloc(sizeof(char)* (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		free (stash);
		free (temp);
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
		p_separator = ft_strchr(stash, '\n');
		if (p_separator != NULL)
		{
			len_to_separator = p_separator - stash + 1;
			line = ft_substr(stash, 0, len_to_separator + 1);
			temp = ft_strdup(stash);
			free (stash);
			stash = temp;
			return (line);
			free(line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 1)
		free (stash);

	free (buffer);
	return (NULL);
}
