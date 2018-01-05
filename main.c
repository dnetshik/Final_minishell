/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:28:29 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 12:13:02 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char	**init_env(char ***head)
{
	extern char		**environ;
	int				len;
	char			**ret;
	int				i;

	len = -1;
	i = -1;
	while (environ[++len])
		len++;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	while (environ[++i])
		ret[i] = ft_strdup(environ[i]);
	ret[i] = NULL;
	*head = ret;
	return (ret);
}

int		main(void)
{
	char	**g_env;

	init_env(&g_env);
	while (1)
	{
		ft_putstr("minishell>>");
		prompt(&g_env);
	}
	free_args(g_env);
	return (1);
}
