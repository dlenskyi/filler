/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:55:48 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/11 16:55:48 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		top_pos(char c, t_fill_gen *g)
{
	int x;
	int y;

	y = 0;
	while (g->map.size[y])
	{
		x = 0;
		while (g->map.size[y][x])
		{
			if (g->map.size[y][x] == c || g->map.size[y][x] == c + 32)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int		bot_pos(char c, t_fill_gen *g)
{
	int x;
	int y;

	y = g->map.y;
	while (--y >= 0)
	{
		x = g->map.x;
		while (--x >= 0)
		{
			if (g->map.size[y][x] == c || g->map.size[y][x] == c + 32)
				return (y);
		}
	}
	return (0);
}

int		left_pos(char c, t_fill_gen *g)
{
	int x;
	int y;
	int l;

	l = g->map.x + 1;
	y = -1;
	while (g->map.size[++y])
	{
		x = -1;
		while (g->map.size[y][++x])
		{
			if ((g->map.size[y][x] == c || g->map.size[y][x] == c + 32)
				&& l > x)
				l = x;
		}
	}
	return (l);
}

int		right_pos(char c, t_fill_gen *g)
{
	int x;
	int y;
	int r;

	y = 0;
	r = 0;
	while (g->map.size[y])
	{
		x = 0;
		while (g->map.size[y][x])
		{
			if ((g->map.size[y][x] == c || g->map.size[y][x] == c + 32)
				&& r < x)
				r = x;
			x++;
		}
		y++;
	}
	return (r);
}
