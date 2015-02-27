set( project_name "core" )

file(GLOB_RECURSE HEADERS *.h)
file(GLOB_RECURSE SOURCES *.cpp)

add_library(${project_name} ${SOURCES} ${HEADERS})

# Linking qt core to the current project
target_link_libraries(${project_name} Qt5::Core)

# Generating translations
GenerateTranslations()
