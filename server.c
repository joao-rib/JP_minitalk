/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/14 15:29:57 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minitalk.h"

static void	handle_signal(int signal)
{
	static char	current_char;
	static int	bit_index;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		current_char |= (signal == SIGUSR1);
		bit_index++;
		if (bit_index == 8)
		{
			ft_printf("%c", current_char);
			bit_index = 0;
			current_char = 0;
		}
		else
			current_char <<= 1;
	}
	else
		ft_printf("Unexpected signal: %d\n", signal);
}

static void	set_sigaction(void)
{
	struct sigaction	signal_action;

	signal_action.sa_handler = &handle_signal;
	signal_action.sa_flags = 0;
	sigemptyset(&signal_action.sa_mask);
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1)
		exit(ft_print_error("Sigaction failure - Bit 1"));
	if (sigaction(SIGUSR2, &signal_action, NULL) == -1)
		exit(ft_print_error("Sigaction failure - Bit 0"));
}

int	main(void)
{
	ft_printf("ID: %d\n", getpid());
	set_sigaction();
	while (1)
		pause();
	return (0);
}
