/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:09:17 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/11 17:09:18 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	put_top_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = -g->piece.y;
	while (++y < g->map.y)
	{
		x = -g->piece.x;
		while (++x < g->map.x)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
		}
	}
}

void	put_bot_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = g->map.y;
	while (--y >= 0)
	{
		x = g->map.x;
		while (--x >= 0)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
		}
	}
}

void	put_left_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = g->map.y;
	while (--y >= 0)
	{
		x = -g->piece.x;
		while (++x < g->map.x)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
		}
	}
}

void	put_right_pos(t_fill_gen *g)
{
	int x;
	int y;

	y = -g->piece.y;
	while (++y < g->map.y)
	{
		x = g->map.x;
		while (--x >= 0)
		{
			if (is_safe(x, y, g))
			{
				g->fill.x = x;
				g->fill.y = y;
				return ;
			}
		}
	}
}
