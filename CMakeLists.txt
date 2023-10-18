cmake_minimum_required(VERSION 3.26)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_library(two-sum two-sum/main.cc)
add_library(add-two-numbers add-two-numbers/main.cc)
add_library(longest-substring-without-repeating-characters longest-substring-without-repeating-characters/main.cc)
add_library(longest-palindromic-substring longest-palindromic-substring/main.cc)
add_library(integer-to-english-words integer-to-english-words/main.cc)
add_library(lru-cache lru-cache/main.cc)
add_library(lfu-cache lfu-cache/main.cc)
add_library(design-in-memory-file-system design-in-memory-file-system/main.cc)
add_library(design-log-storage-system design-log-storage-system/main.cc)
