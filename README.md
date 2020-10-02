# Segment_tree
A simple code for segment tree data structure.
It is very useful data structure which can be used to answer the query and updating the array in only O(logn) time complexity.
It has different functions to performs the task and build in c++.




A Segment Tree is a data structure that can be used to perform range queries and range updates.
It is a height-balanced binary tree, usually built on top of an Array. Segment Trees can be used to solve Range Min/Max & Sum Queries and 
Range Update Queries in O(log n) time

There are two types of queries:

    Update: Given idx

and val, update array element A[idx] as A[idx]=A[idx]+val
.
Query: Given l
and r return the value of A[l]+A[l+1]+A[l+2]+…..+A[r−1]+A[r] such that 0≤l≤r<N

Queries and Updates can be in any order. 



