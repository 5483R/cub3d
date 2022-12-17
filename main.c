/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/11 09:18:02 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_mouse(int key)
{
	if (key < 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	return (0);
}

t_g	*init_globals(void)
{
	t_g	*g;

	g = malloc(sizeof(t_g));
	g->flag_no = 1;
	g->flag_so = 1;
	g->flag_we = 1;
	g->flag_ea = 1;
	g->flag_f = 1;
	g->flag_c = 1;
	g->take_the_map = 6;
	return (g);
}

void	check_tx(t_cubd *cub, int index)
{
	if (cub->tx[index].img == NULL)
	{
		printf("error tx\n");
		exit(1);
	}
}

void	draw(t_cubd *cub)
{
	int	i;
	int	x;

	cub->tx[0].img = mlx_xpm_file_to_image(cub->mlx, cub->no, &i, &x);
	check_tx(cub, 0);
	cub->tx[0].add = mlx_get_data_addr(cub->tx[0].img,
			&cub->tx[0].bp, &cub->tx[0].len, &cub->tx[0].end);
	cub->tx[1].img = mlx_xpm_file_to_image(cub->mlx, cub->ea, &i, &x);
	check_tx(cub, 1);
	cub->tx[1].add = mlx_get_data_addr(cub->tx[1].img,
			&cub->tx[1].bp, &cub->tx[1].len, &cub->tx[0].end);
	cub->tx[2].img = mlx_xpm_file_to_image(cub->mlx, cub->we, &i, &x);
	check_tx(cub, 2);
	cub->tx[2].add = mlx_get_data_addr(cub->tx[2].img,
			&cub->tx[2].bp, &cub->tx[2].len, &cub->tx[0].end);
	cub->tx[3].img = mlx_xpm_file_to_image(cub->mlx, cub->so, &i, &x);
	check_tx(cub, 3);
	cub->tx[3].add = mlx_get_data_addr(cub->tx[3].img,
			&cub->tx[3].bp, &cub->tx[3].len, &cub->tx[0].end);
	draw_rays(cub);
	generate3d(cub);
}

int	main(int ac, char **av)
{
	t_cubd	*cub;
	int		i;

	i = 0;
	if (ac != 2)
		return (0);
	cub = malloc(sizeof(t_cubd));
	cub = return_map(av[1], cub);
	cub->todmap = get_info_of2d(cub);
	cub->x_p = cub->x_p * TILE_SIZE + TILE_SIZE / 2;
	cub->y_p = cub->y_p * TILE_SIZE + TILE_SIZE / 2;
	cub->rays = malloc(sizeof(t_rays *) * NUM_RAYS);
	cub->tx = malloc(sizeof(t_tx) * 4);
	while (i < NUM_RAYS)
		cub->rays[i++] = malloc(sizeof(t_rays));
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIN_WITH, WIN_HIGHT, "CUB3D");
	cub->img = mlx_new_image(cub->mlx, WIN_WITH, WIN_HIGHT);
	cub->add = (int *)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
	draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	mlx_hook(cub->win, 2, 0, manag, cub);
	mlx_loop_hook(cub->mlx, new_map, cub);
	mlx_hook(cub->win, 17, 1L << 0, exit_mouse, &cub);
	mlx_loop(cub->mlx);
}
