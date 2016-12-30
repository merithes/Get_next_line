#ifndef GET_NEXT_LINE_H
# define BUFF_SIZE 0
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int		get_next_line(int fd, char **input);

#endif
