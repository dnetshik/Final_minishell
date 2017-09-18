/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:22:42 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 09:40:41 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			get_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
	return (0);
}

int			get_environ(char **av, char **environ)
{
	int		index;

	index = -1;
	while (environ[++index])
	{
		if (ft_strncmp(&av[1][1], environ[index], ft_strlen(&av[1][1]))
				== 0 && environ[index][ft_strlen(&av[1][1])] == '=')
		{
			ft_putendl(&environ[index][ft_strlen(&av[1][1]) + 1]);
		}
	}
	return (0);
}

void		echo_func(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] != '"') && (av[i][j] != '\''))
				ft_putchar(av[i][j]);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
