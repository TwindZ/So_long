/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/23 18:26:33 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 128
# define IMG_SIZE 64

//-------------------------------PATHS---------------------------------------//
# define WALL "./visual/Lavax64.png"
# define FLOOR "./visual/rock2x64.png"
# define PLAYER "./visual/rock2wdemonx64.png"
# define COLLECT "./visual/rock2soulx64.png"
# define EXIT "./visual/rock2x64blackhole.png"

//-------------------------------MESAGE--------------------------------------//
# define VALID "Map valide ! :)"
# define ERVALID "Map non valide :("
# define ERPLAYERMSS "Pas de joueur présent sur la map"
# define ERPLAYERCNT "Map solo, trop de joueurs présents"
# define EREXIT "Pas de sortrie présente sur la map"
# define ERCOLLECT "Pas de collectible sur la map"
# define ERFLOODCOL "Collectible(s) inatteignable(s)"
# define ERFLOODEXT "Sortie inatteignable"

//------------------------------INCLUDE--------------------------------------//
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//# include "../MLX42/include/MLX42/MLX42.h"

//-------------------------------STRUCTS-------------------------------------//
typedef struct	s_flood
{
	char	**map;
	int		collect;
	int		exit;
}				t_flood;

typedef struct	s_player
{
	int		count;
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct	s_data
{
	int				line;
	int				col;
	int				exit;
	int				collect;
	int				wrongChar;
	int				rectangle;
	int				walled;
	int				valid;
	char			**map;
	t_player		player;
	t_flood			flood;

}				t_data;

#endif