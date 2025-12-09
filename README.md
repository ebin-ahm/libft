*This project has been created as part of the 42 curriculum by ebin-ahm.*

# Libft

---

## Description
Libft is a custom C library that reimplements essential functions from the standard C library while introducing additional utility functions that are not originally provided by libc.  
Certain functions (such as strlen, memcpy, atoi, etc.) already exist in the C standard library, but as part of the 42 curriculum, these functions must be rewritten from scratch.  
This requirement ensures a deep understanding of how low-level operations work internally, including pointer manipulation, memory access, boundary safety, and algorithmic behavior.

In addition to these reimplemented functions, libft also includes “novel” utility functions — functions that do not exist in libc but are extremely useful in real projects.  
These include string manipulation helpers (substr, strtrim, split), integer conversion (itoa), function mappers (strmapi, striteri), file descriptor output helpers, and a complete linked list API.

---

## Instructions

### Compilation
To compile the library, run:
```bash
make
```

To remove object files:
```bash
make clean
```

To remove object files AND the library:
```bash
make fclean
```

To rebuild everything:
```bash
make re
```

### How to Compile Your Program With libft
```bash
gcc -Wall -Wextra -Werror main.c libft.a -o program
```

---

## Resources

### Classic References
- man pages for standard library functions  
- 42 Norminette rules
- 42 Libft PDF version 19.0

### AI-Assisted Learning
AI (ChatGPT) was used for:
1. Clarifying concepts such as pointers, memory operations, and linked list operations  
2. Explaining algorithms, edge cases, and debugging  

All code was manually written and verified by ebin-ahm.

---

# Library Overview

---

## Part 1 — Libc Reimplemented Functions

### Character Checks
- ft_isalpha — checks if a character is alphabetic  
- ft_isdigit — checks if a character is a digit  
- ft_isalnum — checks if a character is alphanumeric  
- ft_isascii — checks if a character is within ASCII range  
- ft_isprint — checks if a character is printable  

### Case Conversion
- ft_toupper — converts a character to uppercase  
- ft_tolower — converts a character to lowercase  

### String Functions
- ft_strlen — returns the length of a string  
- ft_strchr — locates the first occurrence of a character  
- ft_strrchr — locates the last occurrence of a character  
- ft_strncmp — compares strings up to a given length  
- ft_strnstr — locates a substring within a string  
- ft_strlcpy — safe string copy with size limit  
- ft_strlcat — safe string concatenation with size limit  
- ft_strdup — allocates and returns a duplicate string  

### Memory Functions
- ft_memset — fills memory with a byte value  
- ft_bzero — sets memory to zero  
- ft_memcpy — copies memory (non-overlapping)  
- ft_memmove — copies memory (overlapping-safe)  
- ft_memchr — searches memory for a byte  
- ft_memcmp — compares memory regions  

### Conversion
- ft_atoi — converts a string to an integer  

---

## Part 2 — Additional Functions

### String Helpers
- ft_substr — extracts a substring from a given string  
- ft_strjoin — joins two strings into a new string  
- ft_strtrim — trims specified characters from both ends of a string  
- ft_split — splits a string into an array of strings  
- ft_itoa — converts an integer into a string  
- ft_strmapi — applies a function to each character (returns new string)  
- ft_striteri — applies a function to each character (modifies in place)  

### Output Helpers
- ft_putchar_fd — writes a single character to a file descriptor  
- ft_putstr_fd — writes a string to a file descriptor  
- ft_putendl_fd — writes a string followed by a newline to a file descriptor  
- ft_putnbr_fd — writes an integer as text to a file descriptor  

---

## Part 3 — Linked List Functions

### List Creation & Access
- ft_lstnew — creates a new list node  
- ft_lstsize — returns the number of nodes  
- ft_lstlast — returns the last node  

### Insertions
- ft_lstadd_front — adds a node to the beginning of a list  
- ft_lstadd_back — adds a node to the end of a list  

### Deletion & Clearing
- ft_lstdelone — deletes a single node and frees its content using a function  
- ft_lstclear — deletes an entire list and frees all content  

### Iteration & Mapping
- ft_lstiter — applies a function to the content of each node  
- ft_lstmap — creates a new list by applying a function to each node  

---
