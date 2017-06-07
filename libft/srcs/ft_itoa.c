/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 15:02:31 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/27 10:24:13 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(long n)
{
	int		count;

	count = 0;
	while (n /= 10)
		count++;
	return (count + 1);
}

static	int	ft_isnegative(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		i;
	int		negative;

	nb = n;
	i = ft_len(nb) + 1;
	negative = ft_isnegative(nb);
	if (negative)
	{
		nb = -nb;
		i++;
	}
	if (!(ret = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	ret[--i] = '\0';
	while (i--)
	{
		ret[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (negative)
		ret[0] = '-';
	return (ret);
}
