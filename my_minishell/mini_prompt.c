/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:24:40 by dnetshik          #+#    #+#             */
/*   Updated: 2017/09/13 13:27:43 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

int			prompt(char ***env)
{
    struct  paths   val;

	val.r = read(0, val.line, 4096);
	val.line[val.r - 1] = '\0';
    if (ft_strlen(val.line))
    {
	     val.args = ft_strsplit(val.line, ' ');
	    if (ft_strcmp(val.args[0], "exit") == 0)
		    exit(-1);
	    else if ((ft_strcmp(val.args[0], "echo") == 0) && (val.args[1][0] != '$'))
		    echo_func(val.args);
	    else if ((ft_strcmp(val.args[0], "echo") == 0) && (val.args[1][0] == '$'))
		    get_environ(val.args, *env);
	    else if (ft_strcmp(val.args[0], "env") == 0)
		    get_env(*env);
	    else if (ft_strcmp(val.args[0], "setenv") == 0)
		    *env = setv(*env, val.args[1], val.args[2]);
	    else if (ft_strcmp(val.args[0], "unsetenv") == 0)
		    *env = ft_unsetenv(*env, val.args[1]);
	    else
		    get_path(*env, val.args);
	    free_args(val.args);
    }
    return (1);
}
