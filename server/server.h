/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:07:30 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/04 15:03:42 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft_def/libftprintf.h"

int		set_sigh(struct sigaction *sact, void (*f)(int), int signal);
void	sig_handler(int j);

#endif