int	main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		while(av[i])
			i++;
		printf("%i\n", i);
	}
	return (0);
}
