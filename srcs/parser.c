#include "computor.h"

static int	parser_usage(char *msg)
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

static int	parser_term(t_env *env, int i, t_polynome *p)
{
	t_term	t;
	t_list	*l;

	if (ft_strequ("-", env->av[i]) || ft_strequ("+", env->av[i]))
		parser_usage(env->av[i]);
	if (env->av[i][0] == '+' || env->av[i][0] == '-'
		|| ft_isdigit(env->av[i][0]))
	{
		t.c = ft_atoi(env->av[i]);
		PUTSTR(env->av[i]);
		if (ft_strcmp("*", env->av[i++]))
			parser_usage(env->av[--i]);
		if (ft_strncmp("X^", env->av[i++], 2))
			parser_usage(env->av[--i]);
		if ((t.p = ft_atoi(env->av[i])) < 0)
			parser_usage(env->av[i]);
	}
	l = ft_lstnew(&t, sizeof(t));
	ft_lstadd(&p->list, l);
	return (SUCCESS);
}

static int	parser_left(t_env *env)
{
	int		i;

	i = 1;
	while (i < env->ac)
	{
		parser_term(env, i, &env->left);
		i += 3;
		if (ft_strequ(env->av[i], "="))
			return (i);
	}
	return (SUCCESS);
}

static int	parser_right(t_env *env, int i)
{
	if (i == SUCCESS)
		parser_usage("=");
	while (i < env->ac)
	{
		parser_term(env, i, &env->right);
		i += 3;
	}
	return (SUCCESS);
}

int			parser(t_env *env)
{
	int		ret;

	if (ERROR)
		return (FAIL);
	ret = parser_left(env);
	parser_right(env, ret);
	debug(DEBUG_POLYNOME);
	return (SUCCESS);
}