/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:51:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/03 18:58:13 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_def/libftprintf.h"

int	main(void)
{
	int	i;

	i = 0;
	ft_printf("Mi ID es: %d\n", getpid());
	while (1)
	{
		ft_printf("Numero de iteraciones: %d\n", i);
		sleep(1);
		i++;
	}
}


sigaction(SIGUSR1, main);