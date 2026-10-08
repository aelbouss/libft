/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:15:28 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/03 17:20:36 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbr_len(int n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n != 0)
	{
		cnt++;
		n /= 10 ;
	}
	return (cnt);
}

int	check_if_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ptoc;
	long int	nbr;

	nbr = (long int) n;
	len = nbr_len(n);
	if (check_if_negative(nbr) == 1)
	{
		nbr = nbr * -1;
		len += 1;
	}
	ptoc = malloc(len + 1 * sizeof(char));
	if (ptoc == NULL)
		return (NULL);
	if (nbr_len(nbr) == 1)
		ptoc[0] = '0';
	ptoc[len--] = '\0';
	if (check_if_negative(n) == 1)
		ptoc[0] = '-';
	while (nbr != 0)
	{
		ptoc[len--] = (nbr % 10 + '0');
		nbr /= 10;
	}
	return (ptoc);
}
