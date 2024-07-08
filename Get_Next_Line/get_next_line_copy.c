/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:08:38 by cleblond          #+#    #+#             */
/*   Updated: 2024/07/04 17:56:26 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **ptr);
void	*get_next_line(int fd);
char	*ft_read_stash(int fd, char **buffer, char **stash, char **line);
char *ft_search_extract_line(char **stash, char **buffer);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free (line);
	}
	close (fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
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
			free (buffer);
			return (NULL);
		}
	}
	//	stash[ft_strlen(stash)] = '\0';
	if (ft_read_stash(fd, &buffer, &stash, &line) == NULL)
	{
		free (buffer);
		free (stash);
		return (NULL);
	}
	return (line);
}

char	*ft_read_stash(int fd, char **buffer, char **stash, char **line)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		if (temp == NULL)
		{
			free(*stash);
			free(*buffer);
			return (NULL);
		}
		free(*stash);
		*stash = temp;
		if (ft_search_extract_line(stash, buffer) != NULL)
		break;
	}
	if (bytes_read == 0 && stash[0] != '\0')
	{
		*line = ft_strdup(stash);
		if (*line == NULL)
		{
			free (*stash);
			free (*buffer);
			return (NULL);
		}
		free_and_null(&stash);
		free (*buffer);
		return (line);
	}
	free_and_null (&stash);
	free_and_null (&buffer);
	return (NULL);
}

char *ft_search_extract_line(char **stash, char **buffer)
{
	char	*p_separator;
	int		len_to_separator;
	char	*temp;
	char	*line

	p_separator = ft_strchr(stash, '\n');
	if (p_separator != NULL)
	{
		len_to_separator =  p_separator - stash + 1;
		line = ft_substr(stash, 0, len_to_separator);
		if (line == NULL)
		{
			free_and_null (&stash);
			free_and_null (&buffer);
			return (NULL);
		}
		temp = ft_strdup(stash + len_to_separator);
		if (temp == NULL)
		{
			free(*stash);
			free(*buffer);
			return (NULL);
		}
		free_and_null (&stash);
		*stash = temp;
		return (line);
	}
	return (NULL);
}

void free_and_null(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}
