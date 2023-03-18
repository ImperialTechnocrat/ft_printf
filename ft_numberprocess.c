#include "ft_printf.h"

int ft_num_to_str(unsigned n, char *base, char sign, struct s_flags flags)
{
  int baselen;
  int numlen;
  char *numstr;
    
  baselen = ft_strlen(base);
  numlen = ft_numlen(n, baselen);
  numstr = (char *)malloc((numlen + 2) * sizeof(char));
  numstr[numlen+1] = '\0';
  numstr[0] = sign;
  while (n != 0)
  {
    numstr[numlen] = base[n % baselen];
    n /= baselen;
    numlen--;
  }
  format_string(numstr, flags);
  return 0;
}

void ft_int_to_num(int n, char *base, struct s_flags flags)
{
  char sign;
  
  if (n >= 0)
    sign = '+';
  else
  {
    sign = '-';
    n = -n;
  }
  ft_num_to_str(n, base, sign, flags);
}

int ft_putstr(const char *str)
{
  while (*str)
    ft_putchar(*str++);
  return 0;
}

int ft_str_to_int(const char *format, int len)
{
  int order = 1;
  int number = 0;
  while (len > 1)
  {
    order *= 10;
    --len;
  }
  while (order > 0)
  {
    number += (order * (*format - '0'));
    order /= 10;
    ++format;
  }
  return number;
}
