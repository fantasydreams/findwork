#include <vector>
#include <string>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList);
int ladderLength1(string beginWord, string endWord, vector<string>& wordList);
int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordList);
int ladderLengthBiBFS(string beginWord, string endWord, vector<string>& wordList);
int ladderLengthBiBFS1(string beginWord, string endWord, vector<string>& wordList);