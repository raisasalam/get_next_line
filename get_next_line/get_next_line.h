/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalam <rsalam.student@42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:11 by rsalam            #+#    #+#             */
/*   Updated: 2023/01/15 19:22:14 by rsalam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_left_str(int fd, char *left_str);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *str);
char	*ft_get_line(char *left_str);
char	*ft_left(char *left_str);

#endif