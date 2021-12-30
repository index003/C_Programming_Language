#include <stdio.h>
#include <limits.h>

int main() {
   printf("The number of bits in a byte %d\n", CHAR_BIT);
   printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
   printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
   printf("The maximum value of SHORT INT = %d\n", SHRT_MAX); 
   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d\n", INT_MAX);
   printf("The minimum value of CHAR = %d\n", CHAR_MIN);
   printf("The maximum value of CHAR = %d\n", CHAR_MAX);
   printf("The minimum value of LONG = %ld\n", LONG_MIN);
   printf("The maximum value of LONG = %ld\n", LONG_MAX);
}


/*
CHAR_BIT    8                       定义一个字节的比特数。
SCHAR_MIN   -128                    定义一个有符号字符的最小值。
SCHAR_MAX   127                     定义一个有符号字符的最大值。
UCHAR_MAX   255                     定义一个无符号字符的最大值。
CHAR_MIN    0                       定义类型 char 的最小值，如果 char 表示负值，
                                    则它的值等于 SCHAR_MIN，否则等于 0。
CHAR_MAX    127                     定义类型 char 的最大值，如果 char 表示负值，
                                    则它的值等于 SCHAR_MAX，否则等于 UCHAR_MAX。
MB_LEN_MAX  1                       定义多字节字符中的最大字节数。
SHRT_MIN    -32768                  定义一个短整型的最小值。
SHRT_MAX    +32767                  定义一个短整型的最大值。
USHRT_MAX   65535                   定义一个无符号短整型的最大值。
INT_MIN     -2147483648             定义一个整型的最小值。
INT_MAX     2147483647              定义一个整型的最大值。
UINT_MAX    4294967296              定义一个无符号整型的最大值。
LONG_MIN    -9223372036854775808    定义一个长整型的最小值。
LONG_MAX    9223372036854775807     定义一个长整型的最大值。
ULONG_MAX   1.8446744e+19           定义一个无符号长整型的最大值。

CHAR_BIT    8                       Defines the number of bits in a byte.
SCHAR_MIN   -128                    Defines the minimum value for a signed char.
SCHAR_MAX   +127                    Defines the maximum value for a signed char.
UCHAR_MAX   255                     Defines the maximum value for an unsigned char.
CHAR_MIN    -128                    Defines the minimum value for type char and its value will be equal 
                                    to SCHAR_MIN if char represents negative values, otherwise zero.
CHAR_MAX    +127                    Defines the value for type char and its value will be equal to 
                                    SCHAR_MAX if char represents negative values, otherwise UCHAR_MAX.
MB_LEN_MAX  16                      Defines the maximum number of bytes in a multi-byte character.
SHRT_MIN    -32768                  Defines the minimum value for a short int.
SHRT_MAX    +32767                  Defines the maximum value for a short int.
USHRT_MAX   65535                   Defines the maximum value for an unsigned short int.
INT_MIN     -2147483648             Defines the minimum value for an int.
INT_MAX     +2147483647             Defines the maximum value for an int.
UINT_MAX    4294967295              Defines the maximum value for an unsigned int.
LONG_MIN    -9223372036854775808    Defines the minimum value for a long int.
LONG_MAX    +9223372036854775807    Defines the maximum value for a long int.
ULONG_MAX   18446744073709551615    Defines the maximum value for an unsigned long int.
*/
