/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 17:51:10 by eteyssed          #+#    #+#             */
/*   Updated: 2014/11/24 17:51:31 by eteyssed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	allinit(t_all *all)
{
	all->re = 1;
	all->posimg.x = (SIZE_WIN_X / 2);
	all->posimg.y = (SIZE_WIN_Y / 2);
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(all));
	all->env.mlx = mlx_init();
	all->env.win = mlx_new_window(all->env.mlx, SIZE_WIN_X,\
		SIZE_WIN_Y, "42 FDF");
	all->img.img = mlx_new_image(all->env.mlx, SIZE_WIN_X, SIZE_WIN_Y);
	all->img.data = mlx_get_data_addr(all->img.img, &all->img.bpp,\
		&all->img.sizeline, &all->img.endian);
	all->img.clrline = 0x000000;
	allinit(all);
	mlx_loop(all->env.mlx);
	return (0);
}
