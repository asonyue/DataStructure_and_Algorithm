# DataStructure_and_Algorithm

Implementing Data Structure and Algorithm using C

## (Part 1) Link List Implementation

### Display:
When the current pointer pointed to a node that is not NULL,
It will continuously to print out the value of each node and
move the current pointer to the next node.

### Count:
It counts the number of nodes in the link list. Firstly, the
length is set to zero for the link list. Each time it transverse
to the next node, the variable l will increment as a counter.

### Sum:
It counts the sums in the link list. We initialise the sum variable to zero at first.
Each time the current pointer transfer to the next node, it will add the current value
into the sum variable.

### Max:
It find out the max element in the link list. Firstly, we set variable max
into a smallest number. Then, we compare the current element by the
current pointer to the max each time. If any number greater than max, max
will be updated.

### LSearch:
This function is used to search through the link list to see
if the targeted value existed or not and return the value if
it is found, else return NULL.