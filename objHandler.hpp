#ifndef OBJHANDLER_4620
#define OBJHANDLER_4620

#include <vector>
#include <string>

#include "Vector3.hpp"
#include "Triangle.hpp"
#include "file_util.h"


struct objHandler{
  private:
  Vector3 zero_vector = Vector3(0,0,0);
  //indexs to help find and identify vectors for triangles
  char index1;
  char index2;
  char index3;
  public:
  std::vector<Triangle> triangles = {};
  //obj faces start at index one so fill 0 index with 0
  std::vector<Vector3> vectors = {zero_vector};
  std::vector<Vector3> vector_normals ={zero_vector};
  std::vector<Vector3> vector_uv = {zero_vector};

  void evaluateObjFileLine(std::vector<std::string> parts){
      if (parts[0] == "v"){
        vectors.push_back(Vector3(std::stof(parts[1]),std::stof(parts[2]),std::stof(parts[3])));
      } else if (parts[0] == "vt"){
        vector_uv.push_back(Vector3(std::stof(parts[1]),std::stof(parts[2]),std::stof(parts[3])));
      } else if (parts[0] == "vn"){
        vector_normals.push_back(Vector3(std::stof(parts[1]),std::stof(parts[2]),std::stof(parts[3])));
      } else if (parts[0] == "f"){
        index1=parts[1][0];
        index2=parts[2][0];
        index3=parts[3][0];
        triangles.push_back(Triangle(vectors[index1],vectors[index2],vectors[index3]));
      } 
  }
};



#endif