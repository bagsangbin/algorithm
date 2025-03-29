#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <stdio.h>

#include "Tokenizer.h"
#include "Student.h"

inline std::string trim(std::string str) { 
	str.erase(0, str.find_first_not_of(' '));       //prefixing spaces 
	str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces 
	return str; 
}

vector<Student> readInput(string fName);
int mergesort2(vector<Student>& student_list);
void mergesort2(vector<Student>&S, int low, int high);
void merge2(vector<Student>&A, int low, int mid, int high);
void print_Student (vector<Student> sl);

const string fName = "studentlist.txt";
const int NO_LOOP = 100;

int main(){
	vector<Student> A = readInput(fName);
	vector<Student> B;
	print_Student(A);

	clock_t start = clock();
	for (int i = 0; i < NO_LOOP; i++)  {  
		B = A; 		
		mergesort2(B);	
	}
	clock_t end = clock();  double diff = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "------------" << endl;
	printf("%s = %13.9lf msec\n", "MERGE2", diff / NO_LOOP * 1000);
	print_Student(B);

	start = clock();
	for (int i = 0; i < NO_LOOP; i++)  {  
		vector<Student> B = A; 
		sort(B.begin(), B.end());
	}
	end = clock();  
	diff = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "------------" << endl;
	printf("%s = %13.9lf msec\n", "STL.SORT", diff / NO_LOOP);
	print_Student(B);
	return 1;
}

//high > low no
//high - low > 5 
//high - low < 5 exchage sort 실행
void partial(vector<Student> &S,int low, int high, int&pivotPoint){
	int i, j;
	Student pivotItem;
	Student temp;

	pivotItem = S[low];
	for(i = low +1; i <= high; i++){
		if(S[i] < pivotItem){
			j++;
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;
		}
		pivotPoint = j;
		temp = S[low];
		S[low] = S[pivotPoint];
		S[pivotPoint] = temp;
	}

}
void quickSort(vector<Student> &S, int low, int high){
	int pivotPoint;

	if(high - low >= 5){
		partial(S, low, high, pivotPoint);
		quickSort(S,low, pivotPoint-1);
		quickSort(S,pivotPoint+1, high);
	}
	else{
		
	}

}

int mergesort2(vector<Student>& S) {
	mergesort2(S, 0, S.size()-1);
	return 1;
}

void mergesort2(vector<Student>& S, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort2(S, low, mid);
		mergesort2(S, mid+1, high);
		merge2(S, low, mid, high);
	}
}

void merge2(vector<Student>& S, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid +1;
	k = low;
	vector<Student> U (S.size()); 
	while (i <= mid && j <= high) {
		if (S[i] < S[j]) { U[k] = S[i]; i++; } 
		else             { U[k] = S[j];	j++; }
		k++;
	}
	if (i > mid) { 
		while (k <= high) { U[k] = S[j]; k++, j++; }
	} else {
		while (k <= high) { U[k] = S[i]; k++, i++; }
	}
	int n = low;
	while (n <= high)     { S[n] = U[n]; n++; }
}


vector<Student> readInput(string fName){
	vector<Student> student_list;
	ifstream fin(fName.c_str());
	if (fin.fail()) {
		cerr << "Can't open " << fName << endl;
		return student_list;
	}
	string line;
	string name, telno;
	while( getline(fin, line) ){
		cout << line << endl;
		Tokenizer tokens(line, "#");
		name = trim(tokens.next());
		telno = trim(tokens.next());
		Student student = Student(name, telno);
		student_list.push_back(student);
	}
	return student_list;
}

void print_Student (vector<Student> sl){
	for (int i = 0; i < sl.size(); i++) {
		cout << i << ":" << sl[i].get_name() << "::" << sl[i].get_telno() << endl;
	}
}

string readKey(){
	char line[BUFSIZ];

	cout << "Type the name > ";
	cin.getline(line, BUFSIZ) ;
	return trim(string(line));
}

int seqSearch(vector<Student> student_list, string key){
	for(int i = 0; i < student_list.size() ; i++){
		if(key == student_list[i].get_name()) return i;
	}
	return -1;	
}


