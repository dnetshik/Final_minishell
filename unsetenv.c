/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:21:10 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 13:19:05 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			ret_i(char **env, char *key)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if ((ft_strncmp(key, env[i], ft_strlen(key)) == 0)
				&& (env[i][ft_strlen(key)] == '='))
			j++;
		i++;
	}
	if (!j)
		return (-1);
	return (i);
}

char		**ft_unsetenv(char **env, char *key)
{
	int		i;
	int		j;
	char	**ret;

	i = ret_i(env, key);
	if (i == -1)
		return (env);
	ret = (char **)malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (env[i])
	{
		if ((ft_strncmp(key, env[i], ft_strlen(key)) == 0) &&
				(env[i][ft_strlen(key)] == '='))
			free(env[i++]);
		else
		{
			ret[j] = env[i];
			i++;
			j++;
		}
	}
	free(env);
	ret[j] = NULL;
	return (ret);
}
