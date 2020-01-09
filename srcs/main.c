/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:24:46 by khakala           #+#    #+#             */
/*   Updated: 2020/01/09 17:17:41 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int     main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1280, 960, "FdF khakala");
    mlx_pixel_put(mlx_ptr, win_ptr, 200, 500, 0x0000FF00);
    draw_rectangle1(mlx_ptr, win_ptr);
    draw_rectangle2(mlx_ptr, win_ptr);
    draw_line1(mlx_ptr, win_ptr);
    draw_line2(mlx_ptr, win_ptr);
    draw_kuvio(mlx_ptr, win_ptr);
    mlx_string_put(mlx_ptr, win_ptr, 600, 300, 0xC0, "FdF Khakala");
    mlx_loop(mlx_ptr);
}

int     draw_rectangle1(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;

    x = 500;
    y = 290;
    while (x < 800)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
        x++;
    }
    return (0);
}

int     draw_rectangle2(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;

    x = 500;
    y = 330;
    while (x < 800)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
        x++;
    }
    return (0);
}

int     draw_line1(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;

    x = 500;
    y = 290;
    while (y < 331)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
        y++;
    }
    return (0);
}

int     draw_line2(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;

    x = 800;
    y = 290;
    while (y < 331)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
        y++;
    }
    return (0);
}

int     draw_kuvio(void *mlx_ptr, void *win_ptr)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < 980 || x < 1280)
    {
        if (y % 2 == 0 || x % 2 == 0)
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
        y++;
        x++;
    }
    return (0);
}