/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:54:20 by khakala           #+#    #+#             */
/*   Updated: 2020/01/15 15:39:42 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_count_words(const char *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

int     get_height(char *file_name)
{
    int fd;
    int height;
    char *line;
    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while(get_next_line(fd, &line) > 0)
    {
        height++;
        free(line);
    }
    close(fd);
    printf("%d\n", height);
    return (height);
}

int     get_width(char *file_name)
{
    int width;
    int fd;
    char *line;

    fd = open(file_name, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_count_words(line, ' ');
    free(line);
    close(fd);
    return(width);
}

void    fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i;
    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
}

void    read_map(char *file_name, t_fdf *data)
{
    int i;
    char *line;
    int fd;

    data->cos_angle = 0.5;
    data->sin_angle = 0.5;
    data->height = get_height(file_name);
    data->width = get_width(file_name);
    data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    fd = open(file_name, O_RDONLY, 0);
    i = 0;
    while (get_next_line(fd, &line) == 1)
    {
        if (i <= data->height)
        {
            fill_matrix(data->z_matrix[i], line);
            free(line);
            i++;
        }
    }
    close(fd);
    data->z_matrix[i] = NULL;
}