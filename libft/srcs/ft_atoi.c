/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:13:15 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/27 10:36:01 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (ft_isdigit(nptr[i]) == 1)
			ret = ret * 10 + nptr[i++] - '0';
		else
			break ;
	}
	return (ret * sign);
}
