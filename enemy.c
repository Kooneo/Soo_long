/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakour <zbakour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:13:17 by zbakour           #+#    #+#             */
/*   Updated: 2025/02/18 17:58:04 by zbakour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	new_x;
	int	new_y;

	new_x = enemy->x + enemy->direction;
	new_y = enemy->y;
	if (game->map->ptr[new_y][new_x] == '1')
		enemy->direction *= -1;
	else
	{
		game->map->ptr[enemy->y][enemy->x] = '0';
		render_image(game, "textures/bg_64n.xpm", enemy->x * TILE_SIZE, enemy->y
			* TILE_SIZE);
		enemy->x = new_x;
		game->map->ptr[enemy->y][enemy->x] = 'T';
		render_image(game, "textures/env/enemy.xpm", new_x * TILE_SIZE, enemy->y
			* TILE_SIZE);
	}
}

// void	move_enemy_vertical(t_game *game, t_enemy *enemy)
// {
// 	int	new_y;

// 	new_y = enemy->y + enemy->direction;
// 	int new_x = enemy->x;
// 	if (game->map->ptr[new_y][new_x] == '1')
// 		enemy->direction *= -1;
// 	else
// 	{
// 		game->map->ptr[enemy->y][enemy->x] = '0';
// 		enemy->y = new_y;
// 		game->map->ptr[enemy->y][enemy->x] = 'T';
// 	}
// }

void	print_map(t_game *g)
{
	for (size_t i = 0; i < g->map->y; i++)
	{
		for (size_t j = 0; j < g->map->x; j++)
		{
			ft_printf("%c", g->map->ptr[i][j]);
		}
	}
}