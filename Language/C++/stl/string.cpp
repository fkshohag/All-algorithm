// Returns the length of a string
int stringLength(string s) {
  return s.length();
}

// Converts a string to the empty string
string stringClear(string s) {
  s.clear();
  return s;
}

// Returns true if the string is empty
bool stringEmpty(string s) {
  return s.empty();
}

// Returns the character of a string at a given index
char charAt(string s, int index) {
  return s.at(index);
}

// Returns a concatenation of strings left and right
string stringAppend(string left, string right) {
  return left+= right;
}

// Returns the result of inserting a string into another
string stringInsert(string s, string toInsert) {
  return s.insert(7, toInsert);
}

// Erases part of a string
string stringErase(string s) {
  return s.erase(6, 19);
}

// Replaces part of a string
string stringReplace(string s) {
  return s.replace(0, 7, "Things");
}

// Returns the first index of character c in string s
int stringFind(string s, char c) {
  return s.find(c);
}

// Returns the last index of character c in string s
int stringRFind(string s, char c) {
  return s.rfind(c);
}

// Returns the index of the first character in the string that is not c
int stringFirstNot(string s, char c) {
  return s.find_first_not_of(c);
}

// Returns the index of the first occurance of character c
int stringFirst(string s, char c) {
  return s.find_first_of(c);
}

// Returns part of a string
string stringSubstring(string s) {
  return s.substr(7, 7);
}

// Returns the first name, given a full name
string firstName(string s) {
  int firstSpaceIndex = s.find(' ');
  return s.substr(0, firstSpaceIndex);
}

// Returns the middle name, given a full name
string middleName(string s) {
  int firstSpaceIndex = s.find(' ');
  int lastSpaceIndex = s.find_last_of(' ');
  int lengthOfMiddleName = lastSpaceIndex - firstSpaceIndex - 1;
  return s.substr(firstSpaceIndex + 1, lengthOfMiddleName);
}

// Returns the last name, given a full name
string lastName(string s) {
  return s.substr(s.find_last_of(' ') + 1, s.length() - 1);
}

// Returns a capitalized version of a string
string capitalize(string s) {
  char first = s[0];
  first = toupper(first);
  s[0] = first;
  return s;
}

// Returns true if the string contains character c
bool include(string s, char c) {
  return s.find_first_of(c) != s.npos;
}

// Returns a string substituting character target with character replacement
string substitute(string s, char target, char replacement) {
  int indexToReplace = 0;
  while (include(s, target)) {
    indexToReplace = s.find(target);
    s[indexToReplace] = replacement;
  }
  return s;
}