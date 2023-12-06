#include "simple_shell.h"

/**
 * main - get the PID
 *
 * Return: Always 0 as success
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}
