/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:09:32 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/30 17:05:33 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



char    *ft_buffer_sort(char *buffer)
{   
    int i;
    int k;

    i = 0;
    k = 0;
    while(buffer[i] != '\n' && buffer[i] != '\0')
        i++;
    if (buffer[i] == '\n')
        i++;
    while(buffer[i])
        buffer[k++] = buffer[i++];
    buffer[k] = '\0';
    return(buffer);
}

char    *ft_read(char *buffer)
{
    int i;
    int k;
    char *str;

    i = 0;
    k = 0;
    if(ft_strlen(buffer) == 0)
        return(0);
    while(buffer[i] != '\n' && buffer[i] != '\0')
            i++;
    if (buffer[i] == '\n')
        i++;
    str = malloc((i + 1) * sizeof(char));
    if(!str)
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

    int i;
    while(str[ft_strlen(str) - 1] != '\n')
    {
        //printf("{%s}", buffer);
        old_line = strjoin(old_line, ft_read(buffer));
        read(fd, buffer, BUFFER_SIZE);
        str = strjoin(old_line, ft_read(buffer));
        //if  (str[ft_strlen(str) - 1] == '\n')
        //{   
        //    ft_buffer_sort(buffer);
        //    return(str);
        //}
    }  
        ft_buffer_sort(buffer);
        return(str);
}


int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s===============\n",get_next_line(fd));
    printf("%s===============\n",get_next_line(fd));
    printf("%s===============\n",get_next_line(fd));
    printf("%s===============\n",get_next_line(fd));
    close(fd);
    return(0);
}