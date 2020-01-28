/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:48:18 by khakala           #+#    #+#             */
/*   Updated: 2019/10/30 10:48:41 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int pos;
	unsigned int n;

	if (!*needle)
		return ((char*)haystack);
	pos = 0;
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			n = 1;
			while (needle[n] != '\0' && haystack[pos + n] == needle[n])
				++n;
			if (needle[n] == '\0')
				return ((char*)&haystack[pos]);
		}
		++pos;
	}
	return (0);
}
