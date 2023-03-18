#include "ft_printf.h"

int ft_ptrlen(uintptr_t n, int base)
{
  int len;
  len = 1;
  while (n >= base)
  {
    n /= base;
    len++;
  }
  return len;
}

int ft_ptr_to_str(uintptr_t p, char *base)
{
  int baselen;
  int numlen;
  char *numstr;
    
  baselen = 16;
  numlen = ft_ptrlen(p, baselen);
  numstr = (char *)malloc((numlen + 1) * sizeof(char));
  numstr[numlen] = '\0';
  while (p != 0)
  {
    numstr[numlen - 1] = base[p % baselen];
    p /= baselen;
    numlen--;
  }
  ft_putstr("0x");
  ft_putstr(numstr);
  return 0;
}
