#include <stdio.h>
#include <philo.h>

static int	import_input(int argc, char *argv[]);

static int	is_int(const char *str);

int	main(int argc, char *argv[])
{
	if (import_input(argc, argv) == -1)
		return (1);
	printf("Hello, World!\n");
	return (0);
}

static int	import_input(int argc, char *argv[])
{
	int	i;

	if (argc < 4 || argc > 5)
	{
		ph_log(2, "Usage: ");
		ph_log(2, *argv);
		ph_log(2, " <nb_philo> <tm_eat> <tm_sleep> [<nb_max_eat>]\n");
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]) || ph_atoi(argv[i]) < 1)
			return (ph_log(2, "Error: Invalid argument\n"), -1);
		i++;
	}
	return (0);
}

static int	is_int(const char *str)
{
	int				i;
	unsigned int	nbr;

	if (ph_strlen(str) > 10)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
		i++;
	}
	nbr = ph_atoi(str);
	if (nbr > __INT_MAX__)
		return (0);
	return (1);
}
