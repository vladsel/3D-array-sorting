# 3D-array-sorting
(25.04.2020)

Research on the efficiency of sorting methods (direct selection No. 8, hybrid "insertion-exchange" algorithm, Shell sorting No. 1) on multidimensional arrays.

Arrange the three-dimensional array Array[P, M, N] as follows:

rearrange the sections of the array without decreasing the values of the vector of the first elements of each section of Array[*, 0, 0].

Researched methods and algorithms
• Sorting algorithm No. 8 of the direct selection method;
• Hybrid "insertion-exchange" algorithm;
• Algorithm No. 1 of the Shell sorting method (classic variant based on direct insertion No. 2) The number of stages and steps between elements at each stage should be taken depending on the length of the sequences being sorted.

Workaround methods
Using the values of the vector of the first elements of each section of Array[*, 0, 0] as the sort keys, rearrange the corresponding sections each time the keys need to be rearranged. When permuting sections, it is necessary to copy their elements, and not to copy pointers to them using C/C++ pointer operations.

Case studies
• Dependence of algorithm operation time on the size of array sections;
• Dependence of the algorithms' operation time on the shape of the cross-sections of the array.
