# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define CODE_HEAD	4

void			replicate(char **code, const int x)
{
	const int	fd			= open((char[10]){'S', 'u', 'l', 'l', 'y', '_', (48 + x - 1), '.', 'c', 0}, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	const char	*line		= code[0];
	const char	*quoted		= code[1];
	const char	*variable_x	= code[2];
	int			i;

	i = CODE_HEAD;
	while (++i < 37 + CODE_HEAD)
		dprintf(fd, line, code[i], 10);//code lines beginning
	dprintf(fd, variable_x, (x - 1), 10);//setting X
	dprintf(fd, line, code[i], 10);//two more lines
	dprintf(fd, line, code[++i], 10);
	i = -1;
	while (++i < 51)
		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code
	dprintf(fd, code[3], 9, 9, code[4], 10);//the NULL line
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
		"void			replicate(char **code, const int x)",
		"{",
		"	const int	fd			= open((char[10]){'S', 'u', 'l', 'l', 'y', '_', (48 + x - 1), '.', 'c', 0}, O_CREAT | O_WRONLY | O_TRUNC, 0600);",
		"	const char	*line		= code[0];",
		"	const char	*quoted		= code[1];",
		"	const char	*variable_x	= code[2];",
		"	int			i;",
		"",
		"	i = CODE_HEAD;",
		"	while (++i < 37 + CODE_HEAD)",
		"		dprintf(fd, line, code[i], 10);//code lines beginning",
		"	dprintf(fd, variable_x, (x - 1), 10);//setting X",
		"	dprintf(fd, line, code[i], 10);//two more lines",
		"	dprintf(fd, line, code[++i], 10);",
		"	i = -1;",
		"	while (++i < 51)",
		"		dprintf(fd, quoted, 9, 9, 34, code[i], 34, 44, 10);//quoted code",
		"	dprintf(fd, code[3], 9, 9, code[4], 10);//the NULL line",
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
