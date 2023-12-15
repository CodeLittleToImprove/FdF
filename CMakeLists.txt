cmake_minimum_required(VERSION 3.25)
project(fdf C)

set(CMAKE_C_STANDARD 99)

# Add the libft library
add_library(libft STATIC IMPORTED)
set_target_properties(libft PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)

# Add the mlx_linux library
add_library(mlx_linux STATIC IMPORTED)
set_target_properties(mlx_linux PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/mlx_linux/libmlx_Linux.a)

add_executable(fdf
        src/main.c
)

# Link the executable with the libft, mlx_linux, X11, and Xext libraries
target_link_libraries(fdf PRIVATE libft mlx_linux -lX11 -lXext)
