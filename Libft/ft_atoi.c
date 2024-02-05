int	ft_atoi(const char *str);

/* int	main(void)
{
	char	str[] = "    	 ----++154510565646549qaad45445125";
	int result;
	printf("la vieille chaine en char est %s\n", str);
	printf("=========================\n");
	result = ft_atoi(str);
	printf("la nouvelle chaine en int est %d\n", result);
	return (0);
} */

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	signe;
	int	result;

	i = 0;
	minus = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			minus++;
		}
		i++;
	}
	if (minus % 2 != 0)
		signe = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10 + (str[i++] - '0'));
	return (result * signe);
}
