#include "computor.h"

// static int	parser_usage(void);
// {
// 	t_env		*env;
// 	char		*eq;

// 	eq = "<X^2 * N?> + <X^1 * N?> + <X^0 * N> + N";
// 	ft_printf("USAGE: %s %s = %s\n", env->av[0], eq, eq);
// 	_exit(SUCCESS);
// }

static int	parser_left(t_env *env)
{
	int		i;

	i = 0;
	while (++i < env->ac)
	{
		PUTSTR(env->av[i]);
	}
	return (SUCCESS);
}

int			parser(t_env *env)
{
	if (ERROR)
		return (FAIL);
	parser_left(env);
	return (SUCCESS);
}