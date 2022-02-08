#include "baml.h"

char	**valid_arg(char *arg)
{
	char	**format;

	format = (char **) malloc(sizeof(char *) * 4);

	if (strncmp("--", arg, 2) || !strcmp("--bash", arg))
	{
		format[0] = strdup("=(");
		format[1] = strdup(" ");
		format[2] = strdup("\'");
		format[3] = strdup(")");
		return (format);
	}
	else if (!strcmp("--python", arg) || !strcmp("--ruby", arg))
	{
		format[0] = strdup(" = [");
		format[1] = strdup(", ");
		format[2] = strdup("\"");
		format[3] = strdup("]");
		return (format);
	}
	else
	{
		free(format);
		return (NULL);
	}

}

size_t	valid_token(char *store)
{
	size_t offset = 0;

	while (store[offset] == ' ' || store[offset] == '\t')
		offset++;
	if (!strncmp(&store[offset], ENTRYTOKEN, 2))
		return (offset + 2);
	return (0);
}

void	pitem(char *istr)
{
	size_t			isize = strlen(istr);
	size_t			scan = 0;
	size_t			checkp = 0;
	size_t			trimmer = 0;
	unsigned char	memory = 0;

	while (scan < isize)
	{
		if (istr[scan] > 32 )
			trimmer = scan;
		if (istr[scan] == '\'' || istr[scan] == '\"' || istr[scan] == '`')
		{
			memory = istr[scan];
			istr[scan] = 0;
			printf("%s\\%c", &istr[checkp], memory);
			istr[scan] = memory;
			checkp = ++scan;
			continue ;
		}
		scan++;
	}
	istr[trimmer + 1]  = 0;
	if (memory == 0)
		printf("%s", istr);
	else if (scan != checkp)
		printf("%s", &istr[checkp]);
}

void	pheader(char *hstr, char **format, char *hopen)
{
	size_t	scan;

	while (*hstr && (*hstr == ' ' || *hstr == '\t'))
		hstr++;
	scan = 0;
	while (hstr[scan])
	{
		if (hstr[scan] == ';')
		{
			hstr[scan] = 0;
			break ;
		}
		scan++;
	}
	if (*hopen)
		printf("%s\n", format[3]);
	pitem(hstr);
	printf("%s", format[0]);
	*hopen = 1;
}

void	pentry(char *estr, char **format, char *hopen)
{
	size_t	scan;

	while (*estr && (*estr == ' ' || *estr == '\t'))
		estr++;
	scan = 0;
	while (estr[scan])
	{
		if (estr[scan] == '\n')
		{
			estr[scan] = 0;
			break ;
		}
		scan++;
	}
	if(*hopen == 2)
		printf("%s", format[1]);
	else
		*hopen = 2;
	printf("%s", format[2]);
	pitem(estr);
	printf("%s", format[2]);
}

size_t	dstr(char *base, char *tail)
{
	size_t	blen = strlen(base);
	size_t	tlen = strlen(tail);

	base = realloc(base, sizeof(char) * (blen + tlen + 1));
	for (size_t i = blen; i < blen + tlen; i++)
	{
		base[i] = *tail;
		tail++;
	}
	base[blen + tlen] = 0;
	return (blen + tlen);
}
