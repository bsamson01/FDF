/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:05:32 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 13:05:53 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_elem(int nbr, int *tab, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int				*int_tab_add(int *src, int nbr, int size)
{
	int			*new;
	int			i;

	i = 0;
	new = (int *)malloc(sizeof(int) * (size + 1));
	while (i < size)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = nbr;
	free((int *)src);
	return (new);
}
