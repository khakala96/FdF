/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:55:53 by khakala           #+#    #+#             */
/*   Updated: 2020/01/15 15:21:14 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h> // remove when done
# include <stdlib.h>
# include <unistd.h>

typedef struct      s_fdf
{
    int             width;
    int             height;
    int             **z_matrix;
    int             zoom;
    int             color;
    int             shift_x;
    int             shift_y;
    int             shift_z;
    void            *mlx_ptr;
    void            *win_ptr;
    float           cos_angle;
    float           sin_angle;
}                   t_fdf;

void                read_map(char *file_name, t_fdf *data);

void                fill_matrix(int *z_line, char *line);

int                 get_width(char *file_name);

int                 get_height(char *file_name);

void                bresenham(float x, float y, float x1, float y1, t_fdf *data);
void                draw(t_fdf *data);

int                 change_angle(int key, t_fdf *data);

#endif
