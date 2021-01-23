# ft_printf

Restricted implementation of the printf function from the standard C library.

The prototype is `int	ft_printf(char *format, ...)` where `format` is the format string that specifies how subsequent optional arguments are converted for output.

The format string is composed of zero or more *directives*: either ordinary characters that are simply copied to output or conversion specifications that start with an `%` and consist of the following:
```
%[flags][minimum field width][.precision][length modifier][conversion type]
```
Flags, minimum field width, precision and length modifier are optional. At its simplest, the conversion specification is of the form `%[conversion type]`, e.g. `%d`. `%%` produces the % character.

|Conversion type|Length modifier|Precision|Min. field width|Flags|
|-|-|-|-|-|
|`d`, `i` : signed</br>decimal|`default`: int</br>`h`: short</br>`hh`: signed char</br>`l`: long</br>`ll`: long long|-|-|`+` description</br>`' '` description</br>`0` padding on the left with '0's instead of blanks; ignored if precision or `-` is given</br>`-` description
|`o` : unsigned</br>octal|`default`: unsigned int</br>`h`: unsigned short</br>`hh`: unsigned char</br>`l`: unsigned long</br>`ll`: unsigned long long|-|-|`#` precision is increased (if needed) to force the first digit to be 0</br>`0`</br>`-`</br>|
|`u` : unsigned</br>decimal|-"-|-|-|`0`</br>`-`</br>|
|`x`, `X` : unsigned</br>hexadecimal|-"-|-|-|`#` non-zero result gets prefix "0x" or "0X"</br>`0`</br>`-`</br>|
|`c` : char (int</br>converted to</br>unsigned char)|`default`: int|-|-|`-`|
|`s` : character</br>string (pointer</br>to char array)|`default`: char*|maximum number</br>of characters to print|-|`-`|


- self-promoting types / default argument promotions