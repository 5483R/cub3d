/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:30:28 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/25 22:09:35 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double  normalizeangle(double rayangle)
{
    rayangle = remainder(rayangle ,  2 * M_PI);
    if(rayangle < 0)
        rayangle = (2 * M_PI) + rayangle;
    return(rayangle);
}

double distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// // void    hor(double rayangle, int ray, cub3d_t *cub)
// // {
// //     int isRayFacingDown = rayangle > 0 && rayangle < PI;
// //     int isRayFacingUp = !isRayFacingDown;

// //     int isRayFacingRight = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
// //     int isRayFacingLeft = !isRayFacingRight;
    
// //     float xintercept, yintercept;
// //     float xstep, ystep;

// //     float horzWallHitX = 0;
// //     float horzWallHitY = 0;


// //     yintercept = floor(cub->y_player / TILE_SIZE) * TILE_SIZE;
// //     yintercept += isRayFacingDown ? TILE_SIZE : 0;


// //     xintercept = cub->x_player + (yintercept - cub->y_player) / tan(rayangle);


// //     ystep = TILE_SIZE;
// //     ystep *= isRayFacingUp ? -1 : 1;

// //     xstep = TILE_SIZE / tan(rayangle);
// //     xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
// //     xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

// //     float nextHorzTouchX = xintercept;
// //     float nextHorzTouchY = yintercept;

// //     while (nextHorzTouchX > 0 && nextHorzTouchX < cub->todmap->with && nextHorzTouchY > 0 && nextHorzTouchY < cub->todmap->hight ){
// //         float xToCheck = nextHorzTouchX;
// //         float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
        
// //         if (mapHasWallAt(cub, xToCheck, yToCheck)) {
// //             cub->rays[ray].HwallHitx =  nextHorzTouchX;
// //             cub->rays[ray].HwallHity =  nextHorzTouchY;
// //             cub->rays[ray].distanceH = distanceBetweenPoints(cub->x_player, cub->y_player, nextHorzTouchX, nextHorzTouchY);
// //             break;
// //         } else {
// //             nextHorzTouchX += xstep;
// //             nextHorzTouchY += ystep;
// //         }
// //     }
// // }

// // void    ver(double rayangle, int ray, cub3d_t *cub)
// // {
// //     float vertWallHitX = 0;
// //     float vertWallHitY = 0;

// //     int isRayFacingDown = rayangle > 0 && rayangle < M_PI;
// //     int isRayFacingUp = !isRayFacingDown;

// //     int isRayFacingRight = rayangle < 0.5 * M_PI || rayangle > 1.5 * M_PI;
// //     int isRayFacingLeft = !isRayFacingRight;
    
// //     float xintercept, yintercept;
// //     float xstep, ystep;
    
// //     xintercept = floor(cub->x_player / TILE_SIZE) * TILE_SIZE;
// //     xintercept += isRayFacingRight ? TILE_SIZE : 0;

// //     yintercept = cub->y_player + (xintercept - cub->x_player) * tan(rayangle);

// //     xstep = TILE_SIZE;
// //     xstep *= isRayFacingLeft ? -1 : 1;

// //     ystep = TILE_SIZE * tan(rayangle);
// //     ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
// //     ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

// //     float nextVertTouchX = xintercept;
// //     float nextVertTouchY = yintercept;

// //     while (nextVertTouchX > 0 && nextVertTouchX < cub->todmap->with && nextVertTouchY > 0 && nextVertTouchY < cub->todmap->hight ) {
// //         float xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
// //         float yToCheck = nextVertTouchY;
        
// //         if (mapHasWallAt(cub, xToCheck, yToCheck)) {
// //             cub->rays[ray].VwallHitx = nextVertTouchX;
// //             cub->rays[ray].VwallHity = nextVertTouchY;
// //             cub->rays[ray].distanceV = distanceBetweenPoints(cub->x_player, cub->y_player, nextVertTouchX, nextVertTouchY);
// //             break;
// //         } else {
// //             nextVertTouchX += xstep;
// //             nextVertTouchY += ystep;
// //         }
// //     }
// // }


// // double    cast_ray_ray(double rayangle, int ray, cub3d_t *cub)
// // {
// //     rayangle = normalizeangle(rayangle);
// //     hor(rayangle, ray, cub);
// //     ver(rayangle, ray, cub);
// //     cub->rays[ray].rayangle = rayangle;
// //     if(cub->rays[ray].distanceV > cub->rays[ray].distanceH)
// //         return(cub->rays[ray].distanceH);
// //     else
// //         return(cub->rays[ray].distanceV);
    
// // }
// double find_vertic_hit(double rayangle, int ray, cub3d_t *cub)
// {
//     double xintercept, yintercept;
//     double xstep, ystep;
//     double horzWallHitX;
//     double horzWallHitY;

//     xstep = 0;
//     ystep = 0;
    
//     xintercept = floor(cub->y_player / TILE_SIZE) * TILE_SIZE;
//     if(face_right_left(rayangle) == FACE_RIGHT)
//         xintercept += TILE_SIZE;
//     yintercept = cub->y_player + (xintercept - cub->x_player) / tan(rayangle);
//     xstep = TILE_SIZE;
//     if(face_right_left(rayangle) == FACE_LEFT)
//         xstep *= -1;
//     ystep = TILE_SIZE / tan(rayangle);
//     if(face_up_down(rayangle) == FACE_UP && ystep > 0)
//         ystep *= -1;
//     if(face_up_down(rayangle) == FACE_DOWN && ystep < 0)
//         ystep *= -1;
//     double nextHorzTouchX = xintercept;
//     double nextHorzTouchY = yintercept;
//     while(1)
//     {
//         double xToCheck = nextHorzTouchX;
//         double yToCheck = nextHorzTouchY; 
//         if(face_up_down(rayangle) == FACE_UP)
//             xToCheck -= 1;
//         if(mapHasWallAt(cub, xToCheck, yToCheck) != '0')
//             return(distanceBetweenPoints(cub->x_player , cub->y_player, nextHorzTouchX, nextHorzTouchY));
//         else{
//         nextHorzTouchX += xstep;
//         nextHorzTouchY += ystep;}
//     }
//     return(5000);
// }

// double find_horiz_hit(double rayangle, int ray, cub3d_t *cub)
// {
//     double xintercept, yintercept;
//     double xstep, ystep;
//     double horzWallHitX;
//     double horzWallHitY;

//     xstep = 0;
//     ystep = 0;
    
//     yintercept = floor(cub->y_player / TILE_SIZE) * TILE_SIZE;
//     if(face_up_down(rayangle) == FACE_DOWN)
//         yintercept += TILE_SIZE;
//     xintercept = cub->x_player + (yintercept - cub->y_player) / tan(rayangle);
//     ystep = TILE_SIZE;
//     if(face_up_down(rayangle) == FACE_UP)
//         ystep *= -1;
//     xstep = TILE_SIZE / tan(rayangle);
//     if(face_right_left(rayangle) == FACE_LEFT && xstep > 0)
//         xstep *= -1;
//     if(face_right_left(rayangle) == FACE_RIGHT && xstep < 0)
//         xstep *= -1;
//     // exit(0);
//     double nextHorzTouchX = xintercept;
//     double nextHorzTouchY = yintercept;
//     while(1)
//     {
//         double xToCheck = nextHorzTouchX;
//         double yToCheck = nextHorzTouchY; 
//         if(face_up_down(rayangle) == FACE_UP)
//             yToCheck -= 1;
//         if(mapHasWallAt(cub, xToCheck, yToCheck) != '0')
//             return(distanceBetweenPoints(cub->x_player , cub->y_player, nextHorzTouchX, nextHorzTouchY));
//         else
//         {
//             nextHorzTouchX += xstep;
//             nextHorzTouchY += ystep;
//         }
//     }
//     return(5000);
// }

// double  cast_allrays(double rayangle, int ray, cub3d_t *cub)
// {
//     double distance;
//     double vertical;
//     double horizental;

//     rayangle = normalizeangle(rayangle);
//     horizental = find_horiz_hit(rayangle, ray, cub);
//     vertical = find_vertic_hit(rayangle, ray, cub);
//     if(horizental < vertical)
//     {
//         cub->distances[ray] = horizental;
//         return(horizental);
//     }
//     cub->distances[ray]= vertical;
//     return(vertical);
// }

// void    cast_rays(cub3d_t *cub)
// {
//     double rayangle;
//     int    index_ray;
//     int i ;
//     double distance;

//     index_ray = 0;
//     rayangle = cub->ang - (FOV_ANGLE / 2);
//     while(index_ray < NUM_RAYS)
//     {
//         // i = 0;
//         distance = cast_allrays(rayangle, index_ray, cub);
//         for(int j; j < cub->distances[index_ray] ; j++)
//             pixelput(cub, (cub->x_player  - cos(rayangle) * i) , (cub->y_player  - sin(rayangle) * i), 0xff0000);
//         rayangle += FOV_ANGLE / NUM_RAYS;
//         index_ray++;
//     }
//     for(int i ; i < NUM_RAYS ; i++)
//     {
//         for(int j; j < cub->distances[i] ; j++)
//             pixelput(cub, (cub->x_player  - cos(rayangle) * i) , (cub->y_player  - sin(rayangle) * i), 0xff0000);
//     }
// }