/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:33:23 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/07 19:49:01 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TODMAP_H
#define TODMAP_H
#include "../cub3d.h"

# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
#define FACE_UP 300
#define FACE_DOWN 400
#define FACE_RIGHT 500
#define FACE_LEFT 600
#define HORZ 55

t_tood	*get_info_of2d(cub3d_t *cub);
int		calc_with(char **map);
int		calc_hight(char **map);
// void    draw_2d_map(cub3d_t *cub);
void    draw_car(cub3d_t *cub, int i, int j);
int     manag(int keycode, cub3d_t *cub);
int     new_map(cub3d_t *cub);
void    draw_rays(cub3d_t *cub);
void    pixelput(cub3d_t *cub, int x, int y, int color);
void    draw_walls(cub3d_t *cub);
void    draw_player(cub3d_t *cub);
void    draw_angl_view(cub3d_t *cub);
double  normalizeangle(double rayangle);
void    cast_ray(double rayangle, int ray, cub3d_t *cub);
int     face_up_down(double angle);
int     face_right_left(double angle);
int     map_has_wall(cub3d_t *cub, double x, double y);
void    draw(cub3d_t *cub);
void    render_2d_map(cub3d_t *cub);
char     mapHasWallAt(cub3d_t *cub, float x, float y);
void generate3d(cub3d_t *cub);
void pixelput_3d(cub3d_t *cub, int x,int y, int color);
#endif
