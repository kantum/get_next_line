/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:37:51 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/27 10:30:25 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_wordcpy(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		j;
	int		w_count;

	if (!s || !(ret = (char **)malloc(sizeof(char *)
			* ft_count_words(s, c) + 1)))
		return (NULL);
	w_count = ft_count_words(s, c);
	j = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			ret[j++] = ft_wordcpy(s, c);
			while (*s && *s != c)
				s++;
		}
		if (*s)
			s++;
	}
	ret[w_count] = 0;
	return (ret);
}
