#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void print();

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator c_;
  std::vector<T> vec;

  void trickleDown(); //helper function to trickle down after swapping
  void trickleUp(); //helper function to trickle up after pushing
};

// Add implementation of member functions here

//printing for debugging
template <typename T, typename PComparator>
void Heap<T,PComparator>::print() {
  for (size_t i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : m_(m), c_(c)
{

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("empty heap");

  }
  //swap the top and last
  T temp = vec[0];
  vec[0] = vec[vec.size()-1];
  vec[vec.size()-1] = temp;
  

  vec.pop_back(); //remove the switched top node
  trickleDown();

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vec.push_back(item); //push the argument into the vector


  trickleUp();

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(Heap<T,PComparator>::size() == 0)
  {
    return true;
  }
  return false;

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return vec.size();
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown() 
{
  size_t curr = 0; //start with the top

  while(((curr*m_) + 1) < vec.size()) {
    size_t child = curr * m_ + 1; //left-most child

    for(int i = 2; i <= m_; ++i) //comparing the children.
    {
      size_t currChild = curr * m_ + i;

      if(currChild < vec.size()) {
        if(c_(vec[currChild], vec[child])) { //true if current child is better
          child = currChild;
        }
      }
    }

    if(c_(vec[child], vec[curr])) //comparing child to parent. true if child is better
    {
      //swap if child is better
      T temp = vec[child];
      vec[child] = vec[curr];
      vec[curr] = temp;
    }
    else { //if parent is better, then stop
      break;
    }

    curr = child; //change current to the swapped child
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp() //after pushing back
{
  size_t curr = vec.size() - 1;

  while(curr > 0) {
    size_t parent = (curr - 1)/m_; 

    //compare children
    if(c_(vec[curr], vec[parent])) { //if current is better than parent
      T temp = vec[curr];
      vec[curr] = vec[parent];
      vec[parent] = temp;
    }
    else {
      break;
    }
    
    curr = parent; //change current to the swapped parent
  }
}


#endif

