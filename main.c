/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:17:49 by hly               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/03/09 16:36:56 by hly              ###   ########.fr       */
=======
/*   Updated: 2015/02/17 21:16:26 by hly              ###   ########.fr       */
>>>>>>> 0aac60474cb613f4db1fb72ecc1a9c00e751314c
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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

void	print_fail_tab(int *failTab, int max, char *msg)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	
	printf("%s :\n", msg);
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

void	test_ft_is(int (*function)(int), int max)
{
	int		i;
	int		failTab[256] = {0};

	i = 0;
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
		print_fail_tab(failTab, max, "Failed at");
}

void	test_ft_to(int (*function)(int), int max)
{
	int		i;
	int		failTab[256] = {0};
	int		result;

	i = 0;
	while (i <= max)
	{
		if (isprint(i))
		{
			result = function(i);
			if (result != i)
				printf("\033[22;32m%c\033[0m", result);
			else
				printf("%c", result);
		}
		else
			failTab[i] = 1;
		i++;
	}
	printf("\n");
	if (max > 127)
		print_fail_tab(failTab, max, "Unchanged");
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

void	test_ft_toupper()
{
	printf("--------------------\n  TEST FT_TOUPPER\n--------------------\n");
	test_ft_to(ft_toupper, 255);
}

void	test_ft_tolower()
{
	printf("--------------------\n  TEST FT_TOLOWER\n--------------------\n");
	test_ft_to(ft_tolower, 255);
}

void	test_ft_puts(char **str, int tabSize)
{
	int		i;

	printf("--------------------\n  TEST FT_PUTS\n--------------------\n");
	i = 0;
	while (i < tabSize)
		ft_puts(str[i++]);
}

void	test_ft_strlen(char **str)
{
	int		i;

	i = 0;
	printf("--------------------\n  TEST FT_STRLEN\n--------------------\n");
	while (i < 9)
	{
		printf("Length of \"%s\": %zu\n", str[i], ft_strlen(str[i]));
		i++;
	}
}

void	test_ft_memset(char **str, int c)
{
	char	*s;
	size_t	n[] = { 0, 3};
	int		i;

	i = 0;
	printf("--------------------\n  TEST FT_MEMSET\n--------------------\n");
	printf("Test on the string \"%s\"\n", str[0]);
	while (i < 2)
	{
		s = strdup(str[0]);
		s = (char *)ft_memset((void *)s, c, n[i]);
		printf("   case: n = %zu, c = %c | result: %s\n", n[i], c, s);
		free(s);
		i++;
	}
}

void	test_ft_memcpy(char **str)
{
	char	*s;
	size_t	n[] = { 0, 3, 10};
	int		i;

	i = 0;
	printf("--------------------\n  TEST FT_MEMCPY\n--------------------\n");
	printf("Test with \"%s\" and \"%s\"\n", str[0], str[1]);
	while (i < 3)
	{
		s = strdup(str[0]);
		s = (char *)ft_memcpy((void *)s, (void *)str[1], n[i]);
		printf("   case: n = %zu | result: %s\n", n[i], s);
		free(s);
		i++;
	}
}

void	test_ft_strdup(char **str)
{
	size_t	n[] = { 0, 3, 5 };
	char	*s;
	int		i;

	i = 0;
	printf("--------------------\n  TEST FT_STRDUP\n--------------------\n");
	while (i < 3)
	{
		s = ft_strdup(str[n[i]]);
		printf("Test with \"%s\": %p %s\n", str[n[i]], s, s);
		free(s);
		s = NULL;
		i++;
	}
}

void	test_ft_cat()
{
	printf("--------------------\n  TEST FT_CAT\n--------------------\n");
	printf("Test with fd = -1:\n");
	ft_cat(-1);
	printf("Test with a file:\n");
	ft_cat(open("./textfile/file1", O_RDONLY));
	printf("Test with an empty file:\n");
	ft_cat(open("./textfile/emptyFile", O_RDONLY));
	printf("Test with standard input:\n");
	ft_cat(0);
	ft_cat(open("./test", O_RDONLY));
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
						"abc123$!?" };

	test_ft_bzero(str);
	test_ft_strcat(str);
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_puts(str, 9);
	test_ft_strlen(str);
	test_ft_memset(str, 'a');
	test_ft_memcpy(str);
	test_ft_strdup(str);
	test_ft_cat();
	return(0);
}
