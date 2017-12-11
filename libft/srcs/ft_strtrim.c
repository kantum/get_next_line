/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 17:04:07 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/25 17:36:44 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s)
{
	size_t	i;
	size_t	len;
	size_t	spaces;

	i = 0;
	len = ft_strlen((char *)s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	spaces = i;
	if (s[i])
	{
		i = len - 1;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		{
			i--;
			spaces++;
		}
	}
	return (len - spaces);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	len = ft_count(s);
	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i])
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		while (j < len)
			ret[j++] = s[i++];
	}
	ret[j] = '\0';
	return (ret);
}
