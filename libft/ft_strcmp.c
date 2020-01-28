/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:26:28 by khakala           #+#    #+#             */
/*   Updated: 2019/10/24 14:52:04 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int index;

	index = 0;
	while (s2[index] && s1[index] && s2[index] == s1[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
