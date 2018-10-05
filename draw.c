/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:00:25 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 11:00:35 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set(t_data *fdf)
{
	fdf->pos_x0 += fdf->scale;
	fdf->pos_y0 -= fdf->scale;
}

void	draw_y(t_data *fdf)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while (x < fdf->max_x)
	{
		y = fdf->max_y - 1;
		fdf->prev_x = fdf->pos_x0;
		i = 0;
		while (y >= 0)
		{
			fdf->cur_z = fdf->int_map[y--][x];
			fdf->cur_x = fdf->pos_x0 - (i * fdf->scale);
			fdf->cur_y = fdf->pos_y0 - (fdf->scale * i) + cur_scale(fdf);
			if (y == (fdf->max_y - 2))
				fdf->prev_y = fdf->cur_y;
			bres(fdf);
			fdf->prev_y = fdf->cur_y;
			fdf->prev_x = fdf->cur_x;
			i++;
		}
		set(fdf);
		x++;
	}
}

void	draw_x(t_data *fdf)
{
	int		y;
	int		x;

	fdf->scale += fdf->zoom;
	y = fdf->max_y - 1;
	while (y >= 0)
	{
		x = 0;
		fdf->prev_x = fdf->pos_x0;
		while (x < fdf->max_x)
		{
			fdf->cur_z = fdf->int_map[y][x];
			fdf->cur_x = fdf->pos_x0 + (x * fdf->scale);
			fdf->cur_y = fdf->pos_y0 - (x * fdf->scale) + cur_scale(fdf);
			if (x == 0)
				fdf->prev_y = fdf->cur_y;
			bres(fdf);
			fdf->prev_x = fdf->cur_x;
			fdf->prev_y = fdf->cur_y;
			x++;
		}
		y--;
		fdf->pos_y0 -= fdf->scale;
		fdf->pos_x0 -= fdf->scale;
	}
}

void	draw(t_data *fdf)
{
	fdf->pos_x0 = fdf->pos_x;
	fdf->pos_y0 = fdf->pos_y;
	draw_x(fdf);
	fdf->pos_x0 = fdf->pos_x;
	fdf->pos_y0 = fdf->pos_y;
	draw_y(fdf);
}
