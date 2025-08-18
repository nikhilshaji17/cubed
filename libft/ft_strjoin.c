/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:46:39 by nkunnath          #+#    #+#             */
/*   Updated: 2024/07/04 10:46:41 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_string(char *f_string, char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	l_one;
	int	l_two;	

	i = 0;
	j = 0;
	l_one = ft_strlen(s1);
	l_two = ft_strlen(s2);
	while (j < l_one)
	{
		f_string[i] = s1[j];
		i = i + 1;
		j = j + 1;
	}
	j = 0;
	while (j < l_two)
	{
		f_string[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	f_string[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_string;
	int		l_one;
	int		l_two;

	final_string = NULL;
	l_one = 0;
	l_two = 0;
	l_one = ft_strlen(s1);
	l_two = ft_strlen(s2);
	final_string = (char *)malloc((sizeof(char) * (l_one + l_two)) + 1);
	if (final_string == NULL)
		return (final_string);
	make_string(final_string, s1, s2);
	return (final_string);
}
