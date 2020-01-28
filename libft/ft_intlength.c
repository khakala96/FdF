/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:48:16 by khakala           #+#    #+#             */
/*   Updated: 2019/10/30 12:50:24 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		higher_nums(int num)
{
	if (num >= 10000000)
	{
		if (num >= 1000000000)
			return (10);
		if (num >= 100000000)
			return (9);
		return (8);
	}
	if (num >= 1000000)
		return (7);
	return (6);
}

int		ft_intlength(int num)
{
	if (num >= 100000)
		return (higher_nums(num));
	else
	{
		if (num >= 1000)
		{
			if (num >= 10000)
				return (5);
			return (4);
		}
		else
		{
			if (num >= 100)
				return (3);
			if (num >= 10)
				return (2);
		}
		return (1);
	}
}
