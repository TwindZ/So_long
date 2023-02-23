/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:32:17 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/22 13:05:23 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



mlx_t	*ft_mlx_init(t_map *map)
{
	mlx_t *mlx;
	
	mlx = mlx_init(map->col * IMG_SIZE, map->line * IMG_SIZE, "So_long", false);
	if(!mlx)
		return(NULL);
	return (mlx);
}

t_img	*ft_img_init(mlx_t *mlx)
{
	t_img *img;
	img = malloc(sizeof(img));
	img->collect = mlx_texture_to_image(mlx, mlx_load_png(COLLECT));
	img->floor = mlx_texture_to_image(mlx, mlx_load_png(FLOOR));
	img->player = mlx_texture_to_image(mlx, mlx_load_png(PLAYER));
	img->wall = mlx_texture_to_image(mlx, mlx_load_png(WALL));
	img->exit = mlx_texture_to_image(mlx, mlx_load_png(EXIT));
	return(img);
}

int ft_render(t_map *map, mlx_t *mlx, t_img *img)
{
	
	int x;
	int y;
	
	y = 0;
	while(y < map->line)
	{
		x = 0;
		while(x < map->col)
		{
			if(map->map_a[y][x] == '1')
				mlx_image_to_window(mlx, img->wall, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == '0')
				mlx_image_to_window(mlx, img->floor, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'E')
				mlx_image_to_window(mlx, img->exit, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'P')
				mlx_image_to_window(mlx, img->player, x * IMG_SIZE, y * IMG_SIZE);
			if(map->map_a[y][x] == 'C')
				mlx_image_to_window(mlx, img->collect, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
	return(0);
}