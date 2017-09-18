/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:21:10 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 09:42:57 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int          ret_i(char **env, char *key)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (env[i])
    {
        if ((ft_strncmp(key, env[i], ft_strlen(key)) == 0) &&
                (env[i][ft_strlen(key)] == '='))
            j++;
        i++;
    }
    if (!j)
        return (-1);
    return (i);
}

char	**ft_unsetenv(char **env, char *key)
{
	int i;
	int j;
	char **ret;

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
			i++;
		else
		{
			ret[j] = ft_strdup(env[i]);
			i++;
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}


