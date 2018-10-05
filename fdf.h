/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 10:27:14 by bsamson           #+#    #+#             */
/*   Updated: 2018/08/01 13:04:47 by bsamson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <sys/types.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define G_S 15

typedef	struct	s_a
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_a;

typedef	struct	s_data
{
	char			**map;
	void			*mlx;
	void			*win;
	int				max_x;
	int				max_z;
	int				max_y;
	int				cur_y;
	int				cur_z;
	int				cur_x;
	int				prev_x;
	int				prev_z;
	int				prev_y;
	int				pos_x;
	int				pos_y;
	int				height_size;
	int				*heights;
	int				pos_x0;
	int				pos_y0;
	int				scale;
	int				zoom;
	int				height;
	int				**int_map;
}				t_data;

typedef	struct	s_point
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		change_x;
	int		change_y;
}				t_point;

void		bres(t_data *fdf);
void		get_int_map(t_data *fdf);
void		draw_x(t_data *fdf);
void		draw_y(t_data *fdf);
int			cur_scale(t_data *fdf);
void		get_info(t_data *fdf);
t_point		data(t_data *fdf);
int			error(char *str);
int			*int_tab_add(int *src, int nbr, int size);
int			is_elem(int nbr, int *tab, int size);
int			key_hooks(int key, t_data *fdf);
void		zoom(int key, t_data *fdf);
void		translate(int key, t_data *fdf);
void		scale(int key, t_data *fdf);
void		height(int key, t_data *fdf);
void		draw(t_data *fdf);
void		initialize(t_data *fdf);


#endif
