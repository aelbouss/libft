/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:20:07 by aelbouss          #+#    #+#             */
/*   Updated: 2024/11/14 01:30:32 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	cnt_word(char const *str, char c)
{
	int	i;
	int	cnt;

	if (!str)
		return (0);
	cnt = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || str[i - 1] == c) && (str[i] != c))
			cnt++;
		i++;
	}
	return (cnt);
}

static	int	cnt_str(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_stringdup(const char *src, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	void	free_split(char **arr, int arrlen)
{
	while (arrlen >= 0)
	{
		free(arr[arrlen]);
		arrlen--;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char			**str;

	int (i), (j);
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc((cnt_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			str[j++] = ft_stringdup((s + i), cnt_str((s + i), c));
			if (!str[j - 1])
				return (free_split(str, j - 1), NULL);
			i += cnt_str((s + i), c);
		}
	}
	return (str[j] = NULL, str);
}
