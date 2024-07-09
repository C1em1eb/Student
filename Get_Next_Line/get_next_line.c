#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char *stash;
	char		*line;
	char		*p_separator;
	int		 len_to_separator;
	ssize_t	 bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free_and_null (&buffer);
		ft_free_and_null (&stash);
		return (NULL);
	}
	line = NULL;
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
		{
			ft_free_and_null (&buffer);
			return (NULL);
		}
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break;
		buffer[bytes_read] = '\0'; 	// because read doesnt end null the buffer
		temp = ft_strjoin(stash, buffer);
		ft_free_and_null (&stash);
		stash = temp;
		p_separator = ft_strchr(stash, '\n'); // search for the presence of a new line in the stash
		if (p_separator != NULL)
		{
			len_to_separator = p_separator - stash + 1; // if new line found, where is it in the stash ? stash = 0
			line = ft_substr(stash, 0, len_to_separator); // exctract the line from the stash until the seperator
			if (line == NULL)
			{
				ft_free_and_null (&stash);
				ft_free_and_null (&buffer);
				return (NULL);
			}
			// copy the remainder from the stash to a temp and then to the stash from the position after p_separator
			temp = ft_strdup(stash + len_to_separator);
			ft_free_and_null (&stash);
			stash = temp;
			ft_free_and_null (&buffer);
			return (line);
		}
	}
	if (bytes_read == 0 && stash[0] != '\0')
	{
		line = ft_strdup(stash);
		if (line == NULL)
		{
			ft_free_and_null (&stash);
			ft_free_and_null (&buffer);
			return (NULL);
		}
		ft_free_and_null(&stash);
		ft_free_and_null (&buffer);
		return (line);
	}
	ft_free_and_null (&stash);
	ft_free_and_null (&buffer);
	return (NULL);
}

void	ft_free_and_null(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}
