/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergfel <jbergfel@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:38:59 by jbergfel          #+#    #+#             */
/*   Updated: 2023/11/07 16:10:28 by jbergfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		lens1;
	int		lens2;
	char	*str;

	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(lens1 + lens2 + 1);
	if (s1 == 0 && s2 == 0)
		return (0);
	if (!str)
		return (0);
	while (i < lens1 || i < lens2)
	{
		if (i < lens1)
			str[i] = s1[i];
		if (i < lens2)
			str[i + lens1] = s2[i];
		i++;
	}
	str[lens1 + lens2] = '\0';
	return (str);
}
