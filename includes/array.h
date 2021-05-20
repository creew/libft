#ifndef ARRAY_H
# define ARRAY_H

# include <string.h>

/*
**	data - массив данных
**	num_elems - актуальное количество данных в массиве
**	max_elems - максимально количество данных в массиве
**	init_val - на сколько будет увеличиваться массив при нехватке места
*/

typedef struct s_ftarray
{
	void	**data;
	size_t	num_elems;
	size_t	max_elems;
	size_t	init_val;
}				t_ftarray;

int				ft_array_add(t_ftarray *arr, void *data);
void			ft_array_delete_all(t_ftarray **arr, void (*f)(void *));
int				ft_array_foreach(t_ftarray *arr, void (*f)(void *adata,
						void *udata), void *param);
int				ft_array_get(t_ftarray *arr, size_t index, void **data);
int				ft_array_init(t_ftarray *ftarray, size_t init_val);
int				ft_array_insert(t_ftarray *arr, void *data, size_t pos);
t_ftarray		*ft_array_new(size_t init_val);
int				ft_array_remove(t_ftarray *arr, size_t index,
					void (*f)(void *));
void			ft_array_remove_all(t_ftarray *arr, void (*f)(void *));
size_t			ft_array_size(t_ftarray *arr);

#endif
