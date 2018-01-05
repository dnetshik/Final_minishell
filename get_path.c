/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:34:13 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 15:11:56 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void		ft_exec(char *prog, char **args, char **env)
{
	pid_t	k;

	if (prog == NULL)
	{
		ft_putendl("command not found");
		return ;
	}
	k = fork();
	if (k == 0)
	{
		execve(prog, args, env);
		free(prog);
		exit(1);
	}
	wait(NULL);
}

void		func(char *temp, char **s, char **args, char **env)
{
	char		*prog;
	int			i;
	char		*temp2;

	i = 0;
	prog = NULL;
	while (s[i])
	{
		temp2 = ft_strjoin(s[i], "/");
		temp = ft_strjoin(temp2, args[0]);
		free(temp2);
		if (access(temp, X_OK) == 0)
		{
			if (prog)
				free(prog);
			prog = ft_strdup(temp);
		}
		i++;
		free(temp);
	}
	s = free_args(s);
	ft_exec(prog, args, env);
	free(prog);
}

void		get_path(char **env, char **args)
{
	t_paths		val;
	char		*temp;

	val.i = -1;
	val.path = NULL;
	while (env[++val.i])
	{
		if (ft_strncmp("PATH=", env[val.i], 5) == 0)
			val.path = ft_strdup(env[val.i]);
	}
	if (ft_strncmp(args[0], "/", 1) == 0
			|| ft_strncmp(args[0], "./", 2) == 0 || val.path == NULL)
	{
		if (access(args[0], X_OK) == 0)
			ft_exec(args[0], args, env);
		else
			ft_putendl("minishell: command not found");
		ft_strdel(&val.path);
		return ;
	}
	temp = ft_strdup(ft_strchr(val.path, '/'));
	ft_strdel(&val.path);
	val.s = ft_strsplit(temp, ':');
	func(val.tmp, val.s, args, env);
	ft_strdel(&temp);
}
