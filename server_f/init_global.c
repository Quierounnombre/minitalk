/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:45 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/14 14:31:23 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	init_global(void)
{
	g_client_info.is_malloc_ready = 1810;
	g_client_info.num_chars = 0;
	g_client_info.pid_c = 0;
	g_client_info.malloc_size = 0;
	g_client_info.s_pos = 0;
}
