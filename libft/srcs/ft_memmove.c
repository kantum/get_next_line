/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 08:30:59 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/19 14:35:21 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	tmp[n];

	if (n < (1024 * 1024 * 128))
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dest, tmp, n);
		return (dest);
	}
	return (NULL);
}
