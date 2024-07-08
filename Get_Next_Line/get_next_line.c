#include "get_next_line.h"

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);

	}
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

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		buffer = NULL;
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
		{
			free_and_null (&buffer);
			return (NULL);
		}
	}
	stash[ft_strlen(stash)] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free_and_null (&stash);
		stash = temp;
		p_separator = ft_strchr(stash, '\n');
		if (p_separator != NULL)
		{
			len_to_separator = p_separator - stash + 1;
			line = ft_substr(stash, 0, len_to_separator);
			if (line == NULL)
			{
				free_and_null (&stash);
				free_and_null (&buffer);
				return (NULL);
			}
			temp = ft_strdup(stash + len_to_separator);
			free_and_null (&stash);
			stash = temp;
			free_and_null (&buffer);
			return (line);
		}
	}
	if (bytes_read == 0 && stash[0] != '\0')
	{
		line = ft_strdup(stash);
		if (line == NULL)
		{
			free_and_null (&stash);
			free_and_null (&buffer);
			return (NULL);
		}
		free_and_null(&stash);
		free_and_null (&buffer);
		return (line);
	}
	free_and_null (&stash);
	free_and_null (&buffer);
	return (NULL);
}

void	free_and_null(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}
