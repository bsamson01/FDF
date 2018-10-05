/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:55:10 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 12:17:41 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize(t_data *fdf)
{
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->max_x = 0;
	fdf->max_y = 0;
	fdf->max_z = 0;
	fdf->cur_x = 0;
	fdf->cur_y = 0;
	fdf->cur_z = 0;
	fdf->prev_x = 0;
	fdf->prev_y = 0;
	fdf->prev_z = 0;
	fdf->pos_x = 300;
	fdf->pos_y = 600;
	fdf->zoom = 0;
	fdf->scale = 0;
	fdf->height_size = 0;
	fdf->height = 0;
	fdf->pos_x0 = fdf->pos_x;
	fdf->pos_y0 = fdf->pos_y;
}
