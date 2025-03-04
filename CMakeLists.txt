cmake_minimum_required(VERSION 3.10)
project(KonkrGame)

# Définir la norme C++ (C++17 dans ce cas)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Trouver la bibliothèque SDL2
find_package(SDL2 REQUIRED)

# Inclure les répertoires d'en-tête
include_directories(${CMAKE_SOURCE_DIR}/include)

# Ajouter les fichiers sources
add_executable(KonkrGame 
    src/main.cpp 
    src/Game.cpp 
    src/Renderer.cpp 
    src/Map.cpp
)

# Lier les bibliothèques SDL2
target_link_libraries(KonkrGame ${SDL2_LIBRARIES})

# Ajouter les répertoires d'inclusion de SDL2
target_include_directories(KonkrGame PRIVATE ${SDL2_INCLUDE_DIRS})