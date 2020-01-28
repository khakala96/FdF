/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:17:28 by khakala           #+#    #+#             */
/*   Updated: 2019/10/28 10:41:41 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * size + 1);
	if (!string)
		return (NULL);
	ft_bzero(string, size + 1);
	return (string);
}
