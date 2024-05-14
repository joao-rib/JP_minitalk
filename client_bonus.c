/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/14 15:30:52 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minitalk.h"

static void	handle_return(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Bit 1 returned (%d)\n", signal);
	else if (signal == SIGUSR2)
		ft_printf("Bit 0 returned (%d)\n", signal);
}

static void	set_client_sigaction(void)
{
	struct sigaction	client_sig_action;

	client_sig_action.sa_handler = &handle_return;
	client_sig_action.sa_flags = 0;
	sigemptyset(&client_sig_action.sa_mask);
	if (sigaction(SIGUSR1, &client_sig_action, NULL) == -1)
		exit(ft_print_error("Return signal failure - SIGUSR1"));
	if (sigaction(SIGUSR2, &client_sig_action, NULL) == -1)
		exit(ft_print_error("Return signal failure - SIGUSR2"));
}

static void	send_message(int client_id, char c)
{
	int		i;
	char	buff_c;

	i = 7;
	buff_c = c;
	while (i >= 0)
	{
		buff_c = c >> i;
		if (buff_c % 2)
			kill(client_id, SIGUSR1);
		else
			kill(client_id, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		client_id;
	char	*message;

	i = 0;
	set_client_sigaction();
	if (argc != 3)
		return (ft_print_error("Insert two arguments"));
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			return (ft_print_error("First argument must be a number"));
		i++;
	}
	client_id = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_message(client_id, message[i]);
		i++;
	}
	send_message(client_id, '\n');
	return (0);
}
