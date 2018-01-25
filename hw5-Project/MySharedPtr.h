#ifndef _MY_SHARED_PTR_H_
#define _MY_SHARED_PTR_H_


template <class T> class MySharedPtr {
public:
    //**************************************************************************************************
    //* function name   :   MySharedPtr
    //* Description     :   constructor.
    //* Parameters      :   pointer from type T*.
    //* Return value    :   nothing (constructor).
    //**************************************************************************************************
    
    MySharedPtr() : ptr_(nullptr) {
        count_ = new int;
    };
    
    
    MySharedPtr(T* ptr) : ptr_(ptr) {
        count_ = new int;
        *count_ = 1;
    };
    
    //**************************************************************************************************
    //* function name   :   MySharedPtr
    //* Description     :   copy constructor.
    //* Parameters      :   pointer from type T*.
    //* Return value    :   nothing (constructor).
    //**************************************************************************************************
    MySharedPtr(const MySharedPtr& ptr) {
        ptr_ = ptr.ptr_;
        count_ = ptr.count_;
    }
//    MySharedPtr(MySharedPtr& new_ptr){
//        ptr_ = new_ptr.ptr_;
//        count_ = new_ptr.count_;
//        (*count_)++;
//    };
    
    //**************************************************************************************************
    //* function name   :   ~MySharedPtr
    //* Description     :   destructor.
    //* Parameters      :   none.
    //* Return value    :   nothing (destructor).
    //**************************************************************************************************
    ~MySharedPtr(){
        (*count_)--;
        if (!(*count_))
            ptr_->~T(); // look for potential memory leak
    };
    
    //**************************************************************************************************
    //* function name   :   get
    //* Description     :   returns the saved pointer.
    //* Parameters      :   none.
    //* Return value    :   returns the saved pointer.
    //**************************************************************************************************
    T* get() const { return ptr_; };
    
    //**************************************************************************************************
    //* function name   :   * operator
    //* Description     :   dereferance for the pointer.
    //* Parameters      :   none.
    //* Return value    :   returns the dereferanced object.
    //**************************************************************************************************
    T& operator*() const { return *ptr_; };
    
    //**************************************************************************************************
    //* function name   :   -> operator
    //* Description     :   returns the saved pointer.
    //* Parameters      :   none.
    //* Return value    :   returns the saved pointer.
    //**************************************************************************************************
    T* operator->() const { return ptr_; };
    
    //**************************************************************************************************
    //* function name   :   = operator
    //* Description     :   assigment overload. When the old object is not being held by any pointer
    //*                     - then it is being released.
    //* Parameters      :   none.
    //* Return value    :   returns the new assigment reference.
    //**************************************************************************************************
    MySharedPtr& operator=(const MySharedPtr& new_ptr){
        if (this != &new_ptr){
            if (!(--(*count_)))
                ptr_->~T(); // look for potential memory leak
            ptr_ = new_ptr.ptr_;
            count_ = new_ptr.count_;
            (*count_)++;
        }
        return *this;
    };
    
private:
    int* count_;
    T* ptr_;
};


#endif // _MY_SHARED_PTR_H_
