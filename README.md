 # Segment Trees
 
  1. [Creating the Segment Tree](#creating-the-segment-tree)
  2. [Updating the Segment Tree](#updating-the-segment-tree)
  3. [Inserting into the Segment Tree](#inserting-into-the-segment-tree)
  4. [Viewing your Segment Tree](#viewing-your-segment-tree)

Report:

https://docs.google.com/document/d/1jL8fjUv6Un9rhf4OuqHGcZNyCn3NJgp3WJ7-5Q-driw/edit?usp=sharing

 # [Creating the Segment Tree](#segment-trees)
 We first create a vector to store the values from our input text file using command-line arguments:
 ![image](https://user-images.githubusercontent.com/72944152/163855348-ddc1303a-7534-4061-b164-29d5e6b56595.png)
 
 You can use the values provided in numbers.txt, or make your own. If making your own, make sure each value is seperated by a comma.
 
 ```
 6,5,4,3,2,1
 ```
 
 EX:
 ```
 g++ -std=c++11 -Wall segment.cpp -o test -ggdb
 ./test numbers.txt
 ```
 

Whe then create another vector double the size of the first minus 1, were we put the values towards the end of the vector:
![image](https://user-images.githubusercontent.com/72944152/163862583-e5f06512-6d98-4ee6-b2f0-7e5a1a9403c6.png)

The second variable can be either, "sum", "max" or "min", depending on what you want your tree to do.
1. Sum returns the sum of all the values in the vector/tree.
2. Max returns the maximum value of the values in the vector/tree.
3. Min returns the minimum value of the values in the vector/tree.

EX:
```
SegmentTree st(numVector, "min");
```

This will be our Segment Tree, for all intents and purposes. 

![image](https://user-images.githubusercontent.com/72944152/163905913-7f21a580-58dc-4c6f-bf6d-9c4e1f8ff18e.png)

![image](https://user-images.githubusercontent.com/72944152/163906150-8ec60378-7048-48b7-905c-90832c73684c.png)

 # [Updating the Segment Tree](#segment-trees)
 When calling the function insert, it can take in two int variables, (index, value):
 
 EX: ```st.update(5,0);```
 
 This would update the tree we created at its 6th node due to how vectors are counted.
 
 ![image](https://user-images.githubusercontent.com/72944152/163906668-11c3b015-bf0c-4d0e-bb12-eaf5123c3d71.png)
 
 This would then update the entire segment tree, resulting on a new minimum.
 
![image](https://user-images.githubusercontent.com/72944152/163906554-ac86390a-47ca-4f3d-862d-306e9681f2ce.png)
 
 
 # [Inserting into the Segment Tree](#segment-trees)

 When calling the function insert, it can take in two int variables, (index, value):
 
 EX: ```st.insert(4,3);```
 
 This would insert the value in the tree we created at its 5th node, pushing every value after it to the right.
 
 ![image](https://user-images.githubusercontent.com/72944152/163906880-ce6c3e29-38f1-4870-83d8-2b8902301ec6.png)
 
  This would then update the entire segment tree, possibly resulting on a new minimum.
  
  ![image](https://user-images.githubusercontent.com/72944152/163906951-54dac2c4-427e-4c1a-ba4d-0ed5bae8a563.png)

# [Viewing your Segment Tree](#segment-trees)

When calling the function view, it can take in a string value, (output_file.txt):

EX: ```st.view("normal.txt");```

This should print out the values of each node in order and create a txt file that has text in it that can be used to create a DOT file, which can be viewed using this online tool: https://dreampuf.github.io/GraphvizOnline/

It should create a DOT file similar to the ones above.

# [Searching for a value in the Segment Tree](#segment-trees)

When calling the function search, it can take in an int value, (value):

EX: ```st.search(3);```

It should output where the value is in the tree, and how many times in total is has been found.

Output shold look similar to this:

```
3 was found at: 4
3 was found at: 9
Found 2 time(s).
```

 
