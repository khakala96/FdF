/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:28:39 by khakala           #+#    #+#             */
/*   Updated: 2020/01/09 11:10:03 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     read_map(char *av, const int fd, t_map *map)
{
    int x;
    int result;
    char *input;
    char current[SIZE + 1];

    x = 0;
	if ((x = read(fd, current, SIZE)) > 0)
	{
		current[x] = '\0';
		*input = ft_strdup(current);
    }
    if (!((fd = open(av, O_RDONLY)) >= 0))
            ft_error(ERR_OPENING_FILE);
    while ((result = get_next_line(fd, &input)) == 1)
    {
        map->height++;
        printf("%d\n", map->height);
    }
    return (0);
}