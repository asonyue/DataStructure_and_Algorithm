cmake_minimum_required(VERSION 3.25)
project(DataStructure_and_Algorithm C)

set(CMAKE_C_STANDARD 11)

include_directories(LinkList)

add_executable(DataStructure_and_Algorithm LinkList/main.c LinkList/linkList.c)

add_executable(Circular CircularLinkList/Circular.c)

add_executable(Doubly DoublyLinkedList/dbLinkList.c)
