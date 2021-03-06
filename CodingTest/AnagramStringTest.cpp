/*
Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains the same characters, 
only the order of characters can be different. 
For example, “abcd” and “dabc” are an anagram of each other.
*/


#include<stdio.h>
#include<string>
#include<iostream>
#include <unordered_map>
#include <unordered_set> 
using namespace std;


bool isAnagramsUsingUMultiSets(string s,string t) {
	if(s.length()!=t.length()) return false;
	unordered_multiset<char> umset;
	for(auto i:s) {
		umset.insert(i);
	}
	for(auto j:t) {
		auto it = umset.find(j);
		if(it!=umset.end()) {
			umset.erase(it);
		} else {
			return false;
		}
	}
	return true;
}
// Using unorder maps
bool isAnagramsUsingUMaps(string s,string t) {
	unordered_map<char,int> charMap;
	if(s.length()!=t.length()) return false;
	int i;
	cout<<endl<<"***********************************"<<endl;
	for(i= 0;i<s.length();i++) {
		charMap[s.at(i)]++;
		cout<<endl<<"second = "<<charMap[s.at(i)]; 
	}
	cout<<endl<<"***********************************"<<endl;

	for(i= 0;i<t.length();i++) {
		if(charMap[t.at(i)] == 0) return false;
		charMap[t.at(i)]--;
	}
	
	return true;
}


int main() {
	bool result = isAnagramsUsingUMultiSets("AAmit","imAtA");
	printf(" Result = %d",result);
	return 0;
}
