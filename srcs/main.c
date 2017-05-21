#include "computor.h"

static int		setenv(t_env *env, int ac, char **av)
{
	env->ac = ac;
	env->av = av;
	env->error = SUCCESS;
	return (SUCCESS);
}

t_env			*singleton(void)
{
	static t_env sglt;

	return (&sglt);
}

int				main(int ac, char **av)
{
	t_env		*env;

	env = singleton();
	setenv(env, ac, av);
	parser(env);
	errors(env);
	return (env->error);
}