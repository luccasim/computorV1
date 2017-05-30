#include "computor.h"

static int		parser_usage(char *msg)
{
	t_env		*env;
	char		*eq;

	env = singleton();
	if (msg)
		PERROR(msg);
	eq = "<A * X^N>";
	ft_printf("USAGE: %s %s = %s\n", env->av[0], eq, eq);
	_exit(SUCCESS);
}

static int		parser_term(char **av, int *n, t_polynome *p)
{
	t_term	t;
	int		s;
	int		i;

	s = 1;
	i = *n;
	if (ft_strequ("-", av[i]) || ft_strequ("+", av[i]))
		s = (av[i++][0] == '-') ? -1 : 1;
	if (av[i] == 0)
		parser_usage("Missing A * X^N");
	if (av[i][0] == '+' || av[i][0] == '-'
		|| ft_isdigit(av[i][0]))
	{
		t.c = ft_atoi(av[i++]) * s;
		if ((av[i] == 0) || ft_strcmp("*", av[i++]))
			parser_usage("'*' require");
		if ((av[i] == 0) || ft_strncmp("X^", av[i], 2))
			parser_usage("Wrong format X^N");
		if ((av[i] == 0) || ((t.p = ft_atoi(&av[i][2])) < 0))
			parser_usage("N power not valid");
	}
	ft_lstadd(&p->list, ft_lstnew(&t, sizeof(t)));
	*n = ++i;
	return (SUCCESS);
}

static int		parser_polynome(t_polynome *p, char *str)
{
	int		i;
	int		len;
	char	**s;

	s = ft_strsplit(str, ' ');
	len = ft_strstrlen(s);
	i = 0;
	while (i < len)
		parser_term(s, &i, p);
	ft_strdelsplit(s);
	return (SUCCESS);
}

int				parser(t_env *env)
{
	char	**s;

	if (ERROR)
		return (FAIL);
	if (env->ac != 2)
		parser_usage(0);
	s = ft_strsplit(env->av[1], '=');
	if (ft_strstrlen(s) != 2)
		parser_usage("Equation have more or less 1 '='");
	parser_polynome(&env->left, s[0]);
	ft_strdelsplit(s);
	debug(DEBUG_POLYNOME);
	return (SUCCESS);
}