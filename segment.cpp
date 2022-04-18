#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <array>
#include <bits/stdc++.h>


using namespace std;

class SegmentTree {
public:
	//Creating a new empty tree only with the input size
	SegmentTree(int size){
		n = size;
		//Creating a vector that will act as the tree with double the values of size to be able to house the branching values
		//Each value created is 0
		data = vector<int>(2 * n, 0);
	}

	//Creating a tree using the information obtained from a file
	SegmentTree(vector<int> const &values){
		n = values.size();
		//Creating a vector that will act as the tree with double the values of size to be able to house the branching values
		if(n % 2 == 1){
			data = vector<int>(2 * n);
		}else{
			data = vector<int>(2 * n);
		}

		//Copy vector to second half of data
		copy(values.begin(), values.end(), &data[0] + n);
		//Each node is being filled in from the bottom up
		for (int index = n - 1; index > 0; index--){
			data[index] = min(data[index * 2], data[index * 2 + 1]);
		}
	}

	//Updates the value at a specified index with a new value
	void update(int index, int value){
		index += n;
		data[index] = value;

		//Updates the minimum of each node thats related to the updated index
		while (index > 1) {
			index /= 2;
			data[index] = min(data[2 * index], data[2 * index + 1]);
		}
	}

	//Searches through the vector to find the specified value
	void search(int info){
		vector<int> found;
		for(long unsigned int i = 0; i < data.size(); i++){
			if(data[i] == info){
				found.push_back(i+1);
			}
		}
		if(found.empty()){
			cout << info << " was not found." << endl;
		}else{
			for(long unsigned int j = 0; j < found.size(); j++){
				cout << info <<  " was found at: " << found[j] -1<< endl;
			}
			cout << "Found " << found.size() << " time(s)." << endl;
		}
	}

	//Inserts a new value at the specified index
	void insert(int insIndex, int insValue){
		data.insert(data.begin() + insIndex, insValue);
		data[insIndex] = insValue;
		this->n++;

		while (insIndex > 1) {
			insIndex /= 2;
			data[insIndex] = min(data[2 * insIndex], data[2 * insIndex + 1]);
		}
	}

	//Prints out what the tree/vector is currently holding and where, as well as creating a dot file for easier viewing
	void view(std::string file_name){
		int current = 2;
		ofstream output_file(file_name);
		for(long unsigned int i = 1; i < data.size(); i++){
			cout << "C" << i << ": " << data[i] << endl;
			output_file << "C" << i << " [label=""" << data[i] << "]" << endl;
			if(current < (this->n)*2){
				output_file << "C" << i << " -> {C" << current << ", C" << current+1 << "}" << endl;
				current += 2;
			}
		}

		// output_file << "C" << i << " -> {C" << current << ", C" << current+1 << "}" << endl;
	}

private:
	int n;
	vector<int> data;
};

//Used to read the input file
void readFile(string file_name, vector<int> * numVector){
    ifstream file(file_name);
    string str;

    while(!file.eof())
    {
        getline(file, str, ',');
        numVector->push_back(stof(str));
    }
    file.close();
}

int main(int argc, char* argv[]){
    string input_file = argv[1];
    vector<int> numVector;
    vector<string> trees;
    string treeName, pickTree;

    readFile(input_file, &numVector);

	SegmentTree st2(numVector);
	st2.view("normal.txt");
	st2.search(3);
	st2.insert(4,3);
	st2.view("insert.txt");
	st2.search(3);
}