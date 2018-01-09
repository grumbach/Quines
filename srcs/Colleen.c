/*
	Comment outside
*/
# include <stdio.h>

void		other_func(char **str)
{
	char	**str_quoted = str;
	char	*null = *str++;
	char	*null2 = *str++;
	char	*a = *str++;
	char	*b = *str++;

	while (*str)
	{
		printf(a, *str, 10);
		str++;
	}
	while (*str_quoted)
	{
		printf(b, 9, 9, 34, *str_quoted, 34, 10);
		str_quoted++;
	}
	str_quoted++;
	puts(null);
	while (*str_quoted)
	{
		printf(b, 9, 9, 34, *str_quoted, 34, 10);
		str_quoted++;
	}
	puts(null2);
	str++;
	while (*str)
	{
		printf(a, *str, 10);
		str++;
	}
}

int			main()
{
	char	*str[] =
	{
		"		NULL,",
		"		NULL",
		"%s%c",
		"%c%c%c%s%c,%c",
		"/*",
		"	Comment outside",
		"*/",
		"# include <stdio.h>",
		"",
		"void		other_func(char **str)",
		"{",
		"	char	**str_quoted = str;",
		"	char	*null = *str++;",
		"	char	*null2 = *str++;",
		"	char	*a = *str++;",
		"	char	*b = *str++;",
		"",
		"	while (*str)",
		"	{",
		"		printf(a, *str, 10);",
		"		str++;",
		"	}",
		"	while (*str_quoted)",
		"	{",
		"		printf(b, 9, 9, 34, *str_quoted, 34, 10);",
		"		str_quoted++;",
		"	}",
		"	str_quoted++;",
		"	puts(null);",
		"	while (*str_quoted)",
		"	{",
		"		printf(b, 9, 9, 34, *str_quoted, 34, 10);",
		"		str_quoted++;",
		"	}",
		"	puts(null2);",
		"	str++;",
		"	while (*str)",
		"	{",
		"		printf(a, *str, 10);",
		"		str++;",
		"	}",
		"}",
		"",
		"int			main()",
		"{",
		"	char	*str[] =",
		"	{",
		NULL,
		"	};",
		"",
		"	/*",
		"		Comment inside",
		"	*/",
		"	other_func(str);",
		"	return (0);",
		"}",
		NULL
	};

	/*
		Comment inside
	*/
	other_func(str);
	return (0);
}
