/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsalam <rsalam.student@42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:53:24 by rsalam            #+#    #+#             */
/*   Updated: 2023/01/15 19:04:02 by rsalam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = read_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_left(left_str);
	return (line);
}

// int	main(void)
// {
// 	char	*line;

// 	int fd = open("test.txt", O_RDONLY);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// free(line);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }