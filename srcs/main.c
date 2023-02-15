/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 17:15:52 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	t_map	*map;

	if ((fd = open("./maps/map01.ber", O_RDONLY)) == -1)
		ft_printf("open() fail");
	map = ft_parsing(fd);
	ft_printf("player : %d\n", map->player);
	ft_printf("collectables : %d\n", map->collect);
	ft_printf("exit : %d\n", map->exit);
	ft_printf("lignes : %d\n", map->line);
	ft_printf("rectangle : %d\n", map->rectangle);
	if (close(fd) == -1)
		ft_printf("close() fail");
	free(map);
}
