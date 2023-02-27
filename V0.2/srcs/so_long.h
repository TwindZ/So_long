/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:41:54 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/27 17:26:00 by emlamoth         ###   ########.fr       */
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
# define VALID "------SUCCES------\nMap valide ! :)\n"
# define ERVALID "------ERROR-------\nMap non valide :(\n"
# define ERPLAYERMSS "Pas de joueur présent sur la map\n"
# define ERPLAYERCNT "Map solo, trop de joueurs présents\n"
# define EREXITMSS "Pas de sortie présente sur la map\n"
# define EREXITMR "Trop de sorties sur la map\n"
# define ERCOLLECT "Pas de collectible sur la map\n"
# define ERFLOODCOL "Collectible(s) inatteignable(s)\n"
# define ERFLOODEXT "Sortie inatteignable\n"
# define ERFLOOD "Map non terminable\n"
# define ERRECT "Map non rectangulaire\n"
# define ERWALL "Map non encadré\n"

//------------------------------INCLUDE--------------------------------------//
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//# include "../MLX42/include/MLX42/MLX42.h"

//-------------------------------STRUCTS-------------------------------------//
typedef struct s_flood
{
	char	**map;
	int		collect;
	int		exit;
	int		done;
}				t_flood;

typedef struct s_player
{
	int		count;
	int		pos_x;
	int		pos_y;
}				t_player;

typedef struct s_data
{
	int				line;
	int				col;
	int				exit;
	int				collect;
	int				wrongchar;
	int				rectangle;
	int				walled;
	int				valid;
	char			**map;
	t_player		player;
	t_flood			flood;

}				t_data;

void	ft_validate(t_data *data);
void	ft_init_map(char *path, t_data *data);
void	ft_map_data(t_data *data);

#endif