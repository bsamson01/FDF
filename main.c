/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 08:16:25 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 13:09:31 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			data(t_data *fdf)
{
	t_point		a;

	a.start_x = fdf->prev_x;
	a.start_y = fdf->prev_y;
	a.end_x = fdf->cur_x;
	a.end_y = fdf->cur_y;
	a.change_x = a.end_x - a.start_x;
	a.change_y = a.end_y - a.start_y;
	return (a);
}

void			sort_int_tab(int *tab, int size)
{
	int			i;
	int			temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void			height_arr(t_data *fdf)
{
	int			y;
	int			x;

	y = -1;
	while (y++ < fdf->max_y - 1)
	{
		x = 0;
		if (fdf->height_size == 0)
		{
			fdf->heights = (int *)malloc(sizeof(int));
			fdf->heights[0] = fdf->int_map[y][0];
			x++;
			fdf->height_size++;
		}
		while (x < fdf->max_x)
		{
			if (!is_elem(fdf->int_map[y][x], fdf->heights, fdf->height_size))
			{
				fdf->heights = int_tab_add(fdf->heights,
						fdf->int_map[y][x], fdf->height_size);
				fdf->height_size++;
			}
			x++;
		}
	}
}

void			get_map(int fd, t_data *fdf)
{
	int			i;
	char		*line;

	i = 0;
	fdf->map = (char **)malloc(sizeof(char *) * 1000);
	while (get_next_line(fd, &line) > 0)
	{
		fdf->map[i] = (char *)malloc(ft_strlen(line) + 2);
		fdf->map[i] = ft_strcpy(fdf->map[i], line);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	fdf->map[i] = NULL;
	fdf->max_y = i;
	get_info(fdf);
	height_arr(fdf);
	sort_int_tab(fdf->heights, fdf->height_size);
}

int				main(int ac, char **av)
{
	int			fd;
	t_data		fdf;

	if (ac == 2)
	{
		if (!error(av[1]))
		{
			ft_putstr("File extension not recognised. Please ");
			ft_putendl("insert a valid file with extension (.fdf).");
		}
		else
		{
			fd = open(av[1], O_RDONLY, 0600);
			initialize(&fdf);
			get_map(fd, &fdf);
			fdf.mlx = mlx_init();
			fdf.win = mlx_new_window(fdf.mlx, 1000, 1000, av[1]);
			draw(&fdf);
			mlx_key_hook(fdf.win, key_hooks, (t_data *)&fdf);
			mlx_loop(fdf.mlx);
		}
	}
	else
		ft_putendl("Invalid arguments : Please specify the input file.");
	return (0);
}
