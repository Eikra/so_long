#include "so_long.h"
int ft_move_up(position p, map_elmnt *m, int check, int *c,int count)
{
    char    cnt;

    cnt = count +'0'+1;
    if(m->map[p.x-1][p.y]== 'E' && check==1)
    {
        ft_printf( "Move nomber : %d\nYou won !!", count);
        exit(0);
        return(0);
    }
    else if(m->map[p.x-1][p.y]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x-1][p.y]= 'P';
        c++;
       ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    else if(m->map[p.x-1][p.y]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x-1][p.y]= 'P';
       ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    //ft_display(m->map,m);
    return(0);
}
int ft_move_right(position p, map_elmnt *m, int check, int *c,int count)
{
    
    if(m->map[p.x][p.y+1]== 'E' && check==1)
    {
        ft_printf( "Move nomber : %d\nYou won !!", count);
        exit(0);
        return(0);
    }
    if(m->map[p.x][p.y+1]== 'C')
    {
        m->map[p.x][p.y+1]= '0';
        m->map[p.x][p.y+1]= 'P';
        c++;
       ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    if(m->map[p.x][p.y+1]== '0')
    {
        m->map[p.x][p.y+1]= '0';
        m->map[p.x][p.y+1]= 'P';
        ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    //ft_display(m->map,m);
    return(0);
}
int ft_move_left(position p, map_elmnt *m, int check, int *c,int count)
{
    char    cnt;

    cnt = count +'0'+1;
    if(m->map[p.x][p.y-1]== 'E' && check==1)
    {
       ft_printf( "Move nomber : %d\nYou won !!", count);
        exit(0);
        return(0);
    }
    if(m->map[p.x][p.y-1]== 'C')
    {
        m->map[p.x][p.y-1]= '0';
        m->map[p.x][p.y-1]= 'P';
        c++;
        ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    if(m->map[p.x][p.y-1]== '0')
    {
        m->map[p.x][p.y-1]= '0';
        m->map[p.x][p.y-1]= 'P';
        ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    //ft_display(m->map,m);
    return(0);
}
int ft_move_down(position p, map_elmnt *m, int check, int *c,int count)
{
    char    cnt;

    cnt = count +'0'+1;
    if(m->map[p.x+1][p.y]== 'E' && check==1)
    {
       ft_printf( "Move nomber : %d\nYou won !!", count);
        exit(0);
        return(0);
    }
    if(m->map[p.x+1][p.y]== 'C')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x+1][p.y]= 'P';
        c++;
      ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    if(m->map[p.x+1][p.y]== '0')
    {
        m->map[p.x][p.y]= '0';
        m->map[p.x+1][p.y]= 'P';
       ft_printf( "Move nomber : %d\n", count);
        return(1);
    }
    //ft_display(m->map,m);
    return(0);
}