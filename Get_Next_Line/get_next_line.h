#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len); */
void	free_and_null(char **ptr);
char	*get_next_line(int fd);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);

#endif
