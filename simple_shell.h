#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>

void _print(const char *text);
int main(void);
void exec_command(const char *commands);
void prompt_display(void);
void read_input(char *command, size_t size);

#endif
