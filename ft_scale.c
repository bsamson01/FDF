/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 04:33:54 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 12:21:21 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pos(t_data *fdf)
{
	int		i;

	i = 0;
	while (i < fdf->height_size)
	{
		if (fdf->cur_z == fdf->heights[i])
			return (i);
		i++;
	}
	return (0);
}

int		cur_scale(t_data *fdf)
{
	int		i;

	i = fdf->prev_y - fdf->cur_y;
	if (fdf->cur_z != 0)
		return (-(fdf->cur_z + fdf->scale + (fdf->height * pos(fdf))));
	return (0);
}
