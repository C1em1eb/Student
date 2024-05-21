#include "get_next_line.h"

int main(void)
{
	int		fd;

	fd = open("text", O_RDONLY);
	get_next_line(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char 	*temp;
	char 	*stash;
	char 	*line;
	char 	*pdollar;
	int		idollar;
	int		i;
	size_t 	bytes_read;

	buffer = NULL;
	buffer = malloc(sizeof(char)* BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	stash = malloc(sizeof(char)* (BUFFER_SIZE + 1) * 100);
	if (stash == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	ft_printf("buffer step 1 : %s\n", buffer);
	while (bytes_read > 0)
	{
		temp = ft_strdup(buffer);
		stash = ft_strjoin(stash, temp);
		pdollar = ft_strchr(stash, '$');
		i = 0;
		if (pdollar != NULL)
		{
			while (stash[i] != '$')
				i++;
			idollar = i;
			i = 0;
			line = ft_substr(stash, 0, idollar);
			stash = ft_substr(stash, idollar + 1, BUFFER_SIZE + 1);
			ft_printf("line : %s\n", line);
			free(line);
		}
		else
			ft_printf("stash 2 : %s\n", stash);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_printf("buffer step %i : %s\n", i, buffer);
	}
	if (bytes_read == 0)
		return (0);
	return (buffer);
}



char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
