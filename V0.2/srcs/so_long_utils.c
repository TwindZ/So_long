/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:04:23 by emlamoth          #+#    #+#             */
/*   Updated: 2023/03/06 17:30:46 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_data(t_data *data)
{
	data->line = 0;
	data->col = 0;
	data->exit = 0;
	data->collect = 0;
	data->wrongchar = 0;
	data->rectangle = 0;
	data->walled = 0;
	data->valid = 0;
	data->map = NULL;
	data->playercount = 0;
	data->enemycount = 0;
	data->player.direct = 'S';
	data->flood.map = NULL;
	data->flood.collect = 0;
	data->flood.exit = 0;
	data->flood.done = 1;
	data->steps = 0;
	data->enemydelay = 0;
	data->collectindex = 0;
	data->wallindex = 0;
	data->wallindexdir = 0;
	data->rendercount = 0;
}

void	ft_map_size(char *path, t_data *data)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
		i++;
	}
	free(str);
	close(fd);
	data->line = i;
}

void	ft_message2(t_data *data)
{
	if (data->col > 40)
		ft_printf(ERCOLMAX);
	if (data->line > 22)
		ft_printf(ERLINEMAX);
}

void	ft_message(t_data *data)
{
	if (data->valid == 1)
		ft_printf(ERVALID);
	if (data->valid == 0)
		ft_printf(VALID);
	if (data->collect < 1)
		ft_printf(ERCOLLECT);
	if (data->exit > 1)
		ft_printf(EREXITMR);
	if (data->exit < 1)
		ft_printf(EREXITMSS);
	if (data->playercount > 1)
		ft_printf(ERPLAYERCNT);
	if (data->playercount < 1)
		ft_printf(ERPLAYERMSS);
	if (data->rectangle > 0)
		ft_printf(ERRECT);
	if (data->walled > 0)
		ft_printf(ERWALL);
	if (data->flood.exit != data->exit && data->flood.done == 0)
		ft_printf(ERFLOODEXT);
	if (data->flood.collect != data->collect && data->flood.done == 0)
		ft_printf(ERFLOODCOL);
	if (data->wrongchar != 0)
		ft_printf(ERWRONGC);
	ft_message2(data);
}
