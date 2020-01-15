/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:59:51 by khakala           #+#    #+#             */
/*   Updated: 2020/01/15 15:38:30 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX1(a, b) (a > b ? a : b) 
#define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z, t_fdf *data)
{
    *x = (*x - *y) * cos(data->cos_angle);
    *y = (*x + *y) * sin(data->sin_angle) - z;
}

void        bresenham(float x, float y, float x1, float y1, t_fdf *data) // [1:1] [3:12]
{
    float x_step;
    float y_step;
    int max;
    float z;
    float z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];

    // zoom
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    // color
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    // 3D

    isometric(&x, &y, z, data);
    isometric(&x1, &y1, z1, data);

    // shift
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;
    
    x_step = x1 - x; // 2
    y_step = y1 - y; // 11
    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    }
}

void    draw(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
        x++;
        }
        y++;
    }
}