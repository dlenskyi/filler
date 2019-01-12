/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:21:29 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/10 16:21:31 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	magic_border(t_fill_gen *g, int color, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			mlx_pixel_put(g->mlx.mlx_ptr, g->mlx.win_ptr,
			25 + (x * 11) + j, 25 + (y * 11) + i, color);
			j++;
		}
		i++;
	}
}

void	magic_start_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = 0;
	while (g->map.size[y])
	{
		x = 0;
		while (g->map.size[y][x])
		{
			if (g->map.size[y][x] == g->player.robot ||
				g->map.size[y][x] == g->player.robot + 32)
				magic_border(g, 0xeeff00, x, y);
			else if (g->map.size[y][x] == g->player.human)
				magic_border(g, 0xd500ff, x, y);
			x++;
		}
		y++;
	}
}

void	magic_piece(t_fill_gen *g)
{
	int x;
	int y;

	y = 0;
	while (g->map.size[y])
	{
		x = 0;
		while (g->map.size[y][x])
		{
			if (g->map.size[y][x] == g->player.robot ||
				g->map.size[y][x] == g->player.robot + 32)
				magic_border(g, 0xeeff00, x, y);
			else if (g->map.size[y][x] == g->player.human)
				magic_border(g, 0xd500ff, x, y);
			x++;
		}
		y++;
	}
}
