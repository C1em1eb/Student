#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

// Function declarations
char *get_next_line(int fd);
static char *initialize_stash(char *stash);
static char *read_and_append(int fd, char **stash, char *buffer);
static char *extract_line(char **stash);
void ft_free_and_null(char **ptr);

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	stash = initialize_stash(stash);
	if (stash == NULL)
	{
		ft_free_and_null(&buffer);
		return (NULL);
	}
	line = read_and_append(fd, &stash, buffer);
	ft_free_and_null(&buffer);
	if (line == NULL && stash != NULL)
	{
		if (*stash != '\0')
			line = ft_strdup(stash);
		ft_free_and_null(&stash);
	}
	return (line);
}

static char *initialize_stash(char *stash)
{
	if (stash == NULL)
	{
		stash = ft_strdup("");
		if (stash == NULL)
			return (NULL);
	}
	return (stash);
}

static char *read_and_append(int fd, char **stash, char *buffer)
{
	ssize_t bytes_read;
	char *temp;
	char *line;

	line = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free_and_null(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		if (temp == NULL)
		{
			ft_free_and_null(stash);
			return (NULL);
		}
		ft_free_and_null(stash);
		*stash = temp;
		line = extract_line(stash);
		if (line != NULL)
			return (line);
	}
	return (line);
}

static char *extract_line(char **stash)
{
	char *line;
	char *temp;
	char *p_separator;
	int len_to_separator;

	p_separator = ft_strchr(*stash, '\n');
	if (p_separator != NULL)
	{
		len_to_separator = p_separator - *stash + 1;
		line = ft_substr(*stash, 0, len_to_separator);
		if (line == NULL)
		{
			ft_free_and_null(stash);
			return (NULL);
		}
		temp = ft_strdup(*stash + len_to_separator);
		if (temp == NULL)
		{
			ft_free_and_null(&line);
			ft_free_and_null(stash);
			return (NULL);
		}
		ft_free_and_null(stash);
		*stash = temp;
		return (line);
	}
	return (NULL);
}

void ft_free_and_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
