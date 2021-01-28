#include <stdio.h>
#include <inttypes.h>
#include "ft_printf.h"

int main(void)
{
	void *ptr;
	uintmax_t value;

	value = (uintmax_t)ptr;

	printf("pointer %p\n", ptr);
	ft_printf("pointer %p\n", ptr);
}