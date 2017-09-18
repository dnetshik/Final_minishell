/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:21:59 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 09:42:45 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char		**setv(char **name_env, char *key, char *value)
{
	int		i;
	char	*temp;
	char	**temp1;
	char	*f1;

	temp = ft_strjoin(key, "=");
	free(key);
	f1 = temp;
	temp = ft_strjoin(temp, value);
	free(value);
	free(f1);
	i = 0;
	while (name_env[i])
		i++;
	temp1 = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (name_env[i])
	{
		temp1[i] = ft_strdup(name_env[i]);
		i++;
	}
	temp1[i] = ft_strdup(temp);
	i++;
	temp1[i] = NULL;
	return (temp1);
}
