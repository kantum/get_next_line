/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:48:39 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/25 13:32:19 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dest;
	char	*s;
	size_t	n;
	size_t	dst_len;

	dest = dst;
	s = (char *)src;
	n = size;
	while (n-- && *dest)
		dest++;
	dst_len = dest - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(s));
	while (*s)
	{
		if (n != 1)
		{
			*dest++ = *s;
			n--;
		}
		s++;
	}
	*dest = '\0';
	return (dst_len + (s - src));
}
