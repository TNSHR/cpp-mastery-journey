#ifndef RESOURCE_H
#define RESOURCE_H

#include<cstddef>

class Resource{

    private:
       int* data;
       std::size_t size;
    
    public:
      //Constructor
      explicit Resource(std::size_t size);

      //Deconstructor
      ~Resource();

      //copy constructor

      Resource(const Resource& other);

      //Move constructor

      Resource(Resource&& other) noexcept;

      //Copy Assignment Operator
      Resource& operator=(const Resource& other);

      //Move assignment Operator
      Resource& operator = (Resource&& other) noexcept;

      //Display
      void display() const;

      //Get Size
      std::size_t getSize() const;

};
#endif
