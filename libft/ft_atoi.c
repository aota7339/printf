#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t		i;
	long int	r;
	int			sign;

	i = 0;
	r = 0;
	sign = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (sign == -1)
		r = -1 * r;
	return ((int)r);
}
/*

void	my_test_atoi(const char *input)
{
	int a = ft_atoi(input);
	int b = atoi(input);
	
	printf("%s\n", input);
	printf("  %d：ft_atoi\n", a);
	printf("  %d：atoi\n", b);
	assert(a == b);
}

int	testmain_atoi(void)
{
	my_test_atoi("0");
	my_test_atoi("1");
	my_test_atoi("-1");
	my_test_atoi("8");
	my_test_atoi("127");
	my_test_atoi("128");
	my_test_atoi("129");

	my_test_atoi("254");
	my_test_atoi("255");
	my_test_atoi("256");

	my_test_atoi("2147483646");
	my_test_atoi("2147483647");//INT_MAX
	my_test_atoi("2147483648");

	my_test_atoi("4294967294");
	my_test_atoi("4294967295");//UNSIGNED INT_MAX
	my_test_atoi("4294967296");

	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775807");//LONG MAX
	my_test_atoi("9223372036854775808");
	my_test_atoi("9223372036854775809");
	my_test_atoi("9223372036854775810");
	my_test_atoi("9223372036854775811");

	my_test_atoi("18446744073709551614");
	my_test_atoi("18446744073709551615");//UNSIGNED LONG MAX
	my_test_atoi("18446744073709551616");

	my_test_atoi(" -2147483649");
	my_test_atoi(" -2147483648");//INT_MIN
	my_test_atoi(" -2147483647");

	my_test_atoi(" -9223372036854775809");
	my_test_atoi(" -9223372036854775808");//LONG NIN
	my_test_atoi(" -9223372036854775807");

	my_test_atoi(" -922337203685477580009");
	my_test_atoi(" -922337203685477580008");//LONG NIN
	my_test_atoi(" -922337203685477580007");

	my_test_atoi(" 634106827633765826700");
	my_test_atoi(" 63410682763376582680");
	my_test_atoi(" 63410682763376582678");
	my_test_atoi(" 922337203685477580008");
	my_test_atoi(" 922337203685477580007");

	my_test_atoi(" -634106827633765826700");
	my_test_atoi(" -63410682763376582679");
	my_test_atoi(" -63410682763376582680");
	my_test_atoi(" -63410682763376582678");
	my_test_atoi(" -922337203685477580008");
	my_test_atoi(" -922337203685477580007");

	my_test_atoi("9223372036854775812");
	my_test_atoi("922337203685477570");
	my_test_atoi("922337203685477577");

	my_test_atoi("-9223372036854775807");
	my_test_atoi("-9223372036854775807");
	my_test_atoi("9223372036854775806");
	my_test_atoi("9223372036854775806");

	my_test_atoi("-2147483649");
	my_test_atoi("-2147483649");
	my_test_atoi("2147483648");
	my_test_atoi("2147483648");

	my_test_atoi("-2147483658");
	my_test_atoi("-2147483658");
	my_test_atoi("2147483657");
	my_test_atoi("2147483657");

	my_test_atoi("9223372036854775808");
	my_test_atoi("9223372036854775808");
	my_test_atoi("92233720368547758000");
	my_test_atoi("92233720368547758000");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-9223372036854775809");
	my_test_atoi("-92233720368547758000");
	my_test_atoi("-92233720368547758000");
	
	my_test_atoi("4772185884");
	my_test_atoi("9544371768");
	my_test_atoi("14316557653");
	return (0);
}

int	main(void)
{
	testmain_atoi();

	system("leaks a.out");
	return (0);
}*/