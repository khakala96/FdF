/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khakala <khakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 11:24:46 by khakala           #+#    #+#             */
/*   Updated: 2019/12/18 14:43:58 by khakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int ac, char **av)
{
    t_map *map;

    map = NULL;
    if (ac == 2)
    {
        //if (!((fd = open(av[1], O_RDONLY)) >= 0))
            //ft_error(ERR_OPENING_FILE);
        if (!(map = (t_map *)malloc(sizeof(t_map))))
            ft_error(ERR_MALLOCING_MAP);
        if (!(read_map(av[1], map)))
            ft_error(ERR_READING_FILE);
    }
    ft_error(ERR_ARGS);
    return (0);

}