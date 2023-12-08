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
#include <fcntl.h>

/* prototypes for all functions */

int main(void);
int main(void);
void prompt_display(void);
void execute_command(char *command);
char *read_command();
void handle_error(char *message);
extern char **environ;
void writeoutput(const char *message);

#endif /* SIMPLE_SHELL_H */
