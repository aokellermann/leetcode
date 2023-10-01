cmake_minimum_required(VERSION 3.26)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_library(two-sum two-sum/main.cc)
add_library(add-two-numbers add-two-numbers/main.cc)
add_library(longest-substring-without-repeating-characters longest-substring-without-repeating-characters/main.cc)
add_library(longest-palindromic-substring longest-palindromic-substring/main.cc)
