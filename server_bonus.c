/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/14 15:51:29 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minitalk.h"

static void	handle_signal(int signal, siginfo_t *info, void *ucontext)
{
	static char	current_char;
	static int	bit_index;

	(void)ucontext;
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
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

static void	set_sigaction(void)
{
	struct sigaction	signal_action;

	signal_action.sa_sigaction = &handle_signal;
	signal_action.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_action.sa_mask);
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1)
		exit(ft_print_error("Sigaction failure - SIGUSR1"));
	if (sigaction(SIGUSR2, &signal_action, NULL) == -1)
		exit(ft_print_error("Sigaction failure - SIGUSR2"));
}

int	main(void)
{
	ft_printf("ID: %d\n", getpid());
	set_sigaction();
	while (1)
		pause();
	return (0);
}
