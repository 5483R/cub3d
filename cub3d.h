/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/05 22:02:23 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

///////////////////////////
#include "./get_next_line/get_next_line.h"
#include "./libftt/libft.h"
#include "./parsing/pars.h"
#include "./2DMAP/todmap.h"
#include "./raycast/raycast.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>
//////////////////////////
# define PI 3.14159265
# define TOW_PI 6.28318530
# define BUFFER_SIZE 1
# define _SIZE 64
# define FOV_ANGLE 60 * (M_PI / 180)
# define INCR 0.0349066
# define WIN_WITH 2000
# define WIN_HIGHT 1000
# define NUM_RAYS (WIN_WITH)
# define TILE_SIZE 64



//////////////////////////
// typedef struct cub3d_t
// {
//     void	*mlx;
// 	void	*win;
//     int     x_player;
//     int     y_player;
//     char    direction;
//     int     f_col[2];
//     int     c_col[2];
//     char    **map;
//     char    **info;
//     char    *NO;
//     char    *SO;
//     char    *EA;
//     char    *WE;
// }   cub3d_t;

// typedef struct nd_t
// {
// 	void	*hero;
// 	void	*colec;
// 	void	*exi;
// }   nd_t;
/////////////////////////////////////
cub3d_t *init_cub(char *str);
#endif