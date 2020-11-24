#include "holberton.h"
/**
 * _atoi - convert str into ingeter
 * @str: input str
 * Return: integer
 */
int _atoi(char *str)
{
int i = 0;
int sign = 1;
int idx_digt = 0;
if (str[0] == '-')
{
sign = -1;
idx_digt++;
}
for (idx_digt = 0; str[idx_digt] != '\0'; ++idx_digt)
i = i * 10 + str[idx_digt] - '0';
return (sign * i);
}
