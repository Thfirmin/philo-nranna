int	ph_atoi(const char *str)
{
	int		nbr;
	char	signal;

	signal = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			signal = -1;
	nbr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += (*str - '0') * signal;
		str++;
	}
	return (nbr);
}

