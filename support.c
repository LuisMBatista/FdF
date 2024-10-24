/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:13:32 by lumiguel          #+#    #+#             */
/*   Updated: 2024/10/24 12:13:42 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

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
