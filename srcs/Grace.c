# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define USE_ME 0
# define RUN(x) int main(){x}
# define CODE \
	int fd = open("Grace_kid.c", O_CREAT | O_WRONLY);\
	char *code[] =\
	{\
		"Grace_kid.c",\
		"		NULL,",\
		"		NULL",\
		"%s%c%c",\
		"%c%c%c%s%c,%c%c",\
		"# include <stdio.h>",\
		"# include <fcntl.h>",\
		"# include <unistd.h>",\
		"",\
		"# define FILENAME ",\
		"# define RUN(x) int main(){x}",\
		"# define CODE int fd = open(FILENAME, O_CREAT | O_WRONLY);",\
		"	char *code[] =",\
		"	{",\
		NULL,\
		"	};",\
		"	",\
		"	char	**str = (void *)code;",\
		"	char	**str_quoted = str;",\
		"	char	*filename =  str++;",\
		"	char	*null = *str++;",\
		"	char	*null2 = *str++;",\
		"	char	*a = *str++;",\
		"	char	*b = *str++;",\
		"	",\
		"	while (*str)",\
		"	{",\
		"		dprintf(fd, a, *str, 92, 10);",\
		"		str++;",\
		"	}",\
		"	while (*str_quoted)",\
		"	{",\
		"		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, 92, 10);",\
		"		str_quoted++;",\
		"	}",\
		"	str_quoted++;",\
		"	puts(null);",\
		"	while (*str_quoted)",\
		"	{",\
		"		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, 92, 10);",\
		"		str_quoted++;",\
		"	}",\
		"	puts(null2);",\
		"	str++;",\
		"	while (*str)",\
		"	{",\
		"		dprintf(fd, a, *str, 92, 10);",\
		"		str++;",\
		"	}",\
		"	",\
		"	close(fd);",\
		"",\
		"/*",\
		"	This is getting ugly...",\
		"*/",\
		"	",\
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
	\
	(void)filename;\
	\
	while (*str)\
	{\
		dprintf(fd, a, *str, 92, 10);\
		str++;\
	}\
	while (*str_quoted)\
	{\
		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, 92, 10);\
		str_quoted++;\
	}\
	str_quoted++;\
	dprintf(fd, a, null, 92, 10);\
	while (*str_quoted)\
	{\
		dprintf(fd, b, 9, 9, 34, *str_quoted, 34, 92, 10);\
		str_quoted++;\
	}\
	dprintf(fd, a, null2, 92, 10);\
	str++;\
	while (*str)\
	{\
		dprintf(fd, a, *str, 92, 10);\
		str++;\
	}\
	\
	close(fd);

/*
	This is trully UGLY...
*/

RUN(CODE)
