/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:36:06 by dnetshik          #+#    #+#             */
/*   Updated: 2017/12/22 13:23:25 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct		s_paths
{
	char			*path;
	char			**s;
	int				i;
	char			*tmp;
	char			*prog;
	char			line[4096];
	char			**args;
	int				r;
}					t_paths;

char				**free_args(char **arr);
void				init_paths(t_paths *val);
char				**ft_unsetenv(char **env, char *key);
char				**setv(char **name_env, char *key, char *value);
char				*get_env(char *env);
int					get_environ(char **av, char **environ);
void				echo_preparation(char **args, char **env);
void				echo_func(char **av);
void				ft_free(char *tmp);
int					prompt(char ***env);
char				**init_env();
void				ft_exec(char *prog, char **args, char **env);
void				get_path(char **env, char **args);
int					print_env(char **env);
char				*change_tilder(char *dir);

#endif
