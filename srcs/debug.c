#include "computor.h"

static void	debug_term(t_list *l)
{
	t_term	*t;

	t = (t_term *)l->content;
	ft_printf("%d * X^%d ", t->c, t->p);
}

static int	debug_polynomes(t_env *env)
{
	ft_printf("{c:1}Polynomes:{e}\n");
	ft_lstiter(env->left.list, debug_term);
	ft_printf("=");
	ft_lstiter(env->right.list, debug_term);
	ft_printf("\n");
	return (SUCCESS);
}

static int	debug_env(t_env *env)
{
	int		i;

	ft_printf("{c:1}Environement:\n{e}");
	ft_printf("{c}%-10s%d{e}\n", "AC:", env->ac);
	i = 0;
	ft_printf("{c}%-10s{e}\n", "AV:");
	while (++i < env->ac)
		ft_printf("{c}-AV[%d]:\t%s{e}\n",i, env->av[i]);
	ft_printf("{c}%-10s%d{e}\n", "ERROR:", env->error);
	return (SUCCESS);
}

int			debug(int action)
{
	t_env	*env;

	env = singleton();
	ft_printf("{p:1:%s}\n", "Debug infos:");
	if (action & DEBUG_ENV)
		debug_env(env);
	if (action & DEBUG_POLYNOME)
		debug_polynomes(env);
	return (SUCCESS);
}