/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 00:11:40 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/18 15:42:15 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_tex(t_elements *elem, char *trim, char **arr)
{
	arr = ft_split(trim, ' ');
	if (!arr)
		return (1);
	if (!arr[0] || !arr[1] || arr[2])
	{
		free(trim);
		fr_array(arr);
		return (print_error("Error: Texture files are incorrect"));
	}
	free(trim);
	trim = ft_strtrim(arr[1], " \t\v\f\r");
	if (!trim)
	{
		fr_array(arr);
		return (1);
	}
	if (store_tex(elem, trim, arr) == 1)
	{
		free(trim);
		fr_array(arr);
		return (1);
	}
	free(trim);
	fr_array(arr);
	return (0);
}

int	store_elem(t_elements *elem, char *line)
{
	char	**arr;
	char	*trim;

	arr = NULL;
	trim = ft_strtrim(line, " \t\v\f\r\n");
	if (!trim)
		return (1);
	if (trim[0] == 'N' || trim[0] == 'S' || trim[0] == 'W' || trim[0] == 'E')
		return (handle_tex(elem, trim, arr));
	else if (trim[0] == 'F' && trim[1] == ' ')
		elem->floor = parse_rgb(trim + 1);
	else if (trim[0] == 'C' && trim[1] == ' ')
		elem->ceiling = parse_rgb(trim + 1);
	else
		return (free(trim), 1);
	if (elem->floor == -1 || elem->ceiling == -1)
		return (free(trim), 1);
	free(trim);
	return (0);
}
