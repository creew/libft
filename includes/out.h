//
// Created by eklompus on 8/1/20.
//

#ifndef FT_OUT_H
#define FT_OUT_H

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putintarray(int *arr, size_t size, char *name);

#endif	// FT_OUT_H
