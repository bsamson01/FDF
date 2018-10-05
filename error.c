/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 12:51:31 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 12:51:55 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				error(char *str)
{
	int			i;

	i = ft_strlen(str);
	if (i <= 4)
		return (0);
	if (str[i - 1] == 'f' && str[i - 2] == 'd' && str[i - 3] == 'f'
			&& str[i - 4] == '.')
		return (1);
	return (0);
}
