#include "so_long.h"
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// int deal_key(int key, void *param)
// {
//     key += '0';
//     write(1,&key, 1);
//     param = 0;
//     //mlx_pixel_put(ptr->id, ptr->w_id, 250, 250, );
//     return (0);
// }

void    ft_display_item(char *path,int i,int j,map_elmnt *elmnt)
{
    int w;
    int h;
    elmnt->img= mlx_xpm_file_to_image(elmnt->id, path, &w, &h);
    if(!elmnt->img)
        ft_error("Error : corrupted xpm",NULL);
    mlx_put_image_to_window(elmnt->id, elmnt->w_id, elmnt->img,60 *j, 60 * i);
}
void    ft_display(char **map,map_elmnt *elmnt)
{
    int i;
    int j;

    i = 0;
    while ((map[i]))
    {
        j=0;
        while (map[i][j])
        {
            if(map[i][j]=='1')
                ft_display_item("./textures/wall.xpm",i,j,elmnt);
            if(map[i][j]=='0' || map[i][j]=='C' || map[i][j]=='P')
                ft_display_item("./textures/background.xpm",i,j,elmnt);
            if(map[i][j]=='P')
                ft_display_item("./textures/player.xpm",i,j,elmnt);
            if(map[i][j]=='C')
                ft_display_item("./textures/collectible.xpm",i,j,elmnt);
            if(map[i][j]=='E')
                ft_display_item("./textures/door.xpm",i,j,elmnt);
            j++;
        }
        i++;
    }
}
int	deal_key(int key, map_elmnt *elmnt)
{
    position    p;
    static int  count;
    static int  check;
    static int     c;

    p = ft_get_position(elmnt->map);
    if(key == ESC)
    {
        write(1, "You closed the game using ESC key !",35);
        mlx_destroy_window(elmnt->id, elmnt->w_id);
        exit(0);
    }
    if (c == elmnt->collct)
		check = 1;
    if(key== UP || key== 13)
        count+= ft_move_up(p,elmnt,check,&c, count);
    if(key== RIGHT|| key== 2)
        count+= ft_move_right(p,elmnt,check,&c, count);
    if(key== LEFT || key==0)
        count+= ft_move_left(p,elmnt,check,&c, count);
    if(key== DOWN || key==1)
        count+= ft_move_down(p,elmnt,check,&c, count);
    
    return(0);
}
void game_init(map_elmnt elmnt)
{
   elmnt.id = mlx_init ();
   elmnt.w_id= mlx_new_window (elmnt.id, 60 * elmnt.col, 60 * elmnt.row, "so_long");
   ft_display(elmnt.map,&elmnt);
   mlx_hook(elmnt.w_id, 2, 0, deal_key, &elmnt);
//    mlx_hook(elmnt.w_id, 17, 0, closed, &elmnt);
// 	mlx_loop_hook(elmnt.id, animate, &elmnt);
    mlx_loop(elmnt.id);
}
// void game_init(map_elmnt elmnt)
// {
//     t_data	img;

//    elmnt.id = mlx_init ();
//    elmnt.w_id= mlx_new_window (elmnt.id, 1000, 1000, "so_long");
    
//     img.img=mlx_new_image(elmnt.id, 500, 500);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//     mlx_pixel_put(elmnt.id, elmnt.w_id, 5, 5,0xFF5733 );
//     mlx_put_image_to_window(img.img, elmnt.w_id, img.img,0 ,0);
//    //mlx_key_hook(elmnt.w_id, deal_key, (void*)0);
//     mlx_loop(elmnt.id);
// }
// int deal_key(int key, map_elmnt *ptr)
// {
//     write(1,"x", 1);
//     key= 0;
//     //mlx_pixel_put(ptr->id, ptr->w_id, 250, 250, );
//     return (0);
// }

// void game_init(map_elmnt elmnt)
// {
//    void *mlx_ptr;
//    void *win_ptr;
//    elmnt.id = mlx_init ();
//    elmnt.w_id= mlx_new_window (elmnt.id, 500, 500, "so_long");
//     mlx_pixel_put(elmnt.id, elmnt.w_id, 250, 250, 0xFFFFFF );
//     //mlx_new_image(elmnt.id, 300, 300);
//     mlx_key_hook(elmnt.w_id, deal_key, &elmnt);
//     mlx_loop(elmnt.id);
// }