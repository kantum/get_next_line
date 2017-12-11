/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:41:33 by svigouro          #+#    #+#             */
/*   Updated: 2017/04/27 18:42:08 by svigouro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	begin = new;
	while (lst->next)
	{
		if (!(new->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (begin);
}
