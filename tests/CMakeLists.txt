set(target all_tests)

#file(GLOB hdrs "*.h*" "../include/*.h" "../gtest/*.h")
file(GLOB hdrs "*.h*")

target_link_libraries(${target} gtest)