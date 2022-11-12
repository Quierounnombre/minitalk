/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:07:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/10 12:57:24 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft_def/libftprintf.h"

typedef struct s_client
{
	pid_t	pid_c;
	int		num_chars;
	int		is_pid_ready;
}				t_client;

t_client	g_client_info;

int		set_sigh(struct sigaction *sact, void (*f)(int), int sig, int sig2);
void	sig_handler(int j);
void	send_chars(int i, pid_t pid);

#endif