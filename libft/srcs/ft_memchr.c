/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 08:59:13 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/19 14:35:45 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	tf;
	char	*src;

	i = 0;
	src = (char *)s;
	tf = (char)c;
	while (i < n)
	{
		if (src[i] == tf)
			return (&src[i]);
		i++;
	}
	return (NULL);
}
