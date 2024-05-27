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
	char		*buffer;
	char		*temp;
	static char	*stash;
	char		*line;
	char		*p_separator;
	int			len_to_separator;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = malloc(sizeof(char)* (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = NULL;
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free (buffer);
		buffer = NULL;
		free (stash);
		stash = NULL;
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (temp == NULL)
		{
			free (buffer);
			buffer = NULL;
			free (stash);
			stash = NULL;
			return (NULL);
		}
		free (stash);
		stash = temp;
		p_separator = ft_strchr(stash, '\n');
		if (p_separator != NULL)
		{
			len_to_separator =  p_separator - stash + 1;
			line = ft_substr(stash, 0, len_to_separator);
			if (line == NULL)
			{
				free (buffer);
				buffer = NULL;
				free (stash);
				stash = NULL;
				return (NULL);
			}
			temp = ft_strdup(stash + len_to_separator);
			if (temp == NULL)
			{
				free (buffer);
				buffer = NULL;
				free (line);
				line = NULL;
				free (stash);
				stash = NULL;
				return (NULL);
			}
			free (stash);
			stash = temp;
			free (buffer);
			buffer = NULL;
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && stash[0] != '\0')
	{
		line = ft_strdup(stash);
		free (stash);
		stash = NULL;
		free (buffer);
		buffer = NULL;
		return (line);
	}
	free (buffer);
	if (stash)
	{
		free (stash);
		stash = NULL;
	}
	return (NULL);
}
