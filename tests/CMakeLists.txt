# Spécifie la version minimale requise de CMake pour ce projet.
cmake_minimum_required(VERSION 3.15)

# Utilise clang comme compilateur C et C++
set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)

# Définit le nom du projet.
project(Tests)

# Ajoute un répertoire d'inclusion aux chemins de recherche pour les fichiers d'en-tête.
include_directories(${PROJECT_SOURCE_DIR}/../include)

# Crée un exécutable nommé 'run_tests' avec les fichiers sources spécifiés.
add_executable(run_tests 
    test_button.c 
    ../src/button.c 
    ../src/gpio.c 
    ../src/led_control.c
)

# Active le framework de tests intégré de CMake.
enable_testing()

# Ajoute un test nommé 'ButtonTests' qui exécute l'exécutable 'run_tests'.
add_test(NAME ButtonTests COMMAND run_tests)

