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
//Creating a tree using the information obtained from a file
	SegmentTree(vector<int> const &values, string mode){
		n = values.size();
		//Creating a vector that will act as the tree with double the values of size to be able to house the branching values
		data = vector<int>(2 * n);
		original = values;
		this->mode = mode;

		//Copy vector to second half of data
		copy(values.begin(), values.end(), &data[0] + n);
		//Each node is being filled in from the bottom up
		for (int index = n - 1; index > 0; index--){
			if(mode == "min"){
				data[index] = min(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "max"){
				data[index] = max(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "sum"){
				data[index] = data[index * 2] + data[index * 2 + 1];
			}
		}
	}

	//Updates the value at a specified index with a new value
	void update(int index, int value){
		original[index] = value;
		n = original.size();

		//Recreating the vector that is used to represent our segment tree
		data = vector<int>(2 * n);
		copy(original.begin(), original.end(), &data[0] + n);
		for (int index = n - 1; index > 0; index--){
			if(mode == "min"){
				data[index] = min(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "max"){
				data[index] = max(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "sum"){
				data[index] = data[index * 2] + data[index * 2 + 1];
			}
		}
	}

	//Searches through the vector to find the specified value
	void search(int info){
		vector<int> found;
		for(long unsigned int i = 1; i < data.size(); i++){
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
		original.insert(original.begin() + insIndex, insValue);
		original[insIndex] = insValue;
		n = original.size();

		//Recreating the vector that is used to represent our segment tree
		data = vector<int>(2 * n);
		copy(original.begin(), original.end(), &data[0] + n);
		for (int index = n - 1; index > 0; index--){
			if(mode == "min"){
				data[index] = min(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "max"){
				data[index] = max(data[index * 2], data[index * 2 + 1]);
			}else if(mode == "sum"){
				data[index] = data[index * 2] + data[index * 2 + 1];
			}
		}
	}

	//Prints out what the tree/vector is currently holding and where, as well as creating a dot file for easier viewing
	void view(std::string file_name){
		int current = 2;
		int var = (n*2)-1;
		ofstream output_file(file_name);
		output_file << "digraph G {" << endl << "node [style=filled]" << endl;
		for(long unsigned int i = 1; i < data.size(); i++){
			cout << "C" << i << ": " << data[i] << endl;
			output_file << "C" << i << " [label=""" << data[i] << "]" << endl;
			if(current <= var){
				output_file << "C" << i << " -> {C" << current << ", C" << current+1 << "}" << endl;
				current += 2;
			}
		}
		output_file << "}" << endl;
	}

private:
	int n;
	string mode;
	vector<int> data;
	vector<int> original;
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

    readFile(input_file, &numVector);
    
    //Insert code here to create segment trees!
}
