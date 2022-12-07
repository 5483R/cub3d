/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/07 19:48:27 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void pixelput(cub3d_t *cub, int x,int y, int color)
{
    if(x >= 0 && x < WIN_WITH && y >= 0 && y < WIN_HIGHT)
        cub->add[x + y * WIN_WITH] = color;
}
unsigned int	pixelget(cub3d_t *cub, int x,int y, int i)
{
	char *color;
	color = cub->texture[i].add + y * cub->texture[i].len + x * (cub->texture[i].bp / 8);
	return (*(int*)color);
}
// unsigned int pixelget(cub3d_t *cub, int x,int y)
// {
//     int color;
//     color = cub->texture->add[cub->texture->bp / 8 * x + y * cub->texture->len];
//     return color;
// }

// void get_add_xml(cub3d_t *cub)
// {
//     int i;
//     int x;

//     if (cub->mlx)
//     {
//         cub->texture->img = mlx_xpm_file_to_image(cub->mlx, "barrel.xpm", &i, &x);
//     }
//     if (cub->texture->img)
//         cub->texture->add = mlx_get_data_addr(cub->texture->img, &cub->texture->bp, &cub->texture->len, &cub->texture->end);
//     else
//         printf("here\n");
//         exit(0);
// }
void    draw_car(cub3d_t *cub, int i, int j)
{
    int x = 0;
    int y = 0;
    while(y < TILE_SIZE)
    {
        x = 0;
        while(x < TILE_SIZE)
        {
            pixelput(cub, j * TILE_SIZE + x , i * TILE_SIZE + y, 0xFF);
            x++;
        }
        y++;
    }
}

void    draw_player(cub3d_t *cub)
{
    int i = 0;

    while (i < 360)
    {
        pixelput(cub, ((cub->x_player) + cos(i) * 2), ((cub->y_player) + sin(i) * 2), 0xff0000);
        i++;
    }
}

// void    draw_angl_view(cub3d_t *cub)
// {
//     int i = 0;

//     while (i < 30)
//     {
//         pixelput(cub, (cub->x_player - cos(cub->ang) * i), (cub->y_player - sin(cub->ang) * i), 0xff0000);
//         i++;
//     }
// }


int manag(int keycode, cub3d_t * cub)
{
    double posx;
    double posy;
    
    if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == KEY_D)
    {
        posx = cub->x_player - 11  * cos(cub->ang + 1.5708);
        posy = cub->y_player - 11  * sin(cub->ang + 1.5708);
        if(map_has_wall(cub, posx, posy))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
	else if (keycode == KEY_A)
    {
        posx = cub->x_player + 11  * cos(cub->ang + 1.5708);
        posy = cub->y_player + 11  * sin(cub->ang + 1.5708);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if ((keycode == KEY_DOWN || keycode == KEY_S))
    {
        posx = cub->x_player + 11 * cos(cub->ang);
        posy = cub->y_player + 11 * sin(cub->ang);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if ((keycode == KEY_UP || keycode == KEY_W))
    {
        posx = cub->x_player - 11 * cos(cub->ang);
        posy = cub->y_player - 11 * sin(cub->ang);
        if(map_has_wall(cub, posx, posy) && map_has_wall(cub, cub->x_player, posy)
            && map_has_wall(cub, posx, cub->y_player))
        {
            cub->x_player = posx;
            cub->y_player = posy;
        }
    }
    else if (keycode == KEY_LEFT)
    {
        cub->ang -= 0.25;
    }
    else if (keycode == KEY_RIGHT)
    {
        cub->ang += 0.25;
    }
	return (1);
}

int new_map(cub3d_t *cub)
{
    mlx_destroy_image(cub->mlx, cub->img);
    cub->img = mlx_new_image(cub->mlx, WIN_WITH,WIN_HIGHT);
    cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
    draw(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    return(0);
}


/////////////////////////////////////////////////////
//////////////CHECK_IF_WALL//////////////////////////
/////////////////////////////////////////////////////



//===========>
char mapHasWallAt(cub3d_t *cub, float x, float y) {
    if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
        return('1');
    int mapGridIndexX = floor(x / TILE_SIZE);
    int mapGridIndexY = floor(y / TILE_SIZE);
    return(cub->map[mapGridIndexY][mapGridIndexX]) != '0';
}
int map_has_wall(cub3d_t *cub, double x, double y)
{
    int x_check;
    int y_check;
    if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
        return(0);
    x_check = (int)floor(x / TILE_SIZE);
    y_check = (int)floor(y / TILE_SIZE);
    if (cub->map[y_check][x_check] != '1')
        return(1);
    return(0);
}


/////////////////////////////////////////////////////
//////////DRAW_RAYS///////////////////////////////////
/////////////////////////////////////////////////////



//==============>
double calculate_distance(cub3d_t *cub,double x,double y){
    return (sqrt(pow(cub->x_player - x, 2) + pow(cub->y_player - y, 2)));
}

void  ray_distance(cub3d_t *cub, double rayangle, int ray)
{
    
    double i = 0;
    double x_check;
    double y_check;
    double distancedis;

    cub->rays[ray]->projectionplan = (WIN_WITH / 2 ) / tan(FOV_ANGLE / 2) - 150;
    while(i >= 0 && (i < WIN_WITH || i < WIN_HIGHT))
    {
        x_check = cub->x_player - cos(rayangle) * i;
        y_check = cub->y_player - sin(rayangle) * i;
        if (!map_has_wall(cub,  x_check , y_check ) ||  !map_has_wall(cub, x_check, cub->y_player - sin(rayangle) * (i - 1))
            || !map_has_wall(cub, cub->x_player  - cos(rayangle) * (i - 1), y_check))
        {
            cub->rays[ray]->wallHitx = x_check;
            cub->rays[ray]->wallHity = y_check;
            cub->rays[ray]->rayangle = rayangle;
            distancedis = calculate_distance(cub,(cub->x_player - cos(rayangle) * i) ,(cub->y_player - sin(rayangle) * i));
            cub->rays[ray]->distance = distancedis * cos(cub->rays[ray]->rayangle - cub->ang);
            cub->rays[ray]->projectiowalls = (TILE_SIZE / cub->rays[ray]->distance) * cub->rays[ray]->projectionplan;
            cub->rays[ray]->wallsheight = (int)cub->rays[ray]->projectiowalls;
            cub->rays[ray]->walltoppixel = (WIN_HIGHT / 2) - (cub->rays[ray]->wallsheight / 2);
            cub->rays[ray]->walltoppixel = cub->rays[ray]->walltoppixel  < 0 ? 0 : cub->rays[ray]->walltoppixel;
            cub->rays[ray]->wallbottompixel = (WIN_HIGHT / 2) + (cub->rays[ray]->wallsheight / 2);
            cub->rays[ray]->wallbottompixel = cub->rays[ray]->wallbottompixel > WIN_HIGHT ? WIN_HIGHT : cub->rays[ray]->wallbottompixel;
            break ;
        }
        i += 0.3;
    }
}
void    draw_rays(cub3d_t *cub)
{
    double rayangle;
    int ray;
    int i = 0;
    rayangle = cub->ang - 0.5235;
    ray = 0;
    while(rayangle < cub->ang + 0.5235)
    {
        ray_distance(cub, rayangle, ray);
        rayangle += FOV_ANGLE / NUM_RAYS;
        ray++;
    }
}