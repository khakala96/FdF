/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:55:53 by khakala           #+#    #+#             */
/*   Updated: 2020/01/28 15:42:25 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)
# define Q 12
# define E 14
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define MINUS 69
# define PLUS 78
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define P 35
# define I 34
# define ESC 53
# define R 15

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	int			shift_z;
	void		*mlx_ptr;
	void		*win_ptr;
	float		cos_angle;
	float		sin_angle;
	int			z;
	int			z1;
	int			z_alt;
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			camera;
}				t_fdf;

void			read_map(char *file_name, t_fdf *data);

void			fill_matrix(int *z_line, char *line);

int				get_width(char *file_name);

int				get_height(char *file_name, t_fdf *data);

void			bresenham(float x, float y, t_fdf *data);

void			draw(t_fdf *data);

int				change_angle(int key, t_fdf *data);

int				change_z_value(int key, t_fdf *data);

void			draw_lines(float x, float y, t_fdf *data);

void			free_matrix(t_fdf *data);

void			print_menu(t_fdf *data);

void			restore_defaults(t_fdf *data);

int				deal_key(int key, t_fdf *data);

#endif
