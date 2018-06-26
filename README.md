# Hungarian Perfect Matching Algorithm


Minimum distance perfect matching algorithm computes the optimal matching of pairs of points where the overall distance is minimized. It takes a matrix M as input where M[i][j] is the distance between thing<sub>i</sub> and thing<sub>j</sub>, and produces a vector of pairs that are the optimal solution.

The algorithm provides an implementation for computing euclidean distance for points, but distance can be computed any way by the user.

#### Note
Maximum weight perfect matching can easily be computed as well by multiplying all values of the matrix by -1 and adding the absolute value of the minimum value in the matrix to all entries in the matrix.

### Compile and run

To compile use the command:
```
g++ -std=c++17 main.cpp csv.cc hungarian.cc -o hung
```
Run with the following:
```
./hung [file1 Path] [file2 Path]
```


### Test

For testing, I provide two files d1.csv and d2.csv

Both files need to be in csv format with each 2-d point on one line. Any other format will not be recognized and
will give undegined output.

This implementation of the algorithm is based on a python implementation by Dr. Norbert Zeh with many optimizations
for C++.

The code of csv.cc is from an online source with full rights of distribution and modifications. It was modified to fit
the needs of this project.
