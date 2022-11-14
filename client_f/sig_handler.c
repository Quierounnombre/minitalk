/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:16:57 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 20:21:55 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sig_handler(int sig)
{
	static size_t	i;

	if (sig == SIGUSR2)
	{
		ft_printf("Nº iteraciones: %d", i);
		i++;
	}
	if (sig == SIGUSR1)
		exit(1);
}
