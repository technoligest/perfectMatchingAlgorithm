
The basic idea of this implementation is to get 2 sets of points, and to calculate the distance between every point
in one set with every other point in the other set. Store that in an adjacency matrix and use the hungarian algorithm
to find the perfect matching for all of the points in the bipartite graph.

To compile use the command:
g++ -std=c++14 main.cpp io.cc csv.cc hungarian.cc -o hung

Run with the following:
./hung [file1 Path] [file2 Path]

For testing, I provide two files d1.csv and d2.csv

Both files need to be in csv format with each 2-d point on one line. Any other format will not be recognized and
will give undegined output.

This implementation of the algorithm is based on a python implementation by Dr. Norbert Zeh with many optimizations
for C++.

The code of csv.cc is from an online source with full rights of distribution and modifications. It was modified to fit
the needs of this project.
