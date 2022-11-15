/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/15 18:19:51 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sig_handler(int sig)
{
	static int		i;
	static size_t	nbyte;

	if (sig == SIGUSR2)
	{
		i++;
		if (i == 8)
		{
			i = 0;
			nbyte++;
			ft_printf("Nº iteraciones: %d\n", nbyte);
		}
	}
	if (sig == SIGUSR1)
		exit(1);
}
