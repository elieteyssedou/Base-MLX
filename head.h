/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 18:08:36 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/24 18:08:36 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>

# define SIZE_WIN_X 1920
# define SIZE_WIN_Y 1080

typedef unsigned char	t_byte;

typedef struct	s_img
{
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	int			clrline;
	char		*data;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
}				t_env;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_color
{
	t_byte		r;
	t_byte		g;
	t_byte		b;
}				t_color;

typedef struct	s_line
{
	t_pos		p1;
	t_pos		p2;
	t_color		clr;
	t_pos		inc;
	int			dx;
	int			dy;
}				t_line;

int				ft_color_to_int(t_color color);
void			ft_line_put(t_env *env, t_pos p1, t_pos p2);
void			ft_line_put_1(t_line line, t_img img);
void			ft_line_put_2(t_line line, t_img img);
t_color			ft_rgb_to_color(t_byte r, t_byte g, t_byte b);
void			ft_put_pixel_img(t_pos point, t_img img);

#endif
