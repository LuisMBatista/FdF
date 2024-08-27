/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:03:02 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/13 11:50:46 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
// // int main (void)
// // {
// // 	char str[] = "abcde";
// // 	ft_putstr_fd(str,1);
// // 	return (0);
// // }
// int main (void)
// {
// 	int fd = open("./text/test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
// 	char str[] = "0000000000000000000000000000000000000000";
// 	ft_putstr_fd(str,fd);
// 	return (0);
// }