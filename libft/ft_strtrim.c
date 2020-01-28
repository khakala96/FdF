/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:52:36 by khakala           #+#    #+#             */
/*   Updated: 2019/10/29 17:14:22 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_firstchar(char *str, const char *set)
{
	char					*ptr;
	unsigned int			i;
	unsigned int			amount;
	unsigned int			temp;

	ptr = str;
	amount = 0;
	while (*ptr)
	{
		i = 0;
		temp = amount;
		while (set[i])
			if (set[i++] == *ptr)
				++amount;
		if (amount == temp)
			return (amount);
		++ptr;
	}
	return (amount);
}

int		ft_lastchar(char *str, const char *set)
{
	unsigned int	i;
	int				index;
	unsigned int	amount;
	unsigned int	temp;

	amount = 0;
	i = ((unsigned int)ft_strlen(str) - 1);
	while (str[i])
	{
		index = 0;
		temp = amount;
		while (set[index])
			if (set[index++] == str[i])
				++amount;
		if (amount == temp)
			return (amount);
		--i;
	}
	return (amount);
}

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	start;
	unsigned int	size;
	unsigned int	spaces;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen((char*)s);
	spaces = ft_firstchar((char*)s, "' '\t\n");
	start = spaces;
	if (size > spaces)
		spaces = spaces + ft_lastchar((char*)s, "' '\t\n");
	size = size - spaces;
	if (!(result = ft_memalloc((size_t)size + 1)))
		return (NULL);
	result = ft_strncpy(result, (char*)s + start, size);
	return (result);
}
