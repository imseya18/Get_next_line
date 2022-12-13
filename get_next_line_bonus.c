/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:25:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/13 17:12:34 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (ft_clear_buff (0, buffer));
	}
	while (k < i)
	{
		str[k] = buffer[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*check_line(char *str, int fd, char *buffer, int error)
{
	int	check;

	check = BUFFER_SIZE;
	while (check == BUFFER_SIZE)
	{
		if ((str && str[ft_strlen(str) - 1] == '\n'))
		{
			ft_buffer_sort(buffer);
			return (str);
		}
		ft_clear_buff(0, buffer);
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (ft_clear_buff(0, buffer));
		str = strjoin(str, ft_read(buffer, &error));
		if (error == -1 || !str)
			return (ft_clear_buff(1, str));
	}
	ft_buffer_sort(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[9000][BUFFER_SIZE + 1];
	char		*str;
	int			error;

	error = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (read(fd, 0, 0) < 0)
		return (ft_clear_buff(0, buffer[fd]));
	str = ft_read(buffer[fd], &error);
	if (error == -1)
		return (0);
	str = check_line(str, fd, buffer[fd], error);
	return (str);
}
