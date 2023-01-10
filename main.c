/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:58:27 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/04 01:08:35 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
   int fd;
   map_elmnt elmnt;

   fd = check(ac, av[1]);
   elmnt.map = check_map(fd, &elmnt);
   game_init(elmnt);
   return(0);
}

// int main(int ac, char **av)
// {
//     char    **map;
//     map_elmnt  elmnt;
    
//     elmnt= malloc(sizeof(map_elmnt));
//     map = check_map(av[1], &elmnt);
//     elmnt.id = mlx_init ();
//     elmnt.w_id = mlx_new_window (elmnt.id, 300, 300, "so_long");
//     mlx_pixel_put(elmnt.id, elmnt.w_id, 250, 250, "\033[0;91m");
//     mlx_new_image(elmnt.id, 300, 300);
//     mlx_key_hook(elmnt.id, deal_key, &elmnt);
//     mlx_loop(elmnt.id);
//     return(0);
// }


    