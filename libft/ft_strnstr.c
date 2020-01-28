/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:10:32 by khakala           #+#    #+#             */
/*   Updated: 2019/10/30 10:47:23 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *nd, size_t len)
{
	char	*stack;
	size_t	letters_left;
	size_t	needle_len;
	size_t	i;

	stack = (char *)hst;
	if (nd[0] == '\0')
	{
		return (stack);
	}
	i = 0;
	letters_left = len;
	needle_len = (size_t)ft_strlen(nd);
	while (*stack && letters_left >= needle_len)
	{
		if (*stack == *nd)
		{
			if (ft_strncmp(nd, stack, needle_len) == 0)
				return (stack);
		}
		i++;
		letters_left--;
		stack++;
	}
	return (NULL);
}
