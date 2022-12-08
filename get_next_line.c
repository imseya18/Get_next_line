/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:09:32 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/08 17:13:16 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

char	*ft_buffer_sort(char *buffer)
{
	int	i;
	int	k;

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

char	*ft_read(char *buffer, int *error)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (ft_strlen(buffer) == 0)
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
	{
		*error = -1;
		return (ft_clear_buff (buffer));
	}
	while (k < i)
	{
		str[k] = buffer[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			l;
	int			check;
	int			error;

	l = 0;
	check = BUFFER_SIZE;
	error = 0;
	if (read(fd, 0, 0) < 0)
		return (ft_clear_buff(buffer));
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = ft_read(buffer, &error);
	if (error == -1)
		return (0);
	while (l == 0 || (check == BUFFER_SIZE && str[ft_strlen(str) - 1] != '\n'))
	{
		l = 1;
		if ((str && str[ft_strlen(str) - 1] == '\n') || check < BUFFER_SIZE)
		{
			ft_buffer_sort(buffer);
			return (str);
		}
		ft_clear_buff(buffer);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (ft_clear_buff(buffer));
		if (check == 0 && ft_strlen(str) != 0)
		{
			ft_clear_buff(buffer);
			return (str);
		}
		str = strjoin(str, ft_read(buffer, &error));
		if (error == -1 || !str)
		{
			free(str);
			return (0);
		}
	}
	if (check == 0 && ft_strlen(str) == 0)
		return (0);
	ft_buffer_sort(buffer);
	return (str);
}

//int main()
//{
//   int fd;
//
//   fd = open("one_line_no_nl.txt", O_RDONLY);
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   printf("%s===============\n",get_next_line(fd));
//   close(fd);
//   return(0);
//}