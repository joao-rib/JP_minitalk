/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ubase_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/08 12:29:09 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minitalk.h"

static int	repeat_chars(char *str, char t)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == t)
			count++;
		i++;
	}
	if (count <= 1)
		return (0);
	else
		return (1);
}

static int	check_valid(char *str, int b)
{
	int	i;

	i = 0;
	if (b <= 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127)
			return (0);
		else if (str[i] == '-' || str[i] == '+')
			return (0);
		else if (repeat_chars(str, str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_ubase_fd(unsigned int nbr, char *base, int fd)
{
	long	aux;
	int		b;
	int		l;

	b = 0;
	l = 1;
	aux = nbr;
	while (base[b] != '\0')
		b++;
	if (!check_valid(base, b))
		return (0);
	if (aux >= b)
	{
		l += ft_putnbr_ubase_fd(aux / b, base, fd);
		aux %= b;
	}
	write(fd, &base[aux], 1);
	return (l);
}
