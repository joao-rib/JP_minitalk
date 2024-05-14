/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/14 15:01:39 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Header/minitalk.h"

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
