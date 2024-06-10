cmake_minimum_required(VERSION 3.15)
project(NomDeVotreProjet C)

# Détection de la compilation croisée et configuration des compilateurs
if(CMAKE_CROSSCOMPILING)
    set(CMAKE_C_COMPILER "/opt/homebrew/bin/arm-none-eabi-gcc" CACHE STRING "C compiler" FORCE)
    set(CMAKE_CXX_COMPILER "/opt/homebrew/bin/arm-none-eabi-g++" CACHE STRING "C++ compiler" FORCE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m4 -mthumb" CACHE STRING "C Compiler Flags" FORCE)
else()
    if(DEFINED ENV{CC})
        set(CMAKE_C_COMPILER $ENV{CC} CACHE STRING "C compiler" FORCE)
    else()
        set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang" CACHE STRING "C compiler" FORCE)
    endif()

    if(DEFINED ENV{CXX})
        set(CMAKE_CXX_COMPILER $ENV{CXX} CACHE STRING "C++ compiler" FORCE)
    else()
        set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++" CACHE STRING "C++ compiler" FORCE)
    endif()
endif()

# Inclure les répertoires d'en-têtes
include_directories(${PROJECT_SOURCE_DIR}/include)

# Ajouter les sources du projet pour compiler l'exécutable
add_executable(${PROJECT_NAME} src/main.c src/led_control.c src/button.c src/gpio.c)

# Configuration spécifique pour les tests unitaires locaux, non cross-compilés
if(NOT CMAKE_CROSSCOMPILING)
    enable_testing()
    add_subdirectory(tests)
endif()

# Configuration de l'archivage
set(CPACK_GENERATOR "TGZ")
include(CPack)
