/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:51:40 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/15 13:45:55 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	int 	fd;

	if((fd = open("./maps/map01.ber", O_RDONLY))== -1)
		printf("open() fail");

	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	ft_printf("%s", get_next_line(fd));
	

	if (close(fd) == -1)
		printf("close() fail");
}
