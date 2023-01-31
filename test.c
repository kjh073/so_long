#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
	char *result;
	fd = open("maps/map.ber", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
    printf("%zu", ft_strlen(result));
	result = get_next_line(fd);
	printf("%s", result);
    printf("%zu", ft_strlen(result));
	result = get_next_line(fd);
	printf("%s", result);
    printf("%zu", ft_strlen(result));
	result = get_next_line(fd);
	printf("%s", result);
    printf("%zu", ft_strlen(result));
	result = get_next_line(fd);
	printf("%s", result);
    printf("%zu", ft_strlen(result));
}
