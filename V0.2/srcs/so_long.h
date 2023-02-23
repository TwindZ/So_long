/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/22 18:56:52 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 128
# define IMG_SIZE 64

# define WALL "./visual/Lavax64.png"
# define FLOOR "./visual/rock2x64.png"
# define PLAYER "./visual/rock2wdemonx64.png"
# define COLLECT "./visual/rock2soulx64.png"
# define EXIT "./visual/rock2x64blackhole.png"


# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include "../MLX42/include/MLX42/MLX42.h"


typedef struct s_data
{
	int		line;
	int		col;
	int		totallen;
	int		player;
	int		exit;
	int		collect;
	int		wrongChar;
	int		rectangle;
	int		walled;
	char	**map;
	char	**floodmap;

}				t_data;

#endif