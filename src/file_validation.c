/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:05:31 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:59 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_str_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	arg_validity(char *argv)
{
	char	**file;
	int		i;

	if (!argv || !argv[0])
		return (0);
	file = ft_split(argv, '.');
	i = 0;
	while (file[i])
		i++;
	if (!file[1] || i > 2)
		return (free_str_array(file), 0);
	if (ft_strcmp(file[1], "fdf") == 0)
		return (free_str_array(file), 1);
	return (free_str_array(file), 0);
}

void	(arg_validation(int argc, char **argv))
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("Error: Invalid number of arguments.\n");
		exit (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (arg_validity(argv[1]) == 0 || fd < 0 || argc != 2)
	{
		ft_printf("Error: Invalid file.\n");
		exit (0);
	}
	close(fd);
}
