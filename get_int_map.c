/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:40:22 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 10:51:14 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_int_map(t_data *fdf)
{
	int		y;
	int		x;
	char	**split;

	y = 0;
	fdf->int_map = (int **)malloc(sizeof(int *) * fdf->max_y);
	while (y < fdf->max_y)
	{
		x = 0;
		split = ft_strsplit(fdf->map[y], ' ');
		fdf->int_map[y] = (int *)malloc(sizeof(int) * fdf->max_x);
		while (x < fdf->max_x)
		{
			fdf->int_map[y][x] = ft_atoi(split[x]);
			x++;
		}
		while (--x >= 0)
			ft_strdel(&split[x]);
		y++;
	}
	while (--y >= 0)
		ft_strdel(&fdf->map[y]);
	fdf->map[y++] = NULL;
}
