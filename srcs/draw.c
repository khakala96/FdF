/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:59:51 by khakala           #+#    #+#             */
/*   Updated: 2020/01/17 13:52:57 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->cos_angle);
	*y = (*x + *y) * sin(data->sin_angle) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	data->z = data->z_matrix[(int)y][(int)x];
	data->z1 = data->z_matrix[(int)y1][(int)x1];
	if (data->z != 0)
		data->z = data->z_matrix[(int)y][(int)x] * (data->z_alt);
	if (data->z1 != 0)
		data->z1 = data->z_matrix[(int)y][(int)x] * (data->z_alt);
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (data->z || data->z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, data->z, data);
	isometric(&x1, &y1, data->z1, data);
	draw_lines(x, y, x1, y1, data);
}

void	draw_lines(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
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

void	draw(t_fdf *data)
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
