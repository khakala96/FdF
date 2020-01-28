/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:23:09 by khakala           #+#    #+#             */
/*   Updated: 2019/10/29 18:00:08 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*temp;

	if (!alst || !del)
		return ;
	ptr = *alst;
	while (ptr)
	{
		temp = ptr;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = temp->next;
	}
	*alst = NULL;
	return ;
}
