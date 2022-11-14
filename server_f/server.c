/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 18:28:47 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	sact;

	init_global();
	ft_printf("Mi ID es: %d\n", getpid());
	if (set_sigh(&sact, SIGUSR1, SIGUSR2))
	{
		while (1)
			pause();
	}
}
