/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:06 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/09 20:17:37 by schoukou         ###   ########.fr       */
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

t_g    *init_globals()
{
    t_g *g;

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

void    draw(t_cubd *cub)
{
    int i;
    int x;

    cub->texture[0].img = mlx_xpm_file_to_image(cub->mlx, cub->no, &i, &x);
    if(cub->texture[0].img == NULL)
        exit(1);
    cub->texture[0].add = mlx_get_data_addr(cub->texture[0].img, &cub->texture[0].bp, &cub->texture[0].len, &cub->texture[0].end);
    cub->texture[1].img = mlx_xpm_file_to_image(cub->mlx, cub->ea, &i, &x);
    if(cub->texture[1].img == NULL)
        exit(1);
    cub->texture[1].add = mlx_get_data_addr(cub->texture[1].img, &cub->texture[1].bp, &cub->texture[1].len, &cub->texture[0].end);
    cub->texture[2].img = mlx_xpm_file_to_image(cub->mlx, cub->we, &i, &x);
    if(cub->texture[2].img == NULL)
        exit(1);
    cub->texture[2].add = mlx_get_data_addr(cub->texture[2].img, &cub->texture[2].bp, &cub->texture[2].len, &cub->texture[0].end);
    cub->texture[3].img = mlx_xpm_file_to_image(cub->mlx, cub->so, &i, &x);
    if(cub->texture[3].img == NULL)
        exit(1);
    cub->texture[3].add = mlx_get_data_addr(cub->texture[3].img, &cub->texture[3].bp, &cub->texture[3].len, &cub->texture[0].end);
    draw_rays(cub);
    generate3d(cub);
}

int main(int ac, char **av)
{
    t_cubd *cub;
    int i = 0;

    if(ac != 2)
        return(0);
    cub = malloc(sizeof(t_cubd));
    cub = return_map(av[1], cub);
    check_map(cub);
    cub->x_player = cub->x_player * TILE_SIZE + TILE_SIZE / 2;
    cub->y_player = cub->y_player * TILE_SIZE + TILE_SIZE / 2;
    cub->rays = malloc(sizeof(t_rays *) * NUM_RAYS);
    cub->texture = malloc(sizeof(t_texture) * 4);
    while(i < NUM_RAYS)
    {
        cub->rays[i] = malloc(sizeof(t_rays));
        i++;
    }
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx,WIN_WITH ,WIN_HIGHT, "CUB3D");
    cub->img = mlx_new_image(cub->mlx, WIN_WITH, WIN_HIGHT);
    cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
    draw(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    mlx_hook(cub->win, 2, 0, manag, cub);
    mlx_loop_hook(cub->mlx, new_map, cub);
    mlx_hook(cub->win, 17, 1L << 0, exit_mouse, &cub);
    mlx_loop(cub->mlx);
}
