/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:09:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/09 15:08:23 by ael-kouc         ###   ########.fr       */
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

#endif