/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblond <cleblond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:30:19 by cleblond          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:16 by cleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int main(void)
{
	int		fd;
	char	*line;

	//fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	fd = open("text", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
 		if (line == NULL)
			break;
		free (line);
	}
	free (line);
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
		stash = ft_strdup("");
	//printf("stash initial : %s\n", stash);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free (stash);
		free (buffer);
		return (NULL);
	}
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(stash, buffer);
		//printf("1st temp %s\n", temp);
		free (stash);
		stash = NULL;
		stash = temp;
		p_separator = ft_strchr(stash, '\n');
		if (p_separator != NULL)
		{
			len_to_separator =  p_separator - stash + 1;
			line = ft_substr(stash, 0, len_to_separator);
			temp = ft_strdup(stash + len_to_separator);
			free (stash);
			stash = NULL;
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
		//printf("final line %s\n", line);
		return (line);
	}
	if (bytes_read == -1)
	{
		free (stash);
		stash = NULL;
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	return (NULL);
}

void free_and_null(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}

