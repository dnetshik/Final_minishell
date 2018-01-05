/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 10:15:43 by dnetshik          #+#    #+#             */
/*   Updated: 2017/12/22 11:17:08 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = NULL;
	if (s != NULL)
	{
		str = (char *)s;
		while (*str != c)
		{
			if (*str == '\0')
			{
				return (NULL);
			}
			str++;
		}
	}
	return (str);
}
