/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:20:24 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/03 17:27:33 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_caracter( char c, char const *soc)
{
	int	i;

	i = 0 ;
	while (soc[i])
	{
		if (c == soc[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;

	int (i), (j);
	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && find_caracter(s1[i], set))
		i++;
	if (s1[i] == '\0')
	{
		ptr = malloc (1 * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		return (ptr [0] = '\0', ptr);
	}
	i = 0;
	while (s1[i] && find_caracter(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && find_caracter(s1[j], set))
		j--;
	ptr = ft_substr(s1, i, j + 1 - i);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
