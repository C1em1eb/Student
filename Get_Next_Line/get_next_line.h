#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
ssize_t	read(int fd, void *buf, size_t count);
char	*ft_fill_stash(char *buffer);

#endif
