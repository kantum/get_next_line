/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:38:36 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/19 15:35:03 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
