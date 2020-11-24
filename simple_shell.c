#include "holberton.h"
/**
 * main - basic shell
 * @argc: argument counter
 * @argv: argument values
 * Return: ?
 */
int main(int argc, char *argv[])
{
  int exit_status = EXIT_SUCCESS;
  /* Redirect Interrupt signal to handler function */
  signal(SIGINT, handler);
  exit_status = loop(argv[0]); /*infinite command loop*/
  (void)argc;
  return (exit_status);
}
