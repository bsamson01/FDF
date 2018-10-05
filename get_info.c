/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:50:51 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 12:52:13 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_info(t_data *fdf)
{
	char		**ret;
	int			i;
	int			j;

	i = 0;
	while (fdf->map[i])
	{
		ret = ft_strsplit(fdf->map[i], ' ');
		j = 0;
		while (ret[j])
		{
			if (ft_atoi(ret[j]) > fdf->max_z)
				fdf->max_z = ft_atoi(ret[j]);
			j++;
		}
		fdf->max_x = j;
		j -= 1;
		while (j >= 0)
			ft_strdel(&ret[j--]);
		i++;
	}
	fdf->scale = fdf->max_x > fdf->max_y ?
		(300 / fdf->max_x) : (300 / fdf->max_y);
	get_int_map(fdf);
}
