# define CODE \
	char *code[] =\
	{\
		"Grace_kid.c",\
		"		NULL,",\
		"		NULL",\
		"%s%c%c",\
		"%c%c%c%s%c,%c%c",\
		"%s%c",\
		"# define CODE ",\
		"	char *code[] =",\
		"	{",\
		NULL,\
		"	};",\
		"	",\
		"	char	**str = (void *)code;",\
		"	char	**str_quoted = str;",\
		"	char	*filename = *str++;",\
		"	char	*null = *str++;",\
		"	char	*null2 = *str++;",\
		"	char	*a = *str++;",\
		"	char	*b = *str++;",\
		"	char	*c = *str++;",\
		"	",\
		"	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);",\
		"	",\
		"	while (*str)",\
		"	{",\
		"		dprintf(fd, a, *str, BACKSLASH, 10);",\
		"		str++;",\
		"	}",\
		"	while (*str_quoted)",\
		"	{",\
		"		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);",\
		"		str_quoted++;",\
		"	}",\
		"	dprintf(fd, a, null, BACKSLASH, 10);",\
		"	str_quoted++;",\
		"	while (*str_quoted)",\
		"	{",\
		"		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);",\
		"		str_quoted++;",\
		"	}",\
		"	dprintf(fd, a, null, BACKSLASH, 10);",\
		"	str_quoted++;",\
		"	while (*str_quoted)",\
		"	{",\
		"		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);",\
		"		str_quoted++;",\
		"	}",\
		"	dprintf(fd, a, null2, BACKSLASH, 10);",\
		"	str++;",\
		"	while (*str)",\
		"	{",\
		"		dprintf(fd, a, *str, BACKSLASH, 10);",\
		"		str++;",\
		"	}",\
		"	str++;",\
		"	while (*str)",\
		"	{",\
		"		dprintf(fd, c, *str, 10);",\
		"		str++;",\
		"	}",\
		NULL,\
		"	close(fd);",\
		"",\
		"/*",\
		"	This is trully UGLY...",\
		"*/",\
		"",\
		"# include <stdio.h>",\
		"# include <fcntl.h>",\
		"# include <unistd.h>",\
		"",\
		"# define BACKSLASH	92",\
		"# define RUN(x) int main(){x}",\
		"",\
		"RUN(CODE)",\
		NULL\
	};\
	\
	char	**str = (void *)code;\
	char	**str_quoted = str;\
	char	*filename = *str++;\
	char	*null = *str++;\
	char	*null2 = *str++;\
	char	*a = *str++;\
	char	*b = *str++;\
	char	*c = *str++;\
	\
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);\
	\
	while (*str)\
	{\
		dprintf(fd, a, *str, BACKSLASH, 10);\
		str++;\
	}\
	while (*str_quoted)\
	{\
		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);\
		str_quoted++;\
	}\
	dprintf(fd, a, null, BACKSLASH, 10);\
	str_quoted++;\
	while (*str_quoted)\
	{\
		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);\
		str_quoted++;\
	}\
	dprintf(fd, a, null, BACKSLASH, 10);\
	str_quoted++;\
	while (*str_quoted)\
	{\
		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, BACKSLASH, 10);\
		str_quoted++;\
	}\
	dprintf(fd, a, null2, BACKSLASH, 10);\
	str++;\
	while (*str)\
	{\
		dprintf(fd, a, *str, BACKSLASH, 10);\
		str++;\
	}\
	str++;\
	while (*str)\
	{\
		dprintf(fd, c, *str, 10);\
		str++;\
	}\
	close(fd);

/*
	This is trully UGLY...
*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define BACKSLASH	92
# define RUN(x) int main(){x}

RUN(CODE)
