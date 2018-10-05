/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:21:41 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 10:51:47 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	line(void *mlx, void *win, t_point pos)
{
	t_a		a;

	a.dx = abs(pos.end_x - pos.start_x);
	a.dy = abs(pos.end_y - pos.start_y);
	a.sx = pos.start_x < pos.end_x ? 1 : -1;
	a.sy = pos.start_y < pos.end_y ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (pos.change_x)
	{
		mlx_pixel_put(mlx, win, pos.start_x, pos.start_y, 0x0000FF00);
		if (pos.start_x == pos.end_x && pos.start_y == pos.end_y)
			break ;
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			pos.start_x += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			pos.start_y += a.sy;
		}
	}
}

void	bres(t_data *fdf)
{
	t_point		pos;

	pos = data(fdf);
	line(fdf->mlx, fdf->win, pos);
}
