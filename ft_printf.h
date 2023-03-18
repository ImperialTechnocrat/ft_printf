#ifndef FT_PRINTF_H
# define FT_PRINT_H
# define HEX_BASE_BIG "0123456789ABCDEF"
# define HEX_BASE_SMALL "0123456789abcdef"
# define DECA_BASE "0123456789"

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>


typedef struct s_flags
{
  char specifier;
  int prefix;
  int sign_space;
  int plus;
  int width;
  int zero_padding;
  int left_justify;
} flags_t;

void	format_string(char *str, flags_t flags);
char	*ft_strchr(const char* str, int c);
int	ft_putchar(int c);
int	ft_numlen(int n, int base);
int	ft_strlen(char *str);
int ft_num_to_str(unsigned n, char *base, char sign, flags_t flags);
void ft_int_to_num(int n, char *base, flags_t flags);
int ft_putstr(const char *str);
int ft_str_to_int(const char *format, int len);
int ft_ptrlen(uintptr_t n, int base);
int ft_ptr_to_str(uintptr_t p, char *base);
flags_t init_struct(const char *format, const char *end_flag);
const char *flags_process(va_list args, const char *format);
int ft_printf(const char *format, ...);

#endif
