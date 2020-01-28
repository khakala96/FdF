/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:54:20 by khakala           #+#    #+#             */
/*   Updated: 2020/01/28 12:07:32 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_words(const char *str, char c)
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

int		get_height(char *file_name, t_fdf *data)
{
	int		fd;
	int		height;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY);
	height = 0;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
		{
			data->width = ft_count_words(line, ' ');
			i++;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

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

void	read_map(char *file_name, t_fdf *data)
{
	int		i;
	char	*line;
	int		fd;

	data->cos_angle = 0.8;
	data->sin_angle = 0.8;
	data->height = get_height(file_name, data);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (i < data->height)
		{
			fill_matrix(data->z_matrix[i], line);
			i++;
		}
		free(line);
	}
	close(fd);
}
