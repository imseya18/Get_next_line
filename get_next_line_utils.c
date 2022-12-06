/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:09:35 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/06 16:34:10 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_clear_buff(char *buffer)
{
	int i;

	i = 0;

	while(i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';		
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return(0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
    if((s1 == 0 || s1[i] == '\0') && s2)
        return(s2);
	if (s1 == 0 || s2 == 0)
		return (0);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i])
		str[k++] = s1[i++];
    free(s1);
	i = 0;
	while (s2[i])
	{
		str[k] = s2[i];
		i++;
		k++;
	}
    free(s2);
	str[k] = '\0';
	return (str);
}
