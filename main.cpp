#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Voter {
  string id;
  int age;
};

struct Candidate {
  string name;
  int number;
};

vector<Voter> voters;
vector<Candidate> candidates;

void readVotersFromFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Failed to open file: " << filename << endl;
    exit(1);
  }

  string line;
  while (getline(file, line)) {
    vector<string> tokens = split(line, ",");
    if (tokens.size() != 2) {
      cerr << "Invalid voter record: " << line << endl;
      exit(1);
    }

    Voter voter;
    voter.id = tokens[0];
    voter.age = stoi(tokens[1]);
    voters.push_back(voter);
  }
}

void readCandidatesFromFile(const string& filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Failed to open file: " << filename << endl;
    exit(1);
  }

  string line;
  while (getline(file, line)) {
    vector<string> tokens = split(line, ",");
    if (tokens.size() != 2) {
      cerr << "Invalid candidate record: " << line << endl;
      exit(1);
    }

    Candidate candidate;
    candidate.name = tokens[0];
    candidate.number = stoi(tokens[1]);
    candidates.push_back(candidate);
  }
}

bool isVoterEligible(const Voter& voter) {
  return voter.age >= 18 && voter.age <= 70;
}

bool isCandidateValid(const Candidate& candidate) {
  return candidate.number >= 1 && candidate.number <= 6;
}

void scanVoterId() {
  // This function uses the camera of the device to scan the voter ID.
  // The scanned ID is then stored in a CSV file.
}

bool compareVoterId(const string& voterId, const vector<Voter>& voters) {
  // This function compares the voter ID with the IDs in the CSV file.
  // If the voter ID is found, the function returns true.
  for (const Voter& voter : voters) {
    if (voter.id == voterId) {
      return true;
    }
  }
  return false;
}

void showCandidates() {
  // This function shows the names of the candidates on the screen.
  for (const Candidate& candidate : candidates) {
    cout << candidate.name << endl;
  }
}

void vote(const int& candidateNumber) {
  // This function lets the voter vote for a candidate by entering their number.
  // The vote is then recorded in a blockchain.
  if (!isCandidateValid(candidates[candidateNumber - 1])) {
    cerr << "Invalid candidate number." << endl;
    return;
  }

  // Record the vote in the blockchain.
}

int main() {
  readVotersFromFile("voters.csv");
  readCandidatesFromFile("candidates.csv");

  // Scan the voter ID.
  scanVoterId();

  // Compare the voter ID with the IDs in the CSV file.
  if (!compareVoterId(voterId, voters)) {
    cerr << "Invalid voter ID." << endl;
    return 1;
  }

  // Show the candidates.
  showCandidates();

  // Let the voter vote for a candidate.
  vote(candidateNumber);

  return 0;
}

vector<string> split(const string& str, const char& delimiter) {
  vector<string> tokens;
  string::size_type start = 0;
  string::size_type end = str.find(delimiter);
  while (end != string::npos) {
    tokens.push_back(str.substr(start, end - start));
    start = end + 1;
    end = str.find(delimiter, start);
  }

  if (start != str.length()) {
    tokens.push_back(str.substr(start));
  }

  return tokens;
}
