/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:20:24 by khakala           #+#    #+#             */
/*   Updated: 2019/10/30 13:08:03 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	if (s1 && s2)
		size = (size_t)(ft_strlen)((char*)s1) + ft_strlen((char*)s2);
	else if (s1)
		size = (size_t)(ft_strlen((char*)s1));
	else if (s2)
		size = (size_t)(ft_strlen((char*)s2));
	else
		return (NULL);
	if (!(result = ft_memalloc(size)))
		return (NULL);
	if (s1)
		result = strcpy(result, (char*)s1);
	else
		result = strcpy(result, (char*)s2);
	if (s1 && s2)
		result = ft_strcat(result, (char*)s2);
	return (result);
}
