#include "ft_printf.h"

void	format_string(char *str, struct s_flags flags)
{
	char	padding;

	if (flags.zero_padding)
		padding = '0';
	else\
		padding = ' ';
	if (flags.sign_space)
	{
		if (*str == '+')
			*str = ' ';
	}
	if (!flags.plus)
	{
		if(*str == '+')
			++str;
	}
	if (flags.prefix)
	{
		if (flags.specifier == 'x')
			ft_putstr("0x");
		if (flags.specifier == 'X')
			ft_putstr("0X");
	}
	if ((flags.width - ft_strlen(str)) > 0)
	{
		flags.width = flags.width - ft_strlen(str);
		if (flags.left_justify)
			ft_putstr(str);
		else if (!flags.left_justify && flags.zero_padding)
			ft_putchar(*str++);
		while (flags.width)
		{
			ft_putchar(padding);
			--flags.width;
		}
	}
	if (!flags.left_justify)
		ft_putstr(str);
}
