/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:20:20 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/13 16:59:54 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	if (!s)
		return (NULL);
	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *)(s + index));
		index--;
	}
	return (NULL);
}
