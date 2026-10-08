/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:20:16 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/13 19:47:04 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		ii;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			ii = 0;
			while (needle[ii] && haystack[i + ii] && i + ii < len
				&& haystack[i + ii] == needle[ii])
				ii++;
			if (needle[ii] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
