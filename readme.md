# Libft

Welcome to my very first official project at 42: **Libft**.

If you're also a 42 student, you know the drill. If you're a normal human being from the outside world: 42 doesn't let us touch most of standard C's `<string.h>`, `<stdlib.h>`, or `<ctype.h>` functions early on. Instead, they tell us to build our own standard C library from scratch.

Yes, that means writing `strlen`, `memcpy`, and `atoi` with our bare hands while obeying **The Norm** (42's formatting rules that forbid `for` loops, give you 25 lines max per function, and generally test your sanity).

---

## 🧐 What’s inside?

The library is packaged as `libft.a` and divided into three main flavors:

### 1. The Standard Clones (`Libc` Functions)

Recreations of classic C utilities to keep life tolerable without `<string.h>` or `<ctype.h>`:

* **Character Checks:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
* **String Basics:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`
* **Raw Memory Ops:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
* **Allocation & Numbers:** `ft_atoi`, `ft_calloc`, `ft_strdup`

### 2. The Quality-of-Life Additions

Extra functions that standard C didn't provide out of the box, mostly making string manipulation and memory cleanup way less painful:

* `ft_substr` — Extracting a substring without leaking memory.
* `ft_strjoin` — Stitching two strings together dynamically.
* `ft_strtrim` — Trimming pesky leading/trailing characters.
* `ft_split` — The legendary rite of passage. Takes a string, splits it by a delimiter, and returns a NULL-terminated array of strings.
* `ft_itoa` — Turns an integer into an ASCII string (handling negatives and edge cases without crying).
* `ft_strmapi` / `ft_striteri` — Applying functional maps across string characters.
* `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd` — Writing straight to a designated file descriptor.

### 3. Linked Lists (Bonus)

Because arrays get boring, we also implement a singly linked list toolkit to manage dynamic node chains:

* `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

---

## 🛠️ Getting Started

### Prerequisites

* A C compiler (`gcc` or `clang`)
* `make`

### Compilation

Clone the repository and jump right into the directory:

```bash
git clone https://github.com/aelbouss/libft
cd libft

```

Build the library:

```bash
make

```

This compiles all the source files using `-Wall -Wextra -Werror` and bundles them into an archive named `libft.a`.

To compile the linked list bonus functions as well:

```bash
make bonus

```

Need to clean up object files?

```bash
make clean    # removes .o object files
make fclean   # removes .o files AND libft.a
make re       # clean rebuild from scratch

```

---

## 💻 How to use it in your code

Include the header file in your C source:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *str = ft_strdup("Hello from Libft!");
    
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}

```

Compile your program against `libft.a`:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program

```

---

## 💡 What I actually learned

Beyond memorizing pointer arithmetic:

* **Edge cases are everywhere:** `INT_MIN`, empty strings, NULL pointers, overlapping memory buffers (`memmove` vs `memcpy`).
* **Valgrind and gdb are my best friends :** Memory leaks will haunt your sleep unless every `malloc` has a corresponding `free`.
* **Clean code matters:** When a linter restricts you to 4 arguments per function and 25 lines per block, you learn real code structure fast.

---