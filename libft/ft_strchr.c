/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:31:16 by nkunnath          #+#    #+#             */
/*   Updated: 2024/07/02 10:31:21 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i] != '\0')
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i = i + 1;
	}
	if (temp[i] == (char)c)
		return (&temp[i]);
	return (NULL);
}
