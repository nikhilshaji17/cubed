/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:45:09 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/15 21:41:50 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **argv)
{
	t_data	data;
	if (ac != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		printf("Error: Invalid file extension\n");
		return (1);
	}
	init_data(&data);
	if (parse_map(argv[1], &data))
		return (1);
	printf("Fine so far\n");
	return (0);
}
