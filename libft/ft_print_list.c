/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:00 by khakala           #+#    #+#             */
/*   Updated: 2019/10/29 16:19:54 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_print_list_content(lst);
		if (lst->next)
			write(1, "-->", 5);
		lst = lst->next;
	}
}
