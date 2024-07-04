
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:03:51 by cleblond          #+#    #+#             */
/*   Updated: 2024/02/19 16:03:53 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_update_stash(int fd, char **stash);
char	*ft_return_lines(char **stash);
char	*ft_return_final_line(char **stash);
void	ft_free_and_null(char **ptr);
int		ft_update_stash(char **stash, char *buffer);

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
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
			return (NULL);
	}
	line = ft_read_update_stash(fd, &stash);
	if (line != NULL)
		return (line);
	if (stash && stash[0] != '\0')
		return (ft_return_final_line(&stash));
	ft_free_and_null (&stash);
	return (NULL);
}

char	*ft_read_update_stash(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (ft_update_stash(stash, buffer) == -1)
		{
			ft_free_and_null(&buffer);
			return (NULL);
		}
		line = ft_return_lines(stash);
		if (line != NULL)
		{
			ft_free_and_null(&buffer);
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	ft_free_and_null(&buffer);
	return (NULL);
}

int	ft_update_stash(char **stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*stash, buffer);
	if (temp == NULL)
	{
		ft_free_and_null(stash);
		return (-1);
	}
	ft_free_and_null(stash);
	*stash = temp;
	return (0);
}

char	*ft_return_lines(char **stash)
{
	char	*line;
	char	*temp;
	char	*p_separator;
	int		len_to_separator;

	p_separator = ft_strchr(*stash, '\n');
	if (p_separator != NULL)
	{
		len_to_separator = p_separator - *stash + 1;
		line = ft_substr(*stash, 0, len_to_separator);
		if (line == NULL)
			return (NULL);
		temp = ft_strdup(*stash + len_to_separator);
		if (temp == NULL)
		{
			ft_free_and_null (&line);
			return (NULL);
		}
		ft_free_and_null (stash);
		*stash = temp;
		return (line);
	}
	return (NULL);
}

char	*ft_return_final_line(char **stash)
{
	char	*line;

	line = ft_strdup(*stash);
	if (line == NULL)
		return (NULL);
	ft_free_and_null (stash);
	return (line);
}

void	ft_free_and_null(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}
