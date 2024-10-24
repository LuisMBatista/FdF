/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:32:56 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 10:47:51 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_data *allocation_img(void)
{
    t_data *img;
    
    img = malloc(sizeof(t_data));
    if (!img)
    {
        ft_printf("Error: Failed to allocate memory for img.\n");
        exit (0);
    }
    return (img);
}
