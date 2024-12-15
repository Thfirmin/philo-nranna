int	ph_strlen(const char *str)
{
	int	size;

	size = 0;
	if (str)
		while (*(str + size))
			size++;
	return (size);
}
