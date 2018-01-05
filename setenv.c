/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:21:59 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 15:23:07 by dnetshik         ###   ########.fr       */
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
	f1 = temp;
	temp = ft_strjoin(temp, value);
	free(f1);
	i = 0;
	while (name_env[i])
		i++;
	temp1 = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (name_env[i])
	{
		temp1[i] = name_env[i];
		i++;
	}
	temp1[i] = temp;
	i++;
	temp1[i] = NULL;
	free(name_env);
	return (temp1);
}
