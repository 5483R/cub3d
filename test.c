// #include <math.h>
// #include "cub3D.h"

// void	get_inter_point(t_data *game, t_raydata *ray, double ang)
// {
// 	double	ray_ang;
// 	double	correcth;
// 	double	correctv;
// 	double	delta_xv = 0;
// 	double	delta_yv = 0;
// 	double	delta_xh = 0;
// 	double	delta_yh = 0;
// 	double	x_ver = 0;
// 	double	y_ver = 0;
// 	double	x_hor = 0;
// 	double	y_hor = 0;
// 	double	d_ver = 0;
// 	double	d_hor = 0;
// 	int	flag_ver = 0;
// 	int	flag_hor = 0;
	
// 	ray_ang =  norm_angle(ang);
// 	///hor_inter code
// 	//first intersection
// 	correcth = 0;
// 	y_hor = floor(game->player_y / CUBE) * CUBE;
// 	if (ray_ang > 0 && ray_ang < M_PI)
// 		y_hor += CUBE;
// 	else
// 		correcth = -1;
// 	x_hor = game->player_x + (y_hor - game->player_y) / tan(ray_ang);
// 	//finding delta x and delta y
// 	delta_yh = CUBE;
// 	if (!(ray_ang > 0 && ray_ang < M_PI))
// 		delta_yh *= -1;
// 	delta_xh = CUBE / tan(ray_ang);
// 	if ((!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && delta_xh > 0) || ((ray_ang < M_PI_2  || ray_ang > 1.5*M_PI) && delta_xh < 0))
// 		delta_xh *= -1;

// 	//ver_inter
// 	//first intersection
// 	correctv = 0;
// 	x_ver = floor(game->player_x / CUBE) * CUBE;
// 	if (ray_ang < M_PI_2  || ray_ang > 1.5*M_PI)
// 		x_ver += CUBE;
// 	else
// 		correctv = -1;
// 	y_ver = game->player_y + (x_ver - game->player_x)*tan(ray_ang);
// 	//finding delta y and delta x
// 	delta_xv = CUBE;
// 	if (!(ray_ang < M_PI_2  || ray_ang > 1.5*M_PI))
// 		delta_xv *= -1;
// 	delta_yv = CUBE * tan(ray_ang);
// 	if ((!(ray_ang > 0 && ray_ang < M_PI) && delta_yv > 0) || ((ray_ang > 0 && ray_ang < M_PI) && delta_yv < 0))
// 		delta_yv *= -1;
// 	while (1)
// 	{
// 		if (x_ver > 0 && y_ver > 0 && x_ver < game->map_width && y_ver < game->map_length)
// 		{
// 			if (wall(game, x_ver + correctv, y_ver, 0) == 1)
// 				break;
// 			x_ver += delta_xv;
// 			y_ver += delta_yv;
// 		}
// 		else
// 		{
// 			flag_ver = -1;
// 			break ;
// 		}
// 	}
// 	while (1)
// 	{
// 		if (x_hor > 0 && y_hor > 0 && x_hor < game->map_width && y_hor < game->map_length)
// 		{
// 			if (wall(game, x_hor, y_hor + correcth, 0) == 1)
// 				break;
// 			x_hor += delta_xh;
// 			y_hor += delta_yh;
// 		}
// 		else
// 		{
// 			flag_hor = -1;
// 			break ;
// 		}
// 	}
// 	if (flag_ver || flag_hor)
// 	{
// 		if (flag_ver)
// 		{
// 			ray->inter_x = x_hor;
// 			ray->inter_y = y_hor;
// 			ray->v_or_h = 'h';
// 		}
// 		else
// 		{
// 			ray->inter_x = x_ver;
// 			ray->inter_y = y_ver;
// 			ray->v_or_h = 'v';
// 		}
// 	}
// 	else
// 	{
// 		d_ver = hypot(game->player_x - x_ver, game->player_y - y_ver);
// 		d_hor = hypot(game->player_x - x_hor, game->player_y - y_hor);
// 		if (d_hor > d_ver)
// 		{
// 			ray->inter_x = x_ver;
// 			ray->inter_y = y_ver;
// 			ray->v_or_h = 'v';
// 		}
// 		else
// 		{
// 			ray->inter_x = x_hor;
// 			ray->inter_y = y_hor;
// 			ray->v_or_h = 'h';
// 		}
// 	}
// 	if (ray_ang > 0 && ray_ang < M_PI && ray->v_or_h == 'h')
// 		ray->wall = 'S';
// 	else if (ray->v_or_h == 'h')
// 		ray->wall = 'N';
// 	 else if (ray_ang < M_PI_2 || ray_ang > 1.5*M_PI)
// 	 	ray->wall = 'E';
// 	else
// 	 	ray->wall = 'W';
// }

// int	wall(t_data *game, double x, double y, int flag)
// {
// 	int	i;
// 	int	j;

// 	if (x < 0 || x > game->map_width || y < 0 || y > game->map_length)
// 		return (2);
// 	i = floor(y / CUBE);
// 	j = floor(x / CUBE);
// 	if (flag)
// 	{
// 		if (wall(game, x, game->player_y, 0) == 1)
// 			return (1);
// 		if (wall(game, game->player_x, y, 0) == 1)
// 			return (1);
// 	}
// 	return (game->map[(int)i][(int)j] - 48);
// }
int main(){
	double i = 0;
	i++;
	i++;
	printf("%f\n", i);
}