/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:42:08 by arobion           #+#    #+#             */
/*   Updated: 2017/12/18 15:28:36 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 32
# include "libft.h"

typedef	struct		s_gnl
{
	char			*data;
	int				fd;
	struct s_gnl	*next;
}					t_gnl_list;
int					get_next_line(const int fd, char **line);

#endif
