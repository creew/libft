SRCDIR	= ./srcs
OBJDIR	= ./objs

ARR_SRC = ft_array_add.c \
		ft_array_delete_all.c \
		ft_array_foreach.c \
		ft_array_get.c \
		ft_array_init.c \
		ft_array_insert.c \
		ft_array_new.c \
		ft_array_remove.c \
		ft_array_remove_all.c \
		ft_array_size.c
ARR_DIR = array
ARR_ALL = $(addprefix $(SRCDIR)/$(ARR_DIR)/, $(ARR_SRC))
ARR_OBJ = $(addprefix $(OBJDIR)/$(ARR_DIR)/, $(ARR_SRC:%.c=%.o))

GNL_SRC = get_next_line.c
GNL_DIR = get_next_line
GNL_ALL = $(addprefix $(SRCDIR)/$(GNL_DIR)/, $(GNL_SRC))
GNL_OBJ = $(addprefix $(OBJDIR)/$(GNL_DIR)/, $(GNL_SRC:%.c=%.o))

LST_SRC = ft_lstadd.c \
		ft_lstadd_back.c \
        ft_lstaddblank.c \
        ft_lstaddrevsorted.c \
        ft_lstaddsorted.c \
        ft_lstdel.c \
        ft_lstdelone.c \
        ft_lstfind.c \
        ft_lstget.c \
        ft_lstiter.c \
        ft_lstmap.c \
        ft_lstnew.c \
        ft_lstnewblank.c \
        ft_lstremove_if.c \
        ft_lstsize.c
LST_DIR = lst
LST_ALL = $(addprefix $(SRCDIR)/$(LST_DIR)/, $(LST_SRC))
LST_OBJ = $(addprefix $(OBJDIR)/$(LST_DIR)/, $(LST_SRC:%.c=%.o))

MEM_SRC = ft_bzero.c \
		ft_calloc.c \
		ft_intlen.c \
		ft_intmove.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memndup.c \
		ft_memrealloc.c \
		ft_memset.c \
		ft_voidcpy.c
MEM_DIR = mem
MEM_ALL = $(addprefix $(SRCDIR)/$(MEM_DIR)/, $(MEM_SRC))
MEM_OBJ = $(addprefix $(OBJDIR)/$(MEM_DIR)/, $(MEM_SRC:%.c=%.o))

OTH_SRC = ft_abs.c \
		ft_bubble_sort.c \
		ft_getc.c \
		ft_max.c \
		ft_min.c \
		ft_qsort.c \
		ft_queue_add.c \
		ft_queue_poll.c \
		ft_stack_delall.c \
		ft_stack_init.c \
		ft_stack_pop.c \
		ft_stack_push.c \
		ft_stack_size.c \
		ft_swapvals.c
OTH_DIR = oth
OTH_ALL = $(addprefix $(SRCDIR)/$(OTH_DIR)/, $(OTH_SRC))
OTH_OBJ = $(addprefix $(OBJDIR)/$(OTH_DIR)/, $(OTH_SRC:%.c=%.o))

STR_SRC = ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
        ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_safe_atoi.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strpbrk.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtol.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_trim_spaces.c
STR_DIR = str
STR_ALL = $(addprefix $(SRCDIR)/$(STR_DIR)/, $(STR_SRC))
STR_OBJ = $(addprefix $(OBJDIR)/$(STR_DIR)/, $(STR_SRC:%.c=%.o))

OUT_SRC = ft_putchar.c \
          ft_putchar_fd.c \
          ft_putendl.c \
          ft_putendl_fd.c \
          ft_putnbr.c \
          ft_putnbr_fd.c \
          ft_putstr.c \
          ft_putstr_fd.c \
          ft_putintarray.c
OUT_DIR = out
OUT_ALL = $(addprefix $(SRCDIR)/$(OUT_DIR)/, $(OUT_SRC))
OUT_OBJ = $(addprefix $(OBJDIR)/$(OUT_DIR)/, $(OUT_SRC:%.c=%.o))

NAME	= libft.a

FLAGS	= -Wall -Wextra -Werror -g

INCLUDES = ./includes/array.h \
		./includes/libft.h \
		./includes/get_next_line.h \
		./includes/lst.h \
		./includes/str.h \
		./includes/out.h

OBJS	= $(ARR_OBJ) \
 			$(GNL_OBJ) \
 			$(LST_OBJ) \
 			$(MEM_OBJ) \
 			$(OTH_OBJ) \
 			$(STR_OBJ) \
 			$(OUT_OBJ)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -I./includes -c $< -o $@

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
