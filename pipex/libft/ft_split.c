/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaydam <msaydam@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:03:30 by msaydam           #+#    #+#             */
/*   Updated: 2022/07/25 13:09:46 by msaydam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nb_word(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	end;
	size_t	j;
	int		beg;
	char	**str;

	str = (char **)malloc((nb_word(s, c) + 1) * (sizeof(char *)));
	if (!s || !str)
		return (0);
	beg = -1;
	end = 0;
	j = 0;
	while (end <= ft_strlen(s))
	{
		if (beg < 0 && s[end] != c)
			beg = end;
		else if ((s[end] == c || end == ft_strlen(s)) && beg >= 0)
		{
			str[j++] = word_dup(s, beg, end);
			beg = -1;
		}
		end++;
	}
	str[j] = 0;
	return (str);
}
