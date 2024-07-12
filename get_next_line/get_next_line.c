/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cleblond <cleblond@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/12 14:26:50 by cleblond		  #+#	#+#			 */
/*   Updated: 2024/07/12 14:32:45 by cleblond		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	read_and_process(int fd, char *buffer, char **stash, char **line)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*p_separator;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(*stash, buffer);
	ft_free_and_null(stash);
	*stash = temp;
	p_separator = ft_strchr(*stash, '\n');
	if (p_separator != NULL)
	{
		*line = ft_substr(*stash, 0, (p_separator - *stash + 1));
		if (*line == NULL)
			return (ft_free_and_null(stash), -1);
		temp = ft_strdup(*stash + (p_separator - *stash + 1));
		ft_free_and_null(stash);
		*stash = temp;
		return (0);
	}
	return (bytes_read);
}

int	init_stash(char **stash)
{
	if (*stash == NULL)
	{
		*stash = ft_strdup("");
		if (*stash == NULL)
			return (0);
	}
	return (1);
}

char	*finalize_line(char **stash, char *buffer, char **line)
{
	if (*stash && **stash != '\0')
	{
		*line = ft_strdup(*stash);
		ft_free_and_null(stash);
		ft_free_and_null(&buffer);
		return (*line);
	}
	ft_free_and_null(stash);
	ft_free_and_null(&buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	ssize_t		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_and_null(&buffer), ft_free_and_null(&stash), NULL);
	line = NULL;
	if (!init_stash(&stash))
		return (ft_free_and_null(&buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read_and_process(fd, buffer, &stash, &line);
		if (bytes_read < 0)
			return (ft_free_and_null(&stash), ft_free_and_null(&buffer), NULL);
		if (line != NULL)
			return (ft_free_and_null(&buffer), line);
	}
	return (finalize_line(&stash, buffer, &line));
}

void	ft_free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
