/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:17:49 by hly               #+#    #+#             */
/*   Updated: 2015/02/16 17:57:16 by hly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <libfts.h>

void	test_ft_bzero(char **str)
{
	int		n[3] = {0, 4, 10};
	int		i;
	int		j;
	int		len;
	char	*s;

	i = 0;
	len = strlen(str[0]);
	printf("--------------------\n  TEST FT_BZERO\n--------------------\n");
	printf("Test on the string \"%s\"\n", str[0]);
	while (i < 3)
	{
		s = strdup(str[0]);
		j = -1;
		ft_bzero((void *)s, n[i]);
		printf("   case: n = %d | result: ", n[i]);
		while (++j < len)
			printf("%c", *(s + j));
		i++;
		printf("\n");
		free(s);
	}
}

void	test_ft_strcat(char **str)
{
	char	*s;
	char	*s2;

	printf("--------------------\n  TEST FT_STRCAT\n--------------------\n");
	s = strdup(str[0]);
	s2 = strdup(str[1]);
	printf("Test with \"%s\" and \"%s\"\n", str[0], str[1]);
	ft_strcat(s, s2);
	printf("   After concatenation: %s\n", s);
	free(s);
	free(s2);
	s = strdup(str[3]);
	s2 = strdup(str[1]);
	printf("Test with \"%s\" and \"%s\"\n", str[3], str[1]);
	ft_strcat(s, s2);
	printf("   After concatenation: %s\n", s);
	free(s);
	free(s2);
}
/*
void	test_ft_is(char **str, int (*function)(int), int *n, int nbtest)
{
	int		i;
	int		j;

	i = 0;
	while (i < nbtest)
	{
		j = 0;
		printf("Test with \"%s\": ", str[n[i]]);
		while (j == 0 || str[n[i]][j])
		{
			if (function(str[n[i]][j]))
			{
				if (isprint(str[n[i]][j]))
					printf("\033[22;32m%c\033[0m", str[n[i]][j]);
				else
					printf("\033[22;32mOK\033[0m");
			}
			else
			{
				if (isprint(str[n[i]][j]))
					printf("\033[22;31m%c\033[0m", str[n[i]][j]);
				else
					printf("\033[22;31mFAIL\033[0m");
			}
			j++;
		}
		printf("\n");
		i++;
	}
}
*/

void	test_ft_is(int (*function)(int), int max)
{
	int		i;
	int		j;
	int		failTab[256] = {0};

	i = 0;
	j = 0;
	while (i <= max)
	{
		if (isprint(i))
		{
			if (function(i))
				printf("\033[22;32m%c\033[0m", i);
			else
				printf("\033[22;31m%c\033[0m", i);
		}
		else
			failTab[i] = 1;
		i++;
	}
	printf("\n");
	if (max > 127)
	{
		i = -1;
		printf("Failed at:\n");
		while (++i <= max)
		{
			if (failTab[i])
			{
				printf("%d ", i);
				j++;
			}
			if (j % 30 == 0)
				printf("\n");
		}
		printf("\n");
	}
}

void	test_ft_to(char **str, int (*function)(int), int *n, int nbtest)
{
	int		i;
	int		j;
	int		result;

	i = 0;
	while (i < nbtest)
	{
		j = 0;
		printf("Test with \"%s\": ", str[n[i]]);
		while (j == 0 || str[n[i]][j])
		{
			result = function(str[n[i]][j]);
			if (str[n[i]][j] != result)
				printf("\033[22;32m%c\033[0m", result);
			else
				printf("\033[22;31m%c\033[0m", result);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	test_ft_isalpha()
{
	printf("--------------------\n  TEST FT_ISALPHA\n--------------------\n");
	test_ft_is(ft_isalpha, 255);
}

void	test_ft_isdigit()
{
	printf("--------------------\n  TEST FT_ISDIGIT\n--------------------\n");
	test_ft_is(ft_isdigit, 127);
}

void	test_ft_isalnum()
{
	printf("--------------------\n  TEST FT_ISALNUM\n--------------------\n");
	test_ft_is(ft_isalnum, 255);
}

void	test_ft_isascii()
{
	printf("--------------------\n  TEST FT_ISASCII\n--------------------\n");
	test_ft_is(ft_isascii, 127);
}

void	test_ft_isprint()
{
	printf("--------------------\n  TEST FT_ISPRINT\n--------------------\n");
	test_ft_is(ft_isprint, 255);
}

void	test_ft_toupper(char **str)
{
	int		n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};

	printf("--------------------\n  TEST FT_TOUPPER\n--------------------\n");
	test_ft_to(str, ft_toupper, n, 9);
}

void	test_ft_tolower(char **str)
{
	int		n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};

	printf("--------------------\n  TEST FT_TOLOWER\n--------------------\n");
	test_ft_to(str, ft_tolower, n, 9);
}

int		main()
{
	char	*str[] = {	"0123456789",
						"abcdefghijklmnopqrstuvwxyz",
						"!@#$%^&*()_-+ =;:<>,.?/~`\"\'{}[]|\\",
						"",
						"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
						"a",
						"1",
						"$",
						"abc123$!?",
						NULL,
						NULL + 2 };

	test_ft_bzero(str);
	test_ft_strcat(str);
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper(str);
	test_ft_tolower(str);
/*	c = 97;
	printf("%p\n", s1);
	s1 = ft_strdup(toto);
	printf("%p\n", s1);
	free(s1);
	printf("strdup: %s\n", ft_strdup(tata));
	s1 = strdup(toto);
	printf("s1: %s\n", s1);
	ft_bzero((void *)s1, strlen(toto));
	printf("%s\n", s1);
	printf("%s\n", s1 + 1);
	printf("%s\n", s1 + 2);
	printf("%s\n", s1 + 3);
	s1 = ft_strdup(toto);
	printf("s1: %s\n", s1);
	s1 = ft_strcpy(s1, tata);
	printf("s1 after copy: %s\n", s1);
	printf("s1 length: %zu\n", ft_strlen(s1));
	printf("s1 after concatenation: %s\n", ft_strcat(s1, tata));
	printf("%c is alpha: %d\n", c, ft_isalpha(c));
	printf("%c is digit: %d\n", c, ft_isdigit(c));
	printf("%c is alnum: %d\n", c, ft_isalnum(c));
	printf("%c is ascii: %d\n", c, ft_isascii(c));
	printf("%c is print: %d\n", c, ft_isprint(c));
	printf("%c toupper: %c\n", c, ft_toupper(c));
	c = ft_toupper(c);
	printf("%c tolower: %c\n", c, ft_tolower(c));
	ft_puts(s1);
//	ft_puts(NULL);
//	ft_puts(null);
	printf("%s\n", s1);
	printf("memset: %s\n", (char *)ft_memset(s1, 'a', 4));
//	printf("memset: %s\n", (char *)memset(s1, 'a', 10));
	printf("memcpy: %s\n", (char *)ft_memcpy(s1, toto, 2));
	ft_cat(open("./textfile", O_RDONLY));
//	printf("%d\n", (open("./textfile", O_RDONLY)));*/
//	ft_cat(open("./textfile", O_RDONLY));
	(void)str;
	return(0);
}
