/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:42:01 by khakala           #+#    #+#             */
/*   Updated: 2019/10/28 12:08:41 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if (src == dest)
		return (dest);
	if (s < d)
	{
		while (len)
		{
			len--;
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (++i < len)
			*(d + i) = *(s + i);
	}
	return (dest);
}
