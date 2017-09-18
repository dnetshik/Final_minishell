/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:34:13 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/18 13:29:17 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void		ft_exec(char *prog, char **args, char **env)
{
	pid_t	k;

	k = fork();
	if (k == 0)
	{
		if (prog == NULL)
			printf("error\n");
		else
			execve(prog, args, env);
	}
	wait(NULL);
}

void       func(char *temp, char **s, char **args, char **env)
{
    char *prog;
    int i;

    i = 0;
    prog = NULL;
    while(s[i])
    {
        temp = ft_strjoin(s[i], "/");
        temp = ft_strjoin(temp, args[0]);
        //if (ft_strcmp(s[i], args[0]))
          //  temp = ft_strdup(args[0]);
        if(access(temp, X_OK) == 0)
            prog = ft_strdup(temp);
        i++;
    }
    ft_exec(prog, args, env);
}

void		get_path(char **env, char **args)
{
    struct  paths   val;

	val.i = 0;
	val.path = NULL;
	while (env[val.i])
	{
		if (ft_strncmp("PATH=", env[val.i], 5) == 0)
			val.path = ft_strdup(env[val.i]);
		val.i++;
	}
	if (val.path == NULL)
	{
		if (access(args[0], X_OK) == 0)
			ft_exec(args[0], args, env);
		else
			printf("minishell: command not found: %s\n", args[0]);
		return ;
	}
	val.path = ft_strdup(ft_strchr(val.path, '/'));
	val.s = ft_strsplit(val.path, ':');
    func(val.tmp, val.s, args, env);
}
