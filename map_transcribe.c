/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transcribe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:55:06 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 11:58:21 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void read_and_fill_map(int fd, int ***map, int length, int height)
{
    char *str;
    int y = 0;

    while (y < height)
    {
        str = get_next_line(fd);
        if (str == NULL)
            break;

        process_line(str, map, y, length);
        free(str);
        y++;
    }
}
void process_line(char *str, int ***map, int y, int length)
{
    int i = 0;
    int x = 0;

    while (str[i] && str[i] != '\n' && x < length)
    {
        if (str[i] == ',')
            skip_comma(str, &i);
        else if (str[i] == ' ')  
            i++;
        else
        {
            map[y][x][0] = x;
            map[y][x][1] = y;
            map[y][x][2] = ft_atoi(&str[i]);
            skip_to_next_value(str, &i);
            x++;
        }
    }
}
void skip_comma(char *str, int *i)
{
    (*i)++;
    while (str[*i] != ' ' && str[*i] != '\n')
        (*i)++;
}
void skip_to_next_value(char *str, int *i)
{
    while (str[*i] != ' ' && str[*i] != ',' && str[*i] != '\n' && str[*i] != '\0')
        (*i)++;
}
