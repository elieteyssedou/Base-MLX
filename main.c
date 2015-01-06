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

void	mandelbrot(t_env *env)
{
	float	x1 = -1;
	float	x2 = 1;
	float	y1 = -1.2;
	float	y2 = 1.2;
	float	zoom = 100;
	float	iteration_max = 150;
	float 	image_x;
	float 	image_y;

	image_x = (x2 - x1) * zoom;
	image_y = (y2 - y1) * zoom;
	
	int x;
	int y;
	
	float c_r = 0.285;
	float c_i = 0.01;
	float z_r;
	float z_i;
	float i;
	
	float tmp;
	
	t_pos pxl;
	
	x = 0;
	y = 0;
	
	while (x < image_x)
	{
		while (y < image_y)
		{
			i = 0;
			z_r = x / zoom + x1;
			z_i = y / zoom + y1;
	
			while ((z_r * z_r + z_i * z_i < 4) && (i < iteration_max))
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			pxl.x = x;
			pxl.y = y;
			env->img.clrline = 0xFFFFFF * (i / iteration_max);
			ft_put_pixel_img(pxl, env->img);
			y++;
		}
		x++;
	}
}

int		main(int ac, char **av)
{
	ac = ac;
	av = av;
	t_env env;
	t_pos pxl;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, SIZE_WIN_X, SIZE_WIN_Y, "Fract'ol");
	env.img.img = mlx_new_image(env.mlx, SIZE_WIN_X, SIZE_WIN_Y);
	env.img.data = mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.sizeline,
		&env.img.endian);
	env.img.clrline = 0xFF0000;
	mandelbrot(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
