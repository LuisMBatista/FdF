/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:42:12 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 12:15:40 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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





