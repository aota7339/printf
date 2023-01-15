#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

int	ft_printf(const char *fmt, ...);
int	cs_jump(va_list ap, const char frm);
int	print_c(char c);
int	print_s(const char *str);
int	print_di(long int n);
int	print_p(void *n);
int	print_u(unsigned int n);
int	print_x(unsigned long long n);
int	print_X(unsigned long long n);

#endif
