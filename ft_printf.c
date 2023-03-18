#include "ft_printf.h"

struct s_flags init_struct(const char *format, const char *end_flag)
{
  struct s_flags flags = {'\0', 0, 0, 0, 0, 0};
  int i = 0;
  flags.specifier = *end_flag;
  while(format != end_flag && !ft_strchr("123456789", *format))
  {
    if (ft_strchr("# +0-", *format))
    {
      if (*format == '#')
        flags.prefix = 1;
      if (*format == ' ')
        flags.sign_space = 1;
      if (*format == '+')
        flags.plus = 1;
      if (*format == '0')
        flags.zero_padding = 1;
      if (*format == '-')
        flags.left_justify = 1;
    }
    ++format;
  }
  while (ft_strchr("1234567890", *format++))
  {
    ++i;
  }
  if (i)
    flags.width = ft_str_to_int((format - (i + 1)), i);
  return flags;
}

const char *flags_process(va_list args, const char *format)
{
  const char *end_flag;
  
  end_flag = format;
  while (!ft_strchr("diuscpxX%", *end_flag) && end_flag)
    end_flag++;
  if (*end_flag == 'c')
    ft_putchar(va_arg(args, int));
  else if (*end_flag == 's')
    ft_putstr(va_arg(args, char *));
  else if (*end_flag == 'p')
    ft_ptr_to_str(va_arg(args, uintptr_t), "0123456789abcdef");
  else if (*end_flag == 'd' || *end_flag == 'i')
    ft_int_to_num(va_arg(args, int), "0123456789", init_struct(format, end_flag));
  else if (*end_flag == 'u')
    ft_num_to_str(va_arg(args, unsigned int), "0123456789", '+', init_struct(format, end_flag));
  else if (*end_flag == 'x')
    ft_num_to_str(va_arg(args, unsigned int), "0123456789abcdef", '+', init_struct(format, end_flag));
  else if (*end_flag == 'X')
    ft_num_to_str(va_arg(args, unsigned int), "0123456789ABCDEF", '+', init_struct(format, end_flag));
  else if (*end_flag == '%')
    ft_putchar('%');
  return ++end_flag;
}

int ft_printf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  
  while (*format)
  {
    if (*format != '%')
      ft_putchar(*format++);
    else
       format = flags_process(args, ++format);
  }
  return 0;
}
