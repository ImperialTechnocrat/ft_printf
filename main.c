#include "ft_printf.h"

int main()
{
  int p = 123456;
  
  printf("Char: \'%c\', string: \"%s\", d: %010d, i: %+10i, unint: %u, hex: %x, HEX: %#X, Pointer: %p and percent sign: %%\n", '!', "abeceda", -24585, p, 256, 47589, 785654, &p );
  ft_printf("Char: \'%c\', string: \"%s\", d: %010d, i: %+10i, unint: %u, hex: %x, HEX: %#X, Pointer: %p and percent sign: %%\n", '!', "abeceda", -24585, p, 256, 47589, 785654, &p );
  printf("%012d, % -10d, % 010d, %+010d\n", -p, p, p, p);
  ft_printf("%012d, % -10d, % 010d, %+010d\n", -p, p, p, p);

  return 0;
}
