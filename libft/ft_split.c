/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkunnath <nkunnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:24:15 by mnazar            #+#    #+#             */
/*   Updated: 2025/08/18 15:46:08 by nkunnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_free(char **array, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static int	ft_word_count(const char *s, char sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_get_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * ((end - start + 1) + 1));
	if (!word)
	{
		return (NULL);
	}
	while (start <= end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**get_array(const char *s, char c, size_t i, int j)
{
	char	**ptr;
	int		k;

	ptr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!ptr)
		return (NULL);
	k = 0;
	while (i <= (size_t) ft_strlen(s))
	{
		j = i;
		while (s[i] && s[i] != c)
		{
			if (s[++i] == c || s[i] == '\0')
			{
				ptr[k++] = ft_get_word(s, j, i - 1);
				if (!(ptr[k - 1]))
					return (malloc_free(ptr, k - 1));
			}
		}
		if (s[i++] == '\0')
			break ;
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = get_array(s, c, 0, 0);
	return (ptr);
}
