/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:36:06 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 13:10:28 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

struct  paths
{
    char    *path;
    char    **s;
    int     i;
    char    *tmp;
    char    *prog;
    char    line[4096];
    char    **args;
    int     r;
};

int		free_args(char **arr);
char	**ft_unsetenv(char **env, char *key);
char	**setv(char **name_env, char *key, char *value);
int		get_env(char **env);
int		get_environ(char **av, char **environ);
void	echo_func(char **av);
void	ft_free(char *tmp);
int		prompt(char ***env);
char	**init_env();
void	ft_exec(char *prog, char **args, char **env);
void	get_path(char **env, char **args);

#endif
