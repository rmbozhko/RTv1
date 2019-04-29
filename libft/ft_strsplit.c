/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvasin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 16:44:25 by yvasin            #+#    #+#             */
/*   Updated: 2017/01/15 17:32:17 by yvasin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_amount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static size_t	ft_wordlength(const char *s, char c, size_t i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(char*) * (ft_words_amount(s, c) + 1))))
		return (NULL);
	while (s[k])
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		if (s[k] == '\0')
			break ;
		split[i] = ft_strsub(s, k, ft_wordlength(s, c, k) - k);
		k = ft_wordlength(s, c, k);
		i++;
	}
	split[i] = NULL;
	return (split);
}
