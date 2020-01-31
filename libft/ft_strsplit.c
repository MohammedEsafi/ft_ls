/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:44:37 by mesafi            #+#    #+#             */
/*   Updated: 2020/01/20 13:31:45 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	words_count(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static int	key_count(const char *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len + 1);
}

static void	ft_cp_words(char *dest, const char *src, char split)
{
	while (*src != split && *src)
		*dest++ = *src++;
	*dest = '\0';
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		w_count;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	w_count = words_count(s, c);
	arr = (char **)malloc((w_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		if (*s != c && *s)
		{
			arr[i] = (char *)malloc(key_count(s, c) * sizeof(char));
			ft_cp_words(arr[i], s, c);
			s += key_count(s, c) - 2;
			i++;
		}
		s++;
	}
	arr[i] = 0;
	return (arr);
}
