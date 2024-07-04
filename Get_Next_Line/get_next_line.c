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
//void	ft_free_and_null(char **ptr);
int		ft_update_stash(char **stash, char *buffer);

/* int	main(void)
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
} */

static void	free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	char		*temp;
	char		*p_separator;
	int			len_to_separator;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
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
	p_separator = ft_strchr(stash, '\n');
	while (p_separator == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free_and_null (&buffer);
			free_and_null (&stash);
			return (NULL);
		}
		if (bytes_read == 0)
		{
			if (stash[0] != '\0')
			{
				line = ft_strdup(stash);
				free_and_null (&stash);
				if (line == NULL)
				{
					free_and_null (&buffer);
					return (NULL);
				}
			}
			free_and_null (&buffer);
			free_and_null (&stash);
			return (line);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		free_and_null (&stash);
		if (!temp)
		{
			free_and_null (&buffer);
			return (NULL);
		}
		stash = temp;
		p_separator = ft_strchr(stash, '\n');
	}
	if (p_separator)
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
		if (stash == NULL)
		{
			free_and_null (&line);
			free_and_null (&buffer);
			return (NULL);
		}
	}
	else if (stash[0] != '\0')
	{
		line = ft_strdup(stash);
		free_and_null (&stash);
		if (line == NULL)
		{
			free_and_null (&buffer);
			return (NULL);
		}
	}
	free_and_null (&buffer);
	return (line);
}
