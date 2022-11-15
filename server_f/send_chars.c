/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:08 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/15 18:21:16 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_chars(int i, pid_t pid)
{
	ft_printf("\nHe recivido de: %d Un total de %d bytes\n", pid, i);
	kill(pid, SIGUSR1);
	init_global();
}

