//---------------------------------------
//instantiation.cpp

//file to link the templated .cpp files

#include "Students.cpp"
#include "Lab5.cpp"
#include "Queue.cpp"

template class Queue<int>;
template class QueueNode<int>;

template class Queue<Students*>;
template class QueueNode<Students*>;
