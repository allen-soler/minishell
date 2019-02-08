int	main(int ac, char **av)
{
	int		i;
	char	*cwd;
	char	buff[4097];

	getcwd(buff, sizeof(buff));
	printf("hello %lu\n", strlen("OLDPWD="));

	return (0);
}
