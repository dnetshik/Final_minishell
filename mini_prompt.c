/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:24:40 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 15:21:55 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void	exec_cd(char *dir, int old_pwd_bool)
{
	char	*oldpwd;

	oldpwd = get_env("OLDPWD");
	if (!chdir(dir))
	{
		if (old_pwd_bool)
			ft_putendl(oldpwd);
	}
	else
	{
		ft_putstr("cd :");
		if (access(dir, F_OK))
			ft_putstr(" no such file or directory: ");
		else if (access(dir, R_OK))
			ft_putstr(" permission denied: ");
		else
			ft_putstr(" not a directory");
		ft_putstr(dir);
		ft_putchar('\n');
	}
	if (dir)
		free(dir);
	if (oldpwd)
		free(oldpwd);
}

int		exec_command_cd(char **dir)
{
	char	*home;
	char	*temp;

	home = get_env("HOME");
	if (dir[1] && dir[2])
		ft_putendl("cd : too many arguments");
	else if (!dir[1] || dir[1][0] == '~')
	{
		ft_free(home);
		exec_cd((home = change_tilder(dir[1])), 0);
		return (1);
	}
	else if (dir[1][0] == '-')
	{
		ft_free(home);
		exec_cd((home = get_env("OLDPWD")), 1);
		home = NULL;
		return (1);
	}
	else
		exec_cd((temp = ft_strdup(dir[1])), 0);
	ft_free(home);
	return (1);
}

int		prompt(char ***env)
{
	t_paths	val;

	init_paths(&val);
	val.args = NULL;
	if (ft_strlen(val.line))
	{
		val.args = ft_strsplit(val.line, ' ');
		if (ft_strcmp(val.args[0], "exit") == 0)
			exit(-1);
		else if (ft_strequ("echo", val.args[0]) == 1)
			echo_preparation(val.args, *env);
		else if (ft_strcmp(val.args[0], "env") == 0)
			print_env(*env);
		else if (ft_strcmp(val.args[0], "setenv") == 0)
			*env = setv(*env, val.args[1], val.args[2]);
		else if (ft_strcmp(val.args[0], "unsetenv") == 0)
			*env = ft_unsetenv(*env, val.args[1]);
		else if (ft_strequ(val.args[0], "cd"))
			exec_command_cd(val.args);
		else
			get_path(*env, val.args);
		val.args = free_args(val.args);
	}
	return (1);
}
