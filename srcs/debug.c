#include "computor.h"

static int	debug_polynome(t_polynome *pol)
{
	ft_printf("{c:1}Polynomes:{e}\n");
	ft_printf("{c}%-10s%d{e}\n", "CONSTANT:", pol->constant);
	ft_printf("{c}%-10s%d{e}\n", "DEGRES 0:", pol->zero);
	ft_printf("{c}%-10s%d{e}\n", "DEGRES 1:", pol->first);
	ft_printf("{c}%-10s%d{e}\n", "DEGRES 2:", pol->second);
	return (SUCCESS);
}

static int	debug_polynomes(t_env *env)
{
	debug_polynome(&env->left);
	debug_polynome(&env->right);
	debug_polynome(&env->reduct);
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