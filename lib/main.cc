#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include "hungarian.h"

using std::cout;
using std::endl;


double distance(const std::vector<double> &instance1, const std::vector<double> &instance2){
  if(instance1.size() != instance2.size())
    return -1;
  double result = 0;
  size_t size = instance1.size();
  for(int i = 0; i < size; ++i){
    result += pow(instance1[i] - instance2[i], 2);
  }
  return result;
}

//Calculate the distance matrix between two sets of points
//Algorithm expects that that two sets are of the same size and the points are in 2-d space.
hungarian::Matrix<double> calcMatrix(const hungarian::Matrix<double> &m1, const hungarian::Matrix<double> &m2){
  assert(m1.size() == m2.size());
  size_t size;
  if(!m1.empty()){
    size = m1[0].size();
  }
  hungarian::Matrix<double> result(m1.size(), std::vector<double>(m2.size(), 0));
  for(int i = 0; i < m1.size(); ++i){
    assert(m1[i].size() == size);
    assert(m2[i].size() == size);
    for(int j = 0; j < m2.size(); ++j){
      result[i][j] = distance(m1[i], m2[j]);
    }
  }
  return result;
}


int main(int argc, char **argv){
  if(argc != 3){
    cout << "Usage: ./hungarian <inputFile1> <inputFile2>" << endl;
    exit(1);
  }
  std::ifstream file(argv[1]);
  cout << argv[1] << endl;
  const auto &m1 = hungarian::readCSVDataset(file);
  cout << m1.size() << endl;
  cout << m1[0].size() << endl;
  file.close();
  file.open(argv[2]);
  const auto &m2 = hungarian::readCSVDataset(file);
  file.close();

  const auto &distances = calcMatrix(m1, m2);

  const auto &result = hungarian::minimumWeightPerfectMatching(distances);
  for(auto i :result){
    cout << i.first << "\t" << i.second << endl;
  }
  return 0;
}