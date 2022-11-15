/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:15:54 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/15 18:20:25 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sact;
	size_t				len;

	if (set_sigh(&sact, sig_handler, SIGUSR1, SIGUSR2))
	{
		if (parse(argc, argv))
		{
			pid = ft_atoi(argv[1]);
			ft_printf("Escribo a: %d\n", pid);
			len = ft_strlen(argv[2]);
			ft_printf("La cadena mide %d caracteres\n", len);
			transform(argv[2], pid);
			while (1)
				pause();
		}
	}
}
