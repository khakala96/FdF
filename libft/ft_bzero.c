/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:30:49 by khakala           #+#    #+#             */
/*   Updated: 2019/10/28 10:45:07 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	char	*pointer;
	size_t	i;

	if (!n)
		return ;
	pointer = b;
	i = 0;
	while (i < n)
		*(pointer + i++) = 0;
}
