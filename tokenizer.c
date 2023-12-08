#include "simple_shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int n, p, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (n = 0; str[n] != '\0'; n++)
		if (!is_delim(str[n], d) && (is_delim(str[n + 1], d) || !str[n + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (n = 0, p = 0; p < numwords; p++)
	{
		while (is_delim(str[n], d))
			n++;
		k = 0;
		while (!is_delim(str[n + k], d) && str[n + k])
			k++;
		s[p] = malloc((k + 1) * sizeof(char));
		if (!s[p])
		{
			for (k = 0; k < p; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[p][m] = str[n++];
		s[p][m] = 0;
	}
	s[p] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int n, p, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		if ((str[n] != d && str[n + 1] == d) ||
				    (str[n] != d && !str[n + 1]) || str[n + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (n = 0, p = 0; p < numwords; p++)
	{
		while (str[n] == d && str[n] != d)
			n++;
		k = 0;
		while (str[n + k] != d && str[n + k] && str[n + k] != d)
			k++;
		s[p] = malloc((k + 1) * sizeof(char));
		if (!s[p])
		{
			for (k = 0; k < p; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[p][m] = str[n++];
		s[p][m] = 0;
	}
	s[p] = NULL;
	return (s);
}
