#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft.h"
# include "ft_printf.h"
# include "error.h"

/*
** Enums
*/

typedef enum			s_enum_errors
{
	PARSER = 1,
	EQUALS = 2
}						t_enum_errors;

typedef enum			s_enum_debug
{
	DEBUG = 3,
	DEBUG_ENV = 1,
	DEBUG_POLYNOME = 2
}						t_enum_debug;

/*
** Struct
*/

typedef struct			s_term
{
	int					c;
	int					p;
}						t_term;

typedef struct			s_polynome
{
	t_list				*list;
}						t_polynome;

typedef struct			s_env
{
	int					ac;
	char				**av;
	int					error;
	t_polynome			left;
	t_polynome			right;
	t_polynome			reduct;
}						t_env;

t_env					*singleton(void);
int						errors(t_env *);
int						debug(int what);
int						parser(t_env *env);
int						display(void);

#endif