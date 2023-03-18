#include "ft_printf.h"

char	*ft_strchr(const char* str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (char *)str;
		str++;
	}
	if (!c)
		return (char *) str;
	return (0);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_numlen(int n, int base)
{
	int	len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return len;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return len;
}
