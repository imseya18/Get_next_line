/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:25:29 by mmorue            #+#    #+#             */
/*   Updated: 2022/12/13 17:12:36 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*strjoin(char *s1, char *s2);
char	*ft_buffer_sort(char *buffer);
char	*ft_read(char *buffer, int *error);
char	*ft_clear_buff(int behavior, char *buffer);
void	strfill(char *str, char *s1, char *s2);
char	*check_line(char *str, int fd, char *buffer, int error);

#endif