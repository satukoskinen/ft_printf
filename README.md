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
|`d`, `i` : signed</br>decimal|`default`: int</br>`h`: short</br>`hh`: signed char</br>`l`: long</br>`ll`: long long|minimum number of digits; if only `.` is given, precision is taken as zero; if fewer digits are needed, the value is padded on the left with zeroes|if the converted value, with</br>flags considered, has fewer</br>characters than the field width</br>(given as a decimal digit string),</br>it will be padded with spaces on the left (or right, if the `-` flag has been given) to fill out the given field width.|`+` add a plus sign in front of a non-negative number</br>`' '` add a blank in front of a non-negative number; ignored if `+` is given</br>`0` zero padding: padding on the left with '0's instead of blanks; ignored if precision or `-` is given</br>`-` negative field width: values left-adjusted
|`o` : unsigned</br>octal|`default`: unsigned int</br>`h`: unsigned short</br>`hh`: unsigned char</br>`l`: unsigned long</br>`ll`: unsigned long long|-"-|-"-|`#` precision is increased (if needed) to force the first digit to be 0</br>`0` zero padding </br>`-` negative field width</br>|
|`u` : unsigned</br>decimal|-"-|-"-|-"-|`0` zero padding; ignored if precision or `-`is given</br>`-` negative field width</br>|
|`x`, `X` : unsigned</br>hexadecimal|-"-|-"-|-"-|`#` non-zero result gets prefix "0x" or "0X"</br>`0` zero padding; ignored if precision or `-`is given</br>`-` negative field width</br>|
|`c` : char (int</br>converted to</br>unsigned char)|`default`: int|-|-"-|`-` negative field width|
|`s` : character</br>string (pointer</br>to char array)|`default`: char*|maximum number of characters to print; if precision is specified and is less than the length of the array, the string does not have to be nul-terminated|-"-|`-` negative field width|
|`f`, `F` : double|`default`: double</br>`l`: double</br>`L`: long double|number of digits to appear after the decimal point; if precision is zero as in `%.f` or `%.0f`, only the integral part of the double will be printed; if precision is omitted, it is set to a default value of 6|-"-|`#` result contains a decimal point even if precision is set to zero</br>`+` add a plus sign in front of a non-negative number</br>`' '` add a blank in front of a non-negative number; ignored if `+` is given</br>`0` zero padding; ignored if `-`is given</br>`-` negative field width|

