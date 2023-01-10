#include "so_long.h"
int ft_move_up(position p, map_elmnt *m)
{
    if(m->map[p.x-1][p.y]== 'E' && m->clc_cnt == m->collct)
    {
        ft_printf( "Move nomber : %d\nCONGRATULATIONS, You won !!", m->mov_cnt+1);
        exit(0);
        return(0);
    }
    else if(m->map[p.x-1][p.y]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x-1][p.y]= 'P';
        m->clc_cnt++;
       ft_printf( "Move nomber : %d\n", m->mov_cnt+1);
       m->mov_cnt++;
       ft_display_item("./textures/background.xpm",p.x,p.y,m);
        ft_display_item("./textures/player.xpm",p.x-1,p.y,m);
        return(1);
    }
    else if(m->map[p.x-1][p.y]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x-1][p.y]= 'P';
       ft_printf( "Move nomber : %d\n",  m->mov_cnt+1);
       ft_display_item("./textures/background.xpm",p.x,p.y,m);
        ft_display_item("./textures/player.xpm",p.x-1,p.y,m);
        m->mov_cnt++;
        return(1);
    }
    //ft_display(m->map,m);
    return(0);
}
int ft_move_right(position p, map_elmnt *m)
{
    if(m->map[p.x][p.y+1]== 'E' && m->clc_cnt == m->collct)
    {
        ft_printf( "Move nomber : %d\nCONGRATULATIONS, You won !!", m->mov_cnt+1);
        exit(0);
        return(0);
    }
    if(m->map[p.x][p.y+1]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x][p.y+1]= 'P';
        m->clc_cnt++;
       ft_printf( "Move nomber : %d\n",  m->mov_cnt+1);
       ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x,p.y+1,m);
    m->mov_cnt++;
        return(1);
    }
    if(m->map[p.x][p.y+1]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x][p.y+1]= 'P';
        ft_printf( "Move nomber : %d\n", m->mov_cnt+1);
        ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x,p.y+1,m);
    m->mov_cnt++;
        return(1);
    }
    
    //ft_display(m->map,m);
    return(0);
}
int ft_move_left(position p, map_elmnt *m)
{
    if(m->map[p.x][p.y-1]== 'E' && m->clc_cnt == m->collct)
    {
       ft_printf( "Move nomber : %d\nCONGRATULATIONS, You won !!",  m->mov_cnt+1);
        exit(0);
        return(0);
    }
    if(m->map[p.x][p.y-1]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x][p.y-1]= 'P';
        m->clc_cnt++;
        ft_printf( "Move nomber : %d\n", m->mov_cnt+1);
        ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x,p.y-1,m);
    m->mov_cnt++;
        return(1);
    }
    if(m->map[p.x][p.y-1]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x][p.y-1]= 'P';
        ft_printf( "Move nomber : %d\n",  m->mov_cnt+1);
        ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x,p.y-1,m);
    m->mov_cnt++;
        return(1);
    }
    
    //ft_display(m->map,m);
    return(0);
}
int ft_move_down(position p, map_elmnt *m)
{
    if(m->map[p.x+1][p.y]== 'E' && m->clc_cnt == m->collct)
    {
       ft_printf( "Move nomber : %d\nCONGRATULATIONS,You won !!",  m->mov_cnt+1);
        exit(0);
        return(0);
    }
    if(m->map[p.x+1][p.y]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x+1][p.y]= 'P';
        m->clc_cnt++;
      ft_printf( "Move nomber : %d\n",  m->mov_cnt+1);
      ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x+1,p.y,m);
    m->mov_cnt++;
        return(1);
    }
    if(m->map[p.x+1][p.y]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x+1][p.y]= 'P';
       ft_printf( "Move nomber : %d\n", m->mov_cnt+1);
       ft_display_item("./textures/background.xpm",p.x,p.y,m);
    ft_display_item("./textures/player.xpm",p.x+1,p.y,m);
    m->mov_cnt++;
        return(1);
    }
    
    //ft_display(m->map,m);
    return(0);
}