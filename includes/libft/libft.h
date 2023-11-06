/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:34:25 by amassias          #+#    #+#             */
/*   Updated: 2023/11/06 18:55:10 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/*                                                                            */
/* Includes                                                                   */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/* Structures                                                                 */
/*                                                                            */
/* ************************************************************************** */

/**
 * @struct s_list
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make description.
 */
struct
	s_list
{
	void			*content;
	struct s_list	*next;
};

/* ************************************************************************** */
/*                                                                            */
/* Types                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @typedef t_list
 * @copydoc s_list
 */
typedef struct s_list	t_list;

/**
 * @typedef t_comparator
 * @brief 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make description.
 */
typedef int				(*t_comparator)(void *, void *);

/* ************************************************************************** */
/*                                                                            */
/* CType                                                                      */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Tells whether or not `c` is a letter.
 * @param c A character.
 * @return Whether or not `c` is a letter.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_isalpha(
			int c);

/**
 * @brief Tells whether or not `c` is a digit.
 * @param c A character.
 * @return Whether or not `c` is a digit.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_isdigit(
			int c);

/**
 * @brief Tells whether or not `c` is a letter or a digit.
 * @param c A character.
 * @return Whether or not `c` is a letter or a digit.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_isalnum(
			int c);

/**
 * @brief Tells whether or not `c` is an ascii character.
 * @param c A character.
 * @return Whether or not `c` is an ascii character.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_isascii(
			int c);

/**
 * @brief Tells whether or not `c` is printable.
 * @param c A character.
 * @return Whether or not `c` is printable.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_isprint(
			int c);

/**
 * @brief If `c` is a letter, converts it to uppercase.
 * @param c a character.
 * @return The transformes character.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_toupper(
			int c);

/**
 * @brief If `c` is a letter, converts it to lowercase.
 * @param c a character.
 * @return The transformes character.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_tolower(
			int c);

/* ************************************************************************** */
/*                                                                            */
/* String                                                                     */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Calculates th length of `str`.
 * @param str A string.
 * @return The length of `str`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
size_t	ft_strlen(
			const char *str);

/**
 * @brief Sets `n` bytes of `ptr` to `c`.
 * @param ptr A pointer to a memory area.
 * @param c A byte.
 * @param n The ammount of bytes to set to `c`.
 * @return The `ptr` pointer.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	*ft_memset(
			void *ptr,
			int c,
			size_t n);

/**
 * @brief Writes `n` zeros ('\0') to `ptr`.
 * @param ptr A pointer to a memory area.
 * @param n The ammount of bytes to set to zero.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_bzero(
			void *ptr,
			size_t n);

/*!
 * @brief Copies `n` bytes of `src` to `dst`. The memory areas mus not overlap.
 * Use `ft_memmove` if the memory areas do overlap.
 * @param dst A pointer to a memory area.
 * @param src A pointer to a memory area.
 * @param n The ammount of bytes to copy.
 * @return The `dst` pointer.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	*ft_memcpy(
			void *dst,
			const void *src,
			size_t n);

/**
 * @brief copies `n` bytes from memory area `src` to memory area `dst`.
 * The memory areas may overlap: copying takes place as though the bytes in
 * `src` are first copied into a temporary array that does not overlap `src`
 * or `dst`, and the bytes are then copied from the temporary array to `dst`.
 * @param dst A pointer to a memory area.
 * @param src A pointer to a memory area.
 * @param n The ammount of bytes to copy.
 * @return The `dst` pointer.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	*ft_memmove(
			void *dst,
			const void *src,
			size_t n);

/**
 * @brief Copies `src` to `dst`. Takes the full `size` of `dst` and guarantee
 * to NUL-terminate the result (as long as `size` is larger than 0). Note that a
 * byte for the NUL should be included in `size`. Can only operate on true "C"
 * strings. `src` must be NUL-terminated. Copies up to `size - 1` characters
 * from `src` to `dst`, NUL-terminating the result.
 * @param dst A pointer to a memory area.
 * @param src A string.
 * @param size The length of the string `ft_strlcopy` tries to create.
 * @return The length of `src`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
size_t	ft_strlcpy(
			char *dst,
			const char *src,
			size_t size);

/**
 * @brief Concatenate `str` to `dst`. Takes the full `size` of `dst`
 * and guarantee to NUL-terminate the result (as long as there is at least one
 * byte free in `dst`). Note that a byte for the NUL should be included in
 * `size`. Can only operate on true “C” strings. This means that both `src`
 * and `dst` must be NUL-terminated. Appends the NUL-terminated string `src` to
 * the end of `dst`. It will append at most `size - ft_strlen(dst) - 1` bytes,
 * NUL-terminating the result.
 * @param dst A pointer to a memory area.
 * @param src A string.
 * @param size The length of the string `ft_strlcat` tries to create.
 * @return The initial length of `dst` plus the length of `src`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
size_t	ft_strlcat(
			char *dst,
			const char *src,
			size_t size);

/**
 * @brief Returns a pointer to the first occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @param str A string.
 * @param c A character.
 * @return A pointer to the first occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strchr(
			const char *str,
			int c);

/**
 * @brief Returns a pointer to the last occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @param str A string.
 * @param c A character.
 * @return A pointer to the last occurence of `c` in `str` if it exists,
 * `NULL` otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strrchr(
			const char *str,
			int c);

/**
 * @brief Compares with the lexical order the `n` first characters of `str_1`
 * and `str_2`.
 * @param str_1 A string.
 * @param str_2 A string.
 * @param n The max ammount of characters to compare.
 * @return The lexical order of the two string.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_strncmp(
			const char *str_1,
			const char *str_2,
			size_t n);

/**
 * @brief Returns a pointer to the first occurence of the byte `c` in `ptr` if
 * it exists, `NULL` otherwise.
 * @param ptr A memory area.
 * @param c A byte.
 * @return A pointer to the first occurence of the byte `c` in `ptr` if it
 * exists, `NULL` otherwise.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	*ft_memchr(
			const void *ptr,
			int c,
			size_t n);

/**
 * @brief Compares with the lexical order the `n` first bytes of `ptr_1`
 * and `ptr_2`.
 * @param ptr_1 A memory area.
 * @param ptr_2 A memory area.
 * @param n The max ammount of bytes to compare.
 * @return The lexical order of the two memory area.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_memcmp(
			const void *s1,
			const void *s2,
			size_t n);

/**
 * @brief Swaps `n` bytes of `a` and `b`. The memory areas must not overlap.
 * @param a A memory area.
 * @param b A memory area.
 * @param n The number of bytes to swap.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_memswap(
			void *a,
			void *b,
			size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string `little`
 * in the string `big`, where not more than `len` characters are searched.
 * Characters that appear after a ‘\0’ character are not searched.
 * @param big The string to be searched.
 * @param little The string to search.
 * @param len The size of the search.
 * @return If `little` is an empty string, `big` is returned; if `little` occurs
 * nowhere in `big`, `NULL` is returned; otherwise a pointer to the first
 * character of the first occurrence of `little` is returned.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strnstr(
			const char *big,
			const char *little,
			size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of `str`.
 * @param str A string.
 * @return A copy of `str`.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strdup(
			const char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the
 * string `str`. The substring begins at index `start` and is of maximum
 * size `len`.
 * @param str The string from which to create the substring.
 * @param start The start index of the substring in the string `str`.
 * @param len The maximum length of the substring.
 * @return The substring or `NULL` if the allocation fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_substr(
			char const *str,
			unsigned int start,
			size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of `str_1` and `str_2`.
 * @param str_1 The prefix string.
 * @param str_2 The suffix string.
 * @return The new string or `NULL` if the allocation fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strjoin(
			char const *str_1,
			char const *str_2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of `str` with the
 * characters specified in `set` removed from the beginning and the end of the
 * string.
 * @param str The string to be split.
 * @param set The delimiter character.
 * @return The array of new strings resulting from the split or `NULL` if the
 * allocation fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strtrim(
			char const *str,
			char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
 * splitting `str` using the character `delim_char` as a delimiter.
 * The array must end with a `NULL` pointer.
 * @param str The string to be split.
 * @param delim_char The delimiter character.
 * @return The array of new strings resulting from the split or `NULL` if the
 * allocation fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	**ft_split(
			char const *str,
			char delim_char);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer or `NULL` if the allocation
 * fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_itoa(
			int n);

/**
 * @brief Applies the function `f` to each character of the string `str`, and
 * passing its index as first argument to create a new string (with malloc(3))
 * resulting from successive applications of `f`.
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of `f`. Returns
 * `NULL` if the allocation fails.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
char	*ft_strmapi(
			char const *s,
			char (*f)(unsigned int, char));

/**
 * @brief Applies the function `f` on each character of the string `str`,
 * passing its index as first argument. Each character is passed by address
 * to `f` to be modified if necessary.
 * @param str The string on which to iterate.
 * @param f The function to apply to each character.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_striteri(
			char *str,
			void (*f)(unsigned int, char*));

/* ************************************************************************** */
/*                                                                            */
/* Stdlib                                                                     */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts the initial portion of the string pointed to by `str` to an
 * integer.
 * @param str The string to be converted.
 * @return The converted value.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_atoi(
			const char *str);

/**
 * @brief Allocates memory for an array of `nmemb` elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero. 
 * If `nmemb` or `size` is 0, then calloc() returns either NULL, or a unique
 * pointer value that can later be successfully passed to free(). If the
 * multiplication of `nmemb` and `size` would result in integer overflow, then
 * calloc() returns `NULL` and sets `errno` to `EINOMEM`.
 * @param nmemb The number of elements if the array.
 * @param size The size in bytes of each element.
 * @return Return a pointer to the allocated memory or NULL if case of error.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	*ft_calloc(
			size_t nmemb,
			size_t size);

/* ************************************************************************** */
/*                                                                            */
/* IO                                                                         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Outputs the character `c` to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_putchar_fd(
			char c,
			int fd);

/**
 * @brief Outputs the string `str` to the given file descriptor.
 * @param str The string to output.
 * @param fd The file descriptor on which to write.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_putstr_fd(
			char *str,
			int fd);

/**
 * @brief Outputs the string `str` to the given file descriptor followed by a
 * newline.
 * @param str 
 * @param fd 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_putendl_fd(
			char *str,
			int fd);

/**
 * @brief Outputs the signed integer `n` to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_putnbr_fd(
			signed int n,
			int fd);

# ifdef USE_LIB__FT_PRINTF

/**
 * @brief 
 * @param fmt 
 * @param ... 
 * @return int 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
int		ft_printf(
			const char *fmt,
			...);

# endif

# ifdef USE_LIB__GET_NEXT_LINE

/**
 * @brief 
 * @param fd 
 * @return char* 
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 * @todo Make documentation.
 */
char	*get_next_line(
			int fd);

# endif

/* ************************************************************************** */
/*                                                                            */
/* Linked list                                                                */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member variable
 * `content` is initialized with the value of the parameter `content`.
 * The variable `next` is initialized to `NULL`.
 * @param content The content to create the node with.
 * @return The new node.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
t_list	*ft_lstnew(
			void *content);

/**
 * @brief Adds the node `new` at the beginning of `list`.
 * @param list The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_lstadd_front(
			t_list **lst,
			t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * @param list The beginning of the list.
 * @return The length of the list.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
int		ft_lstsize(
			t_list *list);

/**
 * @brief Returns the last node of the list.
 * @param list The beginning of the list.
 * @return Last node of the list.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
t_list	*ft_lstlast(
			t_list *list);

/**
 * @brief Adds the node `new` at the end of the list.
 * @param list The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_lstadd_back(
			t_list **list,
			t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s content
 * using the function `del_fun` given as a parameter and free the node. The
 * memory of `next` must not be freed.
 * @param list The node to free.
 * @param del_fun The address of the function used to delete the content.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_lstdelone(
			t_list *list,
			void (*del_fun)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function `del_fun` and free(3). Finally, the pointer to the list
 * must be set to `NULL`.
 * @param list The address of a pointer to a node.
 * @param del_fun The address of the function used to delete the content of the
 * node.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_lstclear(
			t_list **list,
			void (*del_fun)(void *));

/**
 * @brief Iterates the list `list` and applies the function `f` on the content
 * of each node.
 * @param list The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_lstiter(
			t_list *list,
			void (*f)(void *));

/**
 * @brief Iterates the list `list` and applies the function `f` on the content of
 * each node. Creates a new list resulting of the successive applications of the
 * function `f`. The `del_fun` function is used to delete the content of a node
 * if needed.
 * @param list The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del_fun The address of the function used to delete the content of a
 * node if needed.
 * @return The new list or `NULL` if the allocation fail.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
t_list	*ft_lstmap(
			t_list *list,
			void *(*f)(void *),
			void (*del_fun)(void *));

/* ************************************************************************** */
/*                                                                            */
/* Algorithms                                                                 */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Sorts `nmemb` elements of size `size` of the list pointed by `base`
 * using `cmp` as the comparaison function.
 * @param base A memory area.
 * @param nmemb The number of elements to sort.
 * @param size The size of one single element.
 * @param cmp The comparaison function.
 * @author amassias (amassias@student.42lehavre.fr)
 * @date 2023-11-06
 */
void	ft_qsort(
			void *base,
			size_t nmemb,
			size_t size,
			t_comparator cmp);

#endif