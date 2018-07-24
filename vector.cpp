#ifndef VECTOR_H
#define VECTOR_H
// The class declaration must have doxygen comments – put these in

template <class T>
class Vector 
{
  public:
    Vector(){
      array = new T[1];
      containerSize = 1;
      filledLength = 0;
    }
    
    /**
     *  \brief Get value at given index
     *  
     *  \param [in] index index of value to get
     *  \pre Index > 0 and index < length
     *  \post If index < 0 then index = 0. If index > length then index
     *  \return Value at given index = length
     */
    T& get(int index){
      if (index > filledLength) index = filledLength;
      else if (index < 0) index = 0;
      
      return array[index];
    }
    
    /**
     *  \brief Add value at specified index
     *  
     *  \param [in] t Value to add
     *  \param [in] index Index to add value into
     *  \return 
     *  \pre Index > 0 and index < length
     *  \post If index < 0 then index = 0. If index > length then index = length
     */
    void insert(T t, int index){
      if (index < 0) index = 0;
      if (index > filledLength) index = filledLength;
      filledLength++;
      
      T* tempArray;
      if (filledLength > containerSize){
        containerSize = containerSize*2;
        tempArray = new T[containerSize];
      }
      else tempArray = new T[containerSize];
      
      for (int i = 0; i < index; i++){
        tempArray[i] = array[i];
      }
      tempArray[index] = t;
      for (int i = index; i < filledLength-1; i++){
        tempArray[i+1] = array[i];
      }
      delete[] array;
      array = tempArray;
    }
    
    /**
     *  \brief Remove value at specified index
     *  
     *  \param [in] index Index to remove value from
     *  \return 
     *  \pre Index > 0 and index < length
     *  \post If index < 0 then index = 0. If index > length then index = length
     */
    void remove(int index){
      if (index < 0) index = 0;
      if (index > filledLength) index = filledLength;
      
      T* tempArray = new T[containerSize];
      for (int i = 0; i < index; i++){
        tempArray[i] = array[i];
      }
      for (int i = index+1; i < filledLength; i++){
        tempArray[i-1] = array[i];
      }
      delete[] array;
      array = tempArray;
      filledLength--;
    }
    
    /**
     *  \brief Add value to end of vector
     *  
     *  \param [in] t Value to add
     *  \return 
     *  \pre 
     *  \post 
     */
    void add(T t){
      if (filledLength == containerSize) insert(t, filledLength);
      else{
        array[filledLength] = t;
        filledLength++;
      }
    }
    
    /**
     *  \brief Get length of vector
     *  
     *  \return Vector actual length (not container size)
     *  \pre 
     *  \post 
     */
    int getLength(){
      return filledLength;
    }
    
    /**
     *  \brief Get container size
     *  
     *  \return Size of container (not actual vector length)
     *  \pre 
     *  \post 
     */
    int getContainerSize(){
      return containerSize;
    }
    
  private:
    T* array;
    int containerSize;
    int filledLength;
};


#endif
