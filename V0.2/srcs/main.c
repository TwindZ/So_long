/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/23 18:24:47 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data *data)
{
	data->line = 0;
	data->col = 0;
	data->exit = 0;
	data->collect = 0;
	data->wrongChar = 0;
	data->rectangle = 0;
	data->walled = 0;
	data->valid = 0;
	data->map = NULL;
	data->player.count = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->flood.map = NULL;
	data->flood.collect = 0;
	data->flood.exit = 0;
}

void ft_map_size(char *path, t_data *data)
{
	char	*str;
	int		fd;
	int		i;
		
	i = 0;
	fd = open(path, O_RDONLY);
	while(1)
	{
		str = get_next_line(fd);
		if(!str)
			break;
		free(str);
		i++;
	}
	free(str);
	close (fd);
	data->line = i;
}

void	ft_init_map(char *path, t_data *data)
{
	int		fd;
	int		i;
	
	data->map = (char **)malloc((data->line + 1) * (sizeof(char *)));
	i = 0;
	fd = open(path, O_RDONLY);
	while(i < data->line)
	{
		data->map[i] = get_next_line(fd);
		printf("%s", data->map[i]);
		i++;
	}
	data->map[i] = '\0';
	close (fd);
	data->col = ft_strlen(data->map[0]);
}

void	ft_map_data_util(int x, int y, t_data *data)
{
	if(data->map[y][x] == 'P')
	{
		data->player.count++;
		data->player.pos_x = x;
		data->player.pos_y = y;
	}
	else if(data->map[y][x] == 'E')
		data->exit++;
	else if(data->map[y][x] == 'C')
		data->collect++;
	else if(data->map[y][x] == '1' || data->map[y][x] == '0'
		|| data->map[y][x] == '\n')
		;
	else
		data->wrongChar++;
}

void	ft_is_rec(t_data *data)
{ 
	int	x;
	int	y;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x] == '\0')
			x++;
		if(x != data->col)
			data->rectangle = 1;
		y++;
	}
}

void	ft_map_data(t_data *data)
{
	int	y;
	int	x;
	
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while(data->map[y][x])
		{
			ft_map_data_util(x, y, data);
			x++;
		}
		y++;
	}
	
	ft_is_rec(data);
}

void	ft_flood_cpy(char **src, t_data *data)
{
	int	i;
	
	i = 0;
	while(src[i])
		i++;
	data->flood.map = ft_calloc((i + 1), sizeof(char *));
	i = 0;
	while(src[i])
	{
		data->flood.map[i] = ft_calloc(ft_strlen(src[i]) + 1, sizeof(char));
		ft_strlcpy(data->flood.map[i], src[i], ft_strlen(src[i]));
		// printf("new%s", data->floodmap[i]);
		i++;
	}
}

// void	ft_framed(t_data *data)
// {
	
// }
// void	ft_floodfill(int x, int y, t_data *data)
// {
// 	if(x < 0 || y < 0 || x > data->col - 1 || y > data->line - 1)
// 		return;
// 	if(data->flood.map[y][x] == 'X' || data->flood.map[y][x] == '1')
// 		return;
// 	if(data->flood.map[y][x] == 'C')
// 		data->flood.collect += 1;
// 	if(data->flood.map[y][x] == 'E')
// 		data->flood.exit += 1;
// 	data->flood.map[y][x] = 'X';
// 	ft_floodfill(x + 1, y, data);
// 	ft_floodfill(x - 1, y, data);
// 	ft_floodfill(x, y + 1, data);
// 	ft_floodfill(x, y - 1, data);
// }

void	ft_validate(t_data *data)
{
	if(data->exit < 1 || data->player.count != 1 || data->collect < 1 ||
		data->rectangle != 0 || data->wrongChar != 0)
		data->valid = 1;
	if(data->valid == 0)
	ft_flood_cpy(data->map, data);		
	// ft_floodfill(data->player.pos_x, data->player.pos_y, data);
	ft_freeall(data->flood.map);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		return (ft_printf("Argument invalide !"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		return (ft_printf("Format de carte invalide !"));
	data = malloc(sizeof(*data));
	if(!data)
		return(ft_printf("roblème de création de struct data !"));
	ft_init_data(data);
	ft_map_size(argv[1], data);
	ft_init_map(argv[1], data);
	ft_map_data(data);
	ft_validate(data);
	//-------------------TESTING AREA----------------------------------------//
	ft_printf("Nombre de lignes = %d\n", data->line);
	ft_printf("Nombre de collones avec \\n = %d\n", data->col);
	ft_printf("Nombre de players = %d\n", data->player);
	ft_printf("Nombre de exit = %d\n", data->exit);
	ft_printf("Nombre de collect = %d\n", data->collect);
	ft_printf("Nombre de mauvais Char = %d\n", data->wrongChar);
	ft_printf("Map rectangulaire = %d\n", data->rectangle);
	// ft_printf("Map walled = %d\n", ft_strlen(**data->map));
	//-------------------TESTING AREA----------------------------------------//
	ft_freeall(data->map);
	free(data);
	return(0);
}
