/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/16 15:19:58 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if(argc != 2)
		return (ft_printf("Invalide"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_printf("open() fail");
	ft_ber(argv[1]);
	map = ft_parsing(fd);
	
	ft_printf("lignes : %d\n", map->line);
	ft_printf("Collones: %d\n", map->col);
	ft_printf("Total lenght : %d\n", map->totallen);
	ft_printf("Player : %d\n", map->player);
	ft_printf("Exit : %d\n", map->exit);
	ft_printf("Collectables : %d\n", map->collect);
	ft_printf("Is rectangle : %d\n", map->rectangle);
	ft_printf("Is walled : %d\n", map->walled);
	if (close(fd) == -1)
		ft_printf("close() fail");
	free(map);
}
