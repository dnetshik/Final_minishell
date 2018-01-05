/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetshik <dnetshik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:31:44 by dnetshik          #+#    #+#             */
/*   Updated: 2017/12/22 08:57:09 by dnetshik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *sc)
{
	size_t		i;
	char		*str;

	i = 0;
	str = NULL;
	if (sc != NULL)
	{
		if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(sc) + 1))))
			return (NULL);
		while (i < ft_strlen(sc))
		{
			str[i] = sc[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
