/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:27:10 by dnetshik          #+#    #+#             */
/*   Updated: 2017/12/22 11:41:30 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char		*setup_root(char *home, char *str)
{
	char	*temp;
	char	*path;

	if (!str)
		return (ft_strdup(home));
	temp = ft_strjoin(home, "/");
	path = ft_strjoin(temp, str);
	free(temp);
	return (path);
}

char		*tilder(char **env, char *str)
{
	int		i;
	char	**array;
	char	*ret;
	char	*temp;
	char	*temp2;

	i = 0;
	while (env[i])
	{
		array = ft_strsplit(env[i], '=');
		if (ft_strcmp(array[0], "HOME") == 0)
		{
			temp = setup_root(array[1], NULL);
			temp2 = setup_root(array[1], str);
			ret = str == NULL ? ft_strdup(temp) : ft_strdup(temp2);
			free(temp);
			free(temp2);
			if (array)
				array = free_args(array);
			return (ret);
		}
		array = free_args(array);
		i++;
	}
	return (NULL);
}

char		*change_tilder(char *env)
{
	extern char	**environ;
	char		*whereto;
	char		**br;

	br = ft_strsplit(env, '/');
	if (br)
		whereto = tilder(environ, br[1]);
	else
		whereto = tilder(environ, NULL);
	ft_putendl(whereto);
	if (br)
		br = free_args(br);
	return (whereto);
}
