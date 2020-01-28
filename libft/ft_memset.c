/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:25:33 by khakala           #+#    #+#             */
/*   Updated: 2019/10/22 16:08:28 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)dest;
	while (len-- > 0)
		*(ptr++) = (unsigned char)value;
	return (dest);
}
