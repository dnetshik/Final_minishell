/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:22:42 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 15:05:05 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			print_env(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
	return (0);
}

char		*get_env(char *env)
{
	extern char		**environ;
	int				i;
	int				len;

	i = -1;
	len = ft_strlen(env);
	while (environ[++i])
	{
		if (ft_strnequ(env, environ[i], len))
			return (ft_strdup(environ[i] + (len + 1)));
	}
	return (NULL);
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

void		echo_preparation(char **args, char **env)
{
	if (ft_strequ(args[0], "echo") && !args[1])
	{
		ft_putendl("");
		return ;
	}
	if (!ft_strcmp(args[0], "echo") && args[1][0] != '$')
		echo_func(args);
	else if (!ft_strcmp(args[0], "echo") && args[1][0] == '$')
		get_environ(args, env);
}

void		echo_func(char **av)
{
	int		i;
	int		j;

	i = 1;
	if (!av[1])
		ft_putchar('\n');
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
