/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalam <rsalam.student@42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:59 by rsalam            #+#    #+#             */
/*   Updated: 2023/01/15 19:03:37 by rsalam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_left_str(int fd, char *left_str)
{
	char	*str;
	int		rd_bytes;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, str, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(str);
			return (NULL);
		}
		str[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, str);
	}
	free(str);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[1000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = read_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_left(left_str[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test1.txt", O_RDONLY);
// 	fd3 = open("test2.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }