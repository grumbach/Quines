# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define CODE_HEAD	6

void			replicate(char **code, const int x)
{
	const int	fd			= open(code[0], O_CREAT | O_WRONLY | O_TRUNC, 0600);
	const char	*line		= code[2];
	const char	*quoted		= code[3];
	const char	*variable_x	= code[4];
	int			i;

	i = CODE_HEAD;
	while (++i < 37 + CODE_HEAD)
		dprintf(fd, line, code[i], 10);//code lines beginning
	dprintf(fd, variable_x, (x - 1), 10);//setting X
	dprintf(fd, line, code[i], 10);//two more lines
	dprintf(fd, line, code[++i], 10);
	dprintf(fd, code[5], 9, 9, code[1], 10);//the ()char[10] line
	i = 0;
	while (++i < 51)
		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code
	dprintf(fd, code[5], 9, 9, code[6], 10);//the NULL line
	i = 38 + CODE_HEAD;
	while (++i < 51)
		dprintf(fd, line, code[i], 10);//code lines end
	close(fd);
	system((char[27]){'c','l','a','n','g',' ','S','u','l','l','y','_',47 + x,
		'.','c',' ','-','o',' ','S','u','l','l','y','_',47 + x,0});
	system((char[10]){'.','/','S','u','l','l','y','_',47 + x,0});
}

int				main(void)
{
	int			X = 5;
	char		*code[] =
	{
		(char[10]){'S', 'u', 'l', 'l', 'y', '_', (48 + X - 1), '.', 'c', 0},
		"(char[10]){'S', 'u', 'l', 'l', 'y', '_', (48 + X - 1), '.', 'c', 0},",
		"%s%c",
		"%c%c%c%s%c%c%c",
		"	int			X = %d;%c",
		"%c%c%s%c",
		"NULL",
		"# include <stdio.h>",
		"# include <fcntl.h>",
		"# include <unistd.h>",
		"# include <stdlib.h>",
		"# define CODE_HEAD	6",
		"",
		"void			replicate(char **code, const int x)",
		"{",
		"	const int	fd			= open(code[0], O_CREAT | O_WRONLY | O_TRUNC, 0600);",
		"	const char	*line		= code[2];",
		"	const char	*quoted		= code[3];",
		"	const char	*variable_x	= code[4];",
		"	int			i;",
		"",
		"	i = CODE_HEAD;",
		"	while (++i < 37 + CODE_HEAD)",
		"		dprintf(fd, line, code[i], 10);//code lines beginning",
		"	dprintf(fd, variable_x, (x - 1), 10);//setting X",
		"	dprintf(fd, line, code[i], 10);//two more lines",
		"	dprintf(fd, line, code[++i], 10);",
		"	dprintf(fd, code[5], 9, 9, code[1], 10);//the ()char[10] line",
		"	i = 0;",
		"	while (++i < 51)",
		"		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code",
		"	dprintf(fd, code[5], 9, 9, code[6], 10);//the NULL line",
		"	i = 38 + CODE_HEAD;",
		"	while (++i < 51)",
		"		dprintf(fd, line, code[i], 10);//code lines end",
		"	close(fd);",
		"	system((char[27]){'c','l','a','n','g',' ','S','u','l','l','y','_',47 + x,",
		"		'.','c',' ','-','o',' ','S','u','l','l','y','_',47 + x,0});",
		"	system((char[10]){'.','/','S','u','l','l','y','_',47 + x,0});",
		"}",
		"",
		"int				main(void)",
		"{",
		"	char		*code[] =",
		"	{",
		"	};",
		"",
		"	if (X)",
		"		replicate(code, X);",
		"	return (0);",
		"}",
		NULL
	};

	if (X)
		replicate(code, X);
	return (0);
}
