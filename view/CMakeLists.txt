set(project_name "gui")

file(GLOB HEADERS *.h)
file(GLOB SOURCES *.cpp)

add_executable(${project_name} ${SOURCES} ${HEADERS})

target_link_libraries(${project_name} Qt5::Core Qt5::Widgets core)
