/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:05:46 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/01/04 16:05:48 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		finish(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_loop(t_fill_gen *g)
{
	magic_piece(g);
	if_the_best(g);
	mlx_do_sync(g->mlx.mlx_ptr);
	return (0);
}

void	quit(char *s, t_fill_gen *g)
{
	if (g->piece.size)
		ft_del_strsplit(g->piece.size);
	if (g->map.size)
		ft_del_strsplit(g->map.size);
	if (g->mlx.mlx_ptr)
		free(g->mlx.mlx_ptr);
	if (g->mlx.win_ptr)
		mlx_destroy_window(g->mlx.mlx_ptr, g->mlx.win_ptr);
	if (!ft_strcmp(s, "Reading error\n"))
	{
		ft_printf("{RED}{SET:BO}Reading error{OFF}\n");
		exit(1);
	}
	else if (!ft_strcmp(s, "Initialization error\n"))
	{
		ft_printf("{RED}{SET:BO}Initialization error{OFF}\n");
		exit(1);
	}
	exit(0);
}

int		main(void)
{
	t_fill_gen	g;
	char		*line;

	ft_bzero(&g, sizeof(g));
	get_human_data(&g);
	get_next_line(0, &line);
	get_map_data(&g, line);
	get_mlx_data(&g);
	free(line);
	get_next_line(0, &line);
	get_piece_data(line, &g);
	free(line);
	fill_piece(&g);
	mlx_do_sync(g.mlx.mlx_ptr);
	mlx_hook(g.mlx.win_ptr, 2, 2, finish, &g);
	mlx_loop_hook(g.mlx.mlx_ptr, ft_loop, &g);
	mlx_loop(g.mlx.mlx_ptr);
	quit(NULL, &g);
	return (0);
}
