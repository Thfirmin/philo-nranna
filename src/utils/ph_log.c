#include <unistd.h>
#include <philo.h>

ssize_t	ph_log(int fd, const char *str)
{
	if (!str)
		return (-1);
	return (write(fd, str, ph_strlen(str)));
}
