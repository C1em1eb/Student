#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
ssize_t	read(int fd, void *buf, size_t count);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const	*s1, char const	*s2);
int	ft_strlen_cons(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_and_null(char **ptr);

#endif
