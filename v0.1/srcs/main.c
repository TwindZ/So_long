/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/22 14:18:11 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_struct(t_img *img)
{
	free(img);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_data		*data;
	mlx_t		*mlx;
	t_img		*img;
	
	

	if (argc != 2)
		return (ft_printf("Argument invalide"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Format de carte invalide"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_printf("open() fail");
	map = ft_parsing(fd);	
	mlx = ft_mlx_init(map);
	img = ft_img_init(mlx);
	//ft_render(map, mlx, img);
	//mlx_loop(mlx);	
	ft_printf("lignes : %d\n", map->line);
	ft_printf("Collones: %d\n", map->col);
	ft_printf("Total lenght : %d\n", map->totallen);
	ft_printf("Player : %d\n", map->player);
	ft_printf("Exit : %d\n", map->exit);
	ft_printf("Collectables : %d\n", map->collect);
	ft_printf("Is rectangle : %d\n", map->rectangle);
	ft_printf("Is walled : %d\n", map->walled);
	free(img);
	mlx_close_window(mlx);
	ft_freeall(map->map_a);
	free(map);
	
	mlx_terminate(mlx);
	if (close(fd) == -1)
		ft_printf("close() fail");
	return(0);
}
