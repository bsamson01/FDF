/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:48:40 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 11:43:52 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_hooks(int key, t_data *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 69 || key == 78)
		zoom(key, fdf);
	else if (key >= 123 && key <= 126)
		translate(key, fdf);
	else if (key == 24 || key == 27)
		scale(key, fdf);
	else if (key == 12 || key == 13)
		height(key, fdf);
	return (0);
}

void		height(int key, t_data *fdf)
{
	fdf->height += (key == 12) ? -4 : 4;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}

void		zoom(int key, t_data *fdf)
{
	int		i;

	key == 69 ? (fdf->zoom += 5) : (fdf->zoom -= 5);
	i = mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}

void		translate(int key, t_data *fdf)
{
	int		i;

	if (key == 123 || key == 124)
		key == 123 ? (fdf->pos_x -= 10) : (fdf->pos_x += 10);
	else
		key == 125 ? (fdf->pos_y += 10) : (fdf->pos_y -= 10);
	i = mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}

void		scale(int key, t_data *fdf)
{
	int		i;

	key == 24 ? (fdf->scale++) : (fdf->scale--);
	if (fdf->scale < 1)
		fdf->scale = 1;
	i = mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
}
