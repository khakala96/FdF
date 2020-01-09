/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:50:47 by khakala           #+#    #+#             */
/*   Updated: 2019/12/18 15:48:31 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE 100

#include <stdlib.h>
#include <fcntl.h>
#include "errors.h"
#include "../Libft/libft.h"
#include "stdio.h" // remove when done

typedef struct      s_coords
{
    int             x;
    int             y;
    int             z;
    int             width;
    int             height;
}                   t_coords;

typedef struct      s_map
{
    int             height;
    int             width;
    int             z_min;
    int             z_max;
}                   t_map;

int     ft_error(char *s);

int     read_map(char *av, t_map *map);

int		get_next_line(const int fd, char **line);

#endif

