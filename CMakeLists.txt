cmake_minimum_required(VERSION 3.25)
project(DataStructure_and_Algorithm C)

set(CMAKE_C_STANDARD 11)

include_directories(LinkList)
# Singly LinkedList Implementation
add_executable(DataStructure_and_Algorithm LinkList/main.c LinkList/linkList.c)
# Circular Singly LinkedList Implementation
add_executable(Circular CircularLinkList/Circular.c)
# Doubly LinkedList Implementation
add_executable(Doubly DoublyLinkedList/dbLinkList.c)
# LinedList student Challenge
add_executable(Challenge1 LinkedListChallenge/Challenge1.c)
add_executable(Challenge2 LinkedListChallenge/Challenge2.c)
add_executable(Challenge3 LinkedListChallenge/Challenge3.c)
# Implementation of Stack using Array
add_executable(StackArray Stack/stackArray.c)

add_executable(StackLinkedList Stack/stackLinkedList.c)
add_executable(Paranthesis Stack/paranthesisCheck.c)
add_executable(studentStackChallenge1 Stack/sudentChallenge.c)
add_executable(intopost Stack/infixToPostfix.c)
add_executable(studentChallenge2 Stack/studentChallenge2.c)
add_executable(postfixCalculate Stack/postfixCalculation.c)
