/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 16:48:06 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sig_handler(int sig)
{
	static unsigned char	c;
	static int				i;
	static int				is_first;

	if (!is_first)
	{
		ft_printf("He enviado: ");
		is_first = 1914;
	}
	if (sig == SIGUSR1)
		c = c << 1 | 1;
	else if (sig == SIGUSR2)
		c = c << 1;
	i++;
	if (i == 8)
	{
		if (c == 4)
		{
			ft_printf(" Bytes\n");
			exit(1);
		}
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}
