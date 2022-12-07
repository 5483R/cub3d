#include "cub3d.h"

int direction(cub3d_t* cub, int ray){

    //North
    if (cub->map[((int)(cub->rays[ray]->wallHity + 1)) / TILE_SIZE][(int)cub->rays[ray]->wallHitx / TILE_SIZE] == '0') 
        return (1);
    //west
    if (cub->map[(int)cub->rays[ray]->wallHity / TILE_SIZE][((int)(cub->rays[ray]->wallHitx + 1)) / TILE_SIZE]  == '0') 
        return (2);
    //South
    if (cub->map[((int)(cub->rays[ray]->wallHity - 1)) / TILE_SIZE][(int)cub->rays[ray]->wallHitx / TILE_SIZE]  == '0') 
        return (3);
    //Ew
    if (cub->map[(int)cub->rays[ray]->wallHity / TILE_SIZE][((int)(cub->rays[ray]->wallHitx - 1)) / TILE_SIZE]  == '0') 
        return (4);
    
    return (0);
}
void generate3d(cub3d_t *cub)
{
	int	y;
	int	x;
	double i;
    int ray;
    int textureoffset_x;
    char *dst;
    //double textureoffset_y;
    //
    //textureoffset_y = (int)cub->rays[ray]->wallHity % TILE_SIZE;

    
    ray = 0;
	i = 0;
    x = 0;
    y = cub->rays[ray]->walltoppixel;
    // while (y < cub->rays[ray]->wallbottompixel)
    // {
    //     textureoffset_y = (y - cub->rays[ray]->walltoppixel) * ((float)TILE_SIZE / cub->rays[ray]->wallsheight);
    //     y++;
    // }
    
    while (ray < NUM_RAYS)
    {
        int j = 0;
        while (j < cub->rays[ray]->walltoppixel)
        {
            pixelput(cub, ray, j, 0x4B3D60);
            j++;
        }
        i = j;
        if(direction(cub, ray) == 2 || direction(cub, ray) == 4)
            textureoffset_x = (int)cub->rays[ray]->wallHity % TILE_SIZE;
        else
            textureoffset_x = (int)cub->rays[ray]->wallHitx % TILE_SIZE;
        while (i < cub->rays[ray]->wallbottompixel)
        {
		    int distancefromtop = i + (cub->rays[ray]->wallsheight / 2) - (WIN_HIGHT / 2);
            int textureoffset_y = distancefromtop * ((float)TILE_SIZE / cub->rays[ray]->wallsheight);
            if (direction(cub, ray) == 1)
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 0));
            if (direction(cub, ray) == 3 )
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 1));
            if (direction(cub, ray) == 2 )
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 2));
            if (direction(cub, ray) == 4)
                pixelput(cub, ray, i, pixelget(cub, textureoffset_x,textureoffset_y, 3));
            i++;
        }
		j = cub->rays[ray]->wallbottompixel;
        while(j < WIN_HIGHT)
		{
            pixelput(cub, ray, j, 0x17062e);
			j++;
		}
        ray++;
    }

}
// int rgb_to_int(double r, double g, double b)
// {
//     int color = 0;
//     color |= (int)(b * 255);
//     color |= (int)(g * 255) << 8;
//     color |= (int)(r * 255) << 16;
//     return (color);
// }
// int check_side(cub3d_t *cub)
// {
    
// }

