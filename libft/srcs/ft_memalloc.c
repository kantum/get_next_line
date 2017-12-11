/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 10:53:54 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/19 14:37:00 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	while (i < n)
		ret[i++] = 0;
	return (ret);
}
