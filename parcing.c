/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:42:12 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 12:08:56 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen3(const char *s)
{
    int i = 0;
    int length = 0;

   while (s[i] != '\0')
   {
       if (s[i] != ' ' && s[i] != '\n' && ft_isdigit(s[i]))
	        length++;
        while (s[i] != '\0' && ft_isdigit(s[i]) )
            i++;
        if (s[i] == ',')
            {
                i++;
                while (s[i] != ' ' && s[i] != '\n')
                    i++;
            }
        if (s[i] != '\0')
            i++;
    }
    return length;
}

int lenght_check(char *argv)
{
    char *str;
    int lenght;
    int fd;

    fd = open(argv, O_RDONLY);
    lenght = 0;
    str = get_next_line(fd);
    if (str != NULL)
        lenght = ft_strlen3(str);
    while (str != NULL)
    {
        free(str);
        str = get_next_line(fd);
        if (str != NULL)
        {
            if (lenght != ft_strlen3(str))
            {
                free(str);
                close(fd);
                exit(ft_printf("Error: Length invalid\n"));
            }
        }
    }
    close(fd);
    return lenght;
}

int height_check(char *argv)
{
    char *str;
    int height;
    int fd;

    height = 0;
    fd = open(argv, O_RDONLY);
    str = get_next_line(fd);
    while (str != NULL)
    {
        height++;
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return (height);
}

float check_zoom(float ***map, int img_lenght, int img_height, t_data *img)
{
    float lenght;
    float height;

    lenght = lenght_multiplier(map, img_lenght, img);
    height = height_multiplier(map, img_height, img);
    if (lenght <= height)
        return(lenght);
    return(height);
}

int ***str_to_int(int length, int height, char *argv)
{
    int fd = open(argv, O_RDONLY);
    if (fd == -1)
        return NULL;

    int ***map = map_allocation(length, height);
    if (map == NULL)
        return NULL;
    read_and_fill_map(fd, map, length, height);
    close(fd);
    return map;
}

