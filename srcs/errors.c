#include "computor.h"

static t_dict_error g_errors[] =
{
	{PARSER, "Too much arguments!"},
	{0, 0}
};

int			errors(t_env *env)
{
	if (ERROR)
		debug(DEBUG);
	env->error = CATCH(g_errors);
	return (SUCCESS);
}