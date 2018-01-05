/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:02:09 by dnetshik          #+#    #+#             */
/*   Updated: 2017/12/22 13:17:28 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

void		init_paths(t_paths *val)
{
	char	*temp;

	val->r = read(0, val->line, 4096);
	val->line[val->r - 1] = '\0';
	temp = ft_strtrim(val->line);
	ft_strcpy(val->line, temp);
	free(temp);
}
