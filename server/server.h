/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:07:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/07 20:10:26 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft_def/libftprintf.h"

int		set_sigh(struct sigaction *sact, void (*f)(int), int sig, int sig2);
void	sig_handler(int j);

#endif