/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:35:26 by nkunnath          #+#    #+#             */
/*   Updated: 2024/07/02 13:35:27 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] != '\0' && i < n - 1)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == c2)
			i++;
		else
			return (c1 - c2);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}