# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define CODE_HEAD	4

char			*make_string(char *buf, const int x, const int name_only)
{
	const char	*sully	= (char[7]){'S', 'u', 'l', 'l', 'y', '_', 0};
	const char	*dotc	= (char[3]){'.', 'c', 0};
	const char	*clang	= (char[7]){'c', 'l', 'a', 'n', 'g', ' ', 0};
	const char	*flags	= (char[5]){' ','-','o',' ', 0};
	const char	*andrun	= (char[6]){'&', '&' ,' ' ,'.' ,'/' , 0};
	const char	*fmt	= (char[7]){'%', 's', '%', 'd', '%', 's', 0};
	const char	*fmt2	= (char[21]){'%', 's', '%', 's', '%', 'd', '%', 's', '%', 's', '%', 's', '%', 'd', '%', 's', '%', 's', '%', 'd', 0};

	if (name_only)
		sprintf(buf, fmt, sully, x, dotc);
	else
		sprintf(buf, fmt2, clang, sully, x, dotc, flags, sully, x, andrun, sully, x);
	return (buf);
}

void			replicate(char **code, const unsigned int x)
{
	char		buf[64];
	const int	fd			= open(make_string(buf, x - 1, 1), O_CREAT | O_WRONLY | O_TRUNC, 0600);
	const char	*line		= code[0];
	const char	*quoted		= code[1];
	const char	*variable_x	= code[2];
	int			i;

	i = CODE_HEAD;
	while (++i < 53 + CODE_HEAD)
		dprintf(fd, line, code[i], 10);//code lines beginning
	dprintf(fd, variable_x, (x - 1), 10);//setting X
	dprintf(fd, line, code[i], 10);//two more lines
	dprintf(fd, line, code[++i], 10);
	i = -1;
	while (++i < 67)
		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code
	dprintf(fd, code[3], 9, 9, code[4], 10);//the NULL line
	i = 54 + CODE_HEAD;
	while (++i < 67)
		dprintf(fd, line, code[i], 10);//code lines end
	close(fd);
	system(make_string(buf, x - 1, 0));
}

int				main(void)
{
	int			X = 5;
	char		*code[] =
	{
		"%s%c",
		"%c%c%c%s%c%c%c",
		"	int			X = %d;%c",
		"%c%c%s%c",
		"NULL",
		"# include <stdio.h>",
		"# include <fcntl.h>",
		"# include <unistd.h>",
		"# include <stdlib.h>",
		"# include <string.h>",
		"# define CODE_HEAD	4",
		"",
		"char			*make_string(char *buf, const int x, const int name_only)",
		"{",
		"	const char	*sully	= (char[7]){'S', 'u', 'l', 'l', 'y', '_', 0};",
		"	const char	*dotc	= (char[3]){'.', 'c', 0};",
		"	const char	*clang	= (char[7]){'c', 'l', 'a', 'n', 'g', ' ', 0};",
		"	const char	*flags	= (char[5]){' ','-','o',' ', 0};",
		"	const char	*andrun	= (char[6]){'&', '&' ,' ' ,'.' ,'/' , 0};",
		"	const char	*fmt	= (char[7]){'%', 's', '%', 'd', '%', 's', 0};",
		"	const char	*fmt2	= (char[21]){'%', 's', '%', 's', '%', 'd', '%', 's', '%', 's', '%', 's', '%', 'd', '%', 's', '%', 's', '%', 'd', 0};",
		"",
		"	if (name_only)",
		"		sprintf(buf, fmt, sully, x, dotc);",
		"	else",
		"		sprintf(buf, fmt2, clang, sully, x, dotc, flags, sully, x, andrun, sully, x);",
		"	return (buf);",
		"}",
		"",
		"void			replicate(char **code, const unsigned int x)",
		"{",
		"	char		buf[64];",
		"	const int	fd			= open(make_string(buf, x - 1, 1), O_CREAT | O_WRONLY | O_TRUNC, 0600);",
		"	const char	*line		= code[0];",
		"	const char	*quoted		= code[1];",
		"	const char	*variable_x	= code[2];",
		"	int			i;",
		"",
		"	i = CODE_HEAD;",
		"	while (++i < 53 + CODE_HEAD)",
		"		dprintf(fd, line, code[i], 10);//code lines beginning",
		"	dprintf(fd, variable_x, (x - 1), 10);//setting X",
		"	dprintf(fd, line, code[i], 10);//two more lines",
		"	dprintf(fd, line, code[++i], 10);",
		"	i = -1;",
		"	while (++i < 67)",
		"		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code",
		"	dprintf(fd, code[3], 9, 9, code[4], 10);//the NULL line",
		"	i = 54 + CODE_HEAD;",
		"	while (++i < 67)",
		"		dprintf(fd, line, code[i], 10);//code lines end",
		"	close(fd);",
		"	system(make_string(buf, x - 1, 0));",
		"}",
		"",
		"int				main(void)",
		"{",
		"	char		*code[] =",
		"	{",
		"	};",
		"",
		"	if (X > 0 && strstr(__FILE__, (char[8]){'S','u','l','l','y','.','c',0}))",
		"		replicate(code, X + 1);",
		"	else if (X > 0)",
		"		replicate(code, X);",
		"	return (0);",
		"}",
		NULL
	};

	if (X > 0 && strstr(__FILE__, (char[8]){'S','u','l','l','y','.','c',0}))
		replicate(code, X + 1);
	else if (X > 0)
		replicate(code, X);
	return (0);
}
