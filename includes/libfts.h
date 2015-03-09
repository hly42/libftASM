/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 19:55:14 by hly               #+#    #+#             */
/*   Updated: 2015/02/14 20:57:49 by hly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

extern void		ft_bzero(void *s, size_t n);
extern char		*ft_strcat(char *s1, const char *s2);
extern int		ft_isalpha(int c);
extern int		ft_isdigit(int c);
extern int		ft_isalnum(int c);
extern int		ft_isascii(int c);
extern int		ft_isprint(int c);
extern int		ft_toupper(int c);
extern int		ft_tolower(int c);
extern int		ft_puts(const char *s);
extern char		*ft_strcpy(char *dst, const char *src);
extern size_t	ft_strlen(const char *s);
extern void		*ft_memset(void *b, int c, size_t len);
extern void		*ft_memcpy(void *dst, const void *src, size_t n);
extern char		*ft_strdup(const char *s1);
extern void		ft_cat(const int fd);

#endif	/* LIBFTS_H */
