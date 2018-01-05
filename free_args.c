/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:18:14 by dnetshik          #+#    #+#             */
/*   Updated: 2018/01/05 15:05:34 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char	**free_args(char **arr)
{
	int		i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i])
			ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
