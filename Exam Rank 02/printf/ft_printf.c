#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags {
	int width;
	int precision;
} t_flags;

short is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int calc_digits(size_t nbr, size_t base_len)
{
	int digits = 0;

	while (nbr >= base_len)
	{
		nbr /= base_len;
		digits++;
	}
	return (++digits);
}

int ft_strlen(char *str)
{
	int count = 0;

	while (*str++)
		count++;
	return (count);
}

void ft_putstr_len(char *str, int len)
{
	int i = 0;
	while (str[i] && i < len)
		write(1, &str[i++], 1);
}

void put_n_char(int n, char c)
{
	while (n-- > 0)
		write(1, &c, 1);
}

void putnbr_base(size_t nbr, size_t base_len, const char *base)
{
	if (nbr >= base_len)
	{
		putnbr_base(nbr / base_len, base_len, base);
		putnbr_base(nbr % base_len, base_len, base);
	}
	else
		write(1, &base[nbr], 1);
}

int print_string(va_list arg, t_flags *flags)
{
	char *string = va_arg(arg, char*);
	if (!string)
		string = "(null)";
	int printed = ft_strlen(string);
	if (flags->precision >= 0 && flags->precision < printed)
		printed = flags->precision;
	put_n_char(flags->width - printed, ' ');
	ft_putstr_len(string, printed);
	return ((printed > flags->width) ? printed : flags->width);
}

int print_decimal(va_list arg, t_flags *flags)
{
	long decimal = va_arg(arg, int);
	int printed;
	int zero_count = 0;
	short negative = 0;

	if (decimal < 0)
	{
		decimal = -decimal;
		negative++;
	}
	printed = calc_digits(decimal, 10);
	if (decimal == 0 && flags->precision >= 0)
		printed = 0;
	if (flags->precision >= 0 && flags->precision > printed)
		zero_count += flags->precision - printed;
	if (negative)
		printed++;
	put_n_char(flags->width - (zero_count + printed), ' ');
	if (negative)
		write(1, "-", 1);
	put_n_char(zero_count, '0');
	printed += zero_count;
	if (decimal == 0 && flags->precision >= 0)
		return ((printed > flags->width) ? printed : flags->width);
	putnbr_base(decimal, 10, "0123456789");
	return ((printed > flags->width) ? printed : flags->width);
}

int print_hex(va_list arg, t_flags *flags)
{
	int printed;
	int zero_count = 0;
	unsigned int hex = va_arg(arg, unsigned int);
	
	printed = calc_digits(hex, 16);
	if (hex == 0 && flags->precision >= 0)
		printed = 0;
	if (flags->precision >= 0 && flags->precision > printed)
		zero_count = flags->precision - printed;
	put_n_char(flags->width - (zero_count + printed), ' ');
	put_n_char(zero_count, '0');
	printed += zero_count;
	if (hex == 0 && flags->precision >= 0)
		return ((printed > flags->width) ? printed : flags->width);
	putnbr_base(hex, 16, "0123456789abcdef");
	return ((printed > flags->width) ? printed : flags->width);
}

int dispatcher(char spec, va_list args, t_flags *flags)
{
	if (spec == 's')
		return (print_string(args, flags));
	if (spec == 'd')
		return (print_decimal(args, flags));
	if (spec == 'x')
		return (print_hex(args, flags));
	else return 0;
}

void parse_flags(char **str, t_flags *flags)
{
	while (is_digit(**str))
	{
		flags->width = (flags->width * 10) + (**str - 48);
		(*str)++;
	}
	if (**str == '.')
	{
		(*str)++;
		flags->precision = 0;
		while (is_digit(**str))
		{
			flags->precision = (flags->precision * 10) + (**str - 48);
			(*str)++;
		}
	}
}

int ft_printf(const char *str, ... )
{
	int printed = 0;
	va_list args;
	t_flags flags;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags.width = 0;
			flags.precision = -1;
			parse_flags((char**)&str, &flags);
			printed += dispatcher(*str, args, &flags);
		}	
		else
		{
			write(1, str, 1);
			printed++;
		}
		str++;
	}
	va_end(args);
	return (printed);
}
