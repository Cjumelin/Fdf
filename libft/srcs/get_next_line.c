/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:14:31 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/24 14:46:36 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_read(int fd, char *buf)
{
	int r;

	ft_bzero(buf, BUFF_SIZE + 1);
	r = read(fd, buf, BUFF_SIZE);
	if (r != -1)
		buf[r] = '\0';
	return (r);
}

void		buf_have_rc(char *ptr, char **line)
{
	char	*tmp;

	if (*line)
	{
		tmp = *line;
		*line = ft_strjoin(tmp, ptr);
		free(tmp);
	}
	else
		*line = ft_strdup(ptr);
}

int			ft_join(char **line, char *buf, int fd, int rt)
{
	char	*ptr;
	char	*end;

	while ((end = ft_strchr(buf, '\n')) == NULL)
	{
		buf_have_rc(buf, line);
		if ((rt = ft_read(fd, buf)) < 1)
			return (rt || ft_strlen(*line) != 0);
	}
	ptr = ft_strsub(buf, 0, (int)(end - buf));
	if (ptr != NULL)
	{
		buf_have_rc(ptr, line);
		free(ptr);
	}
	ft_strcpy(buf, end + 1);
	return (rt);
}

t_list_fd	*add_or_match_fd(t_list_fd **first, int fd)
{
	t_list_fd	*new;

	if (!*first)
	{
		if ((new = (t_list_fd *)malloc(sizeof(*new))) == NULL)
			return ((void*)0);
		ft_memset(new->buf, 0, BUFF_SIZE + 1);
		new->fd = fd;
		new->next = NULL;
		return ((*first = new));
	}
	new = *first;
	while (new->fd != fd && new->next != NULL)
		new = new->next;
	if (new->fd == fd)
		return (new);
	if (new->next == NULL)
	{
		if ((new->next = (t_list_fd *)malloc(sizeof(*new->next))) == NULL)
			return ((void *)0);
		ft_memset(new->next->buf, 0, BUFF_SIZE + 1);
		new->next->fd = fd;
		new->next->next = NULL;
	}
	return (new->next);
}

int			get_next_line(int const fd, char **line)
{
	static t_list_fd		*first = NULL;
	t_list_fd				*l;
	int						rt;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if ((l = add_or_match_fd(&first, fd)) == NULL)
		return (-1);
	rt = 1;
	if ((*line = malloc(1)) == NULL)
		return (-1);
	(*line)[0] = 0;
	if (l->buf[0] == '\0')
		if ((rt = ft_read(fd, l->buf)) < 1)
			return (rt);
	rt = ft_join(line, l->buf, fd, rt);
	if (rt > 1)
		rt = 1;
	return (rt);
}
