#include <stdio.h> 
#include <unistd.h> 

#define MAXLINE 1000	/* maximum input line size */ 

int max; 				/* maximum length seen so far */ 
char line[MAXLINE]; 	/* currennt input line */ 
char longest[MAXLINE];	/* longest line saved here */ 

int get_line(); 
void copy(); 





/* print logest input line; specialized version */ 
main()
{
	int i, len; 
	extern int max; 
	extern char longest[]; 

	max = 0; 
	while ((len = get_line()) > 0) 
	{
		if (len > max)
		{
			max = len; 
			copy(); 
		}
	}
	if (max > 0)	/* there was a line */ 
	{
		printf("\nAnd the longest line is"); 
		for (i = 0; i < 3; ++i)
		{
			sleep(1); 
			printf("."); 
			fflush(stdout); 
		}
			printf("%s \nWow! Now that's a whopper!\n", longest);
	}
	else 
	{
		printf("What?! No line!!\n"); 
	}
	return 0; 
}



/* getline: specialized version */ 
int get_line()
{
	int c, i; 
	extern char line[]; 

	for (i = 0; i < MAXLINE-1 && (c=getchar())!=EOF && c !='\n'; ++i)
	{
		line[i] = c; 
	}
	if (c == '\n')
	{
		line[i] = c; 
		++i; 
	}
	line[i] = '\0'; 
	return i; 
}

/* copy: specialized version */ 
void copy()
{
	int i; 
	extern char line[], longest[]; 

	i = 0; 
	while ((longest[i] = line[i]) != '\0')
	{
		++i; 
	}
}