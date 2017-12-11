/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:01:59 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/27 19:15:16 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (power != 1)
		nb *= ft_power(nb, (power - 1));
	return (nb);
}
