/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:09:32 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/07 17:11:18 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include "get_next_line_utils.c"

char    *ft_buffer_sort(char *buffer)
{   
    int i;
    int k;

    i = 0;
    k = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    if (buffer[i] == '\n')
        i++;
    while (buffer[i] != '\0')
        buffer[k++] = buffer[i++];
    buffer[k] = '\0';
    return (buffer);
}

char    *ft_read(char *buffer)
{
    int i;
    int k;
    char *str;

    i = 0;
    k = 0;;
    if (ft_strlen(buffer) == 0)
        return(0);
    while (buffer[i] != '\n' && buffer[i] != '\0')
            i++;
    if (buffer[i] == '\n')
        i++;
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return(0);
    while (k < i)
    {
        str[k] = buffer[k];
        k++;
    }
    str[k] = '\0';
    return(str);
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char *str;
    char *old_line;
    int    loop;
    int    check;

    loop = 0;
    old_line = 0;
    str = 0;
    check = BUFFER_SIZE;
    if (read(fd, 0 , 0) < 0)
    {
        ft_clear_buff(buffer);
        return (0);
    }   
    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0 , 0) < 0)
        return (0);
    str = strjoin(str,ft_read(buffer));
    while( loop == 0 || (check == BUFFER_SIZE  && str[ft_strlen(str) - 1] != '\n'))
    {
        loop = 1;
        old_line = str;

       if ((old_line && old_line[ft_strlen(old_line) - 1] == '\n') || check < BUFFER_SIZE)
           {
               ft_buffer_sort(buffer);
               return(old_line);
           }
           
        check = read(fd, buffer, BUFFER_SIZE);
         if (check == -1)
         {
            ft_clear_buff(buffer);
            return (0);
         }   
        if (check == 0 && ft_strlen(old_line) != 0)
        {
               ft_clear_buff(buffer);
               return(old_line);
        }
        str = strjoin(old_line, ft_read(buffer));
        
        old_line = 0;
    }
    if ( check == 0 && ft_strlen(str) == 0)
        return(0);
        ft_buffer_sort(buffer);
        return(str);
}

//int main()
//{
//   int fd;
//
//   fd = open("limits.txt", O_RDONLY);
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   close(fd);
//   return(0);
//}